#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sqlite3.h"

// Helper function to clear input buffer
void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Helper function to remove trailing newline from fgets
void remove_newline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

// Function to initialize database and create table if it doesn't exist
int init_database(sqlite3 *db) {
    char *sql = "CREATE TABLE IF NOT EXISTS Students ("
                "roll_no INTEGER PRIMARY KEY, "
                "name TEXT NOT NULL, "
                "standard TEXT, "
                "div TEXT, "
                "address TEXT, "
                "mobile_no TEXT, "
                "email TEXT);";

    char *err_msg = 0;
    int rc = sqlite3_exec(db, sql, 0, 0, &err_msg);

    if (rc != SQLITE_OK) {
        printf("❌ Database Setup Error: %s\n", err_msg);
        sqlite3_free(err_msg);
        return 0;
    }
    return 1;
}

// Function to accept student details and save to SQLite
void add_student(sqlite3 *db) {
    int roll_no;
    char name[100], standard[20], div[10], address[200], mobile_no[20], email[100];

    printf("\n=== Add New Student Record ===\n");
    
    printf("Enter Roll No: ");
    if (scanf("%d", &roll_no) != 1) {
        printf("❌ Invalid input for Roll No.\n");
        clear_buffer();
        return;
    }
    clear_buffer();

    printf("Enter Full Name: ");
    fgets(name, sizeof(name), stdin);
    remove_newline(name);

    printf("Enter Standard (Class): ");
    fgets(standard, sizeof(standard), stdin);
    remove_newline(standard);

    printf("Enter Division: ");
    fgets(div, sizeof(div), stdin);
    remove_newline(div);

    printf("Enter Address: ");
    fgets(address, sizeof(address), stdin);
    remove_newline(address);

    printf("Enter Mobile No: ");
    fgets(mobile_no, sizeof(mobile_no), stdin);
    remove_newline(mobile_no);

    printf("Enter Email Address: ");
    fgets(email, sizeof(email), stdin);
    remove_newline(email);

    // SQL query using prepared statement placeholders (?) to safely bind strings
    char *sql = "INSERT INTO Students (roll_no, name, standard, div, address, mobile_no, email) "
                "VALUES (?, ?, ?, ?, ?, ?, ?);";

    sqlite3_stmt *stmt;
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, 0) == SQLITE_OK) {
        sqlite3_bind_int(stmt, 1, roll_no);
        sqlite3_bind_text(stmt, 2, name, -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 3, standard, -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 4, div, -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 5, address, -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 6, mobile_no, -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 7, email, -1, SQLITE_STATIC);

        if (sqlite3_step(stmt) == SQLITE_DONE) {
            printf("\n✅ Student record stored successfully!\n");
        } else {
            printf("\n❌ Error storing record: %s\n", sqlite3_errmsg(db));
        }
        sqlite3_finalize(stmt);
    } else {
        printf("\n❌ Failed to prepare statement: %s\n", sqlite3_errmsg(db));
    }
}

// Function to fetch and display all student data
void view_students(sqlite3 *db) {
    char *sql = "SELECT roll_no, name, standard, div, address, mobile_no, email FROM Students;";
    sqlite3_stmt *stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, 0) == SQLITE_OK) {
        printf("\n=================================== ALL STUDENT RECORDS ===================================\n");
        int count = 0;

        while (sqlite3_step(stmt) == SQLITE_ROW) {
            count++;
            int roll = sqlite3_column_int(stmt, 0);
            const unsigned char *name = sqlite3_column_text(stmt, 1);
            const unsigned char *std = sqlite3_column_text(stmt, 2);
            const unsigned char *div = sqlite3_column_text(stmt, 3);
            const unsigned char *addr = sqlite3_column_text(stmt, 4);
            const unsigned char *mob = sqlite3_column_text(stmt, 5);
            const unsigned char *email = sqlite3_column_text(stmt, 6);

            printf("Record #%d:\n", count);
            printf("  Roll No  : %d\n", roll);
            printf("  Name     : %s\n", name);
            printf("  Class/Div: %s (Div: %s)\n", std, div);
            printf("  Address  : %s\n", addr);
            printf("  Mobile   : %s\n", mob);
            printf("  Email    : %s\n", email);
            printf("-------------------------------------------------------------------------------------------\n");
        }

        if (count == 0) {
            printf("No student records found in the database.\n");
        }
        sqlite3_finalize(stmt);
    } else {
        printf("\n❌ Failed to fetch records: %s\n", sqlite3_errmsg(db));
    }
}

int main() {
    sqlite3 *db;
    
    // Open or create database file
    int rc = sqlite3_open("student_db.db", &db);
    if (rc != SQLITE_OK) {
        printf("Cannot open database: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    if (!init_database(db)) {
        sqlite3_close(db);
        return 1;
    }

    int choice;
    do {
        printf("\n=============================\n");
        printf(" STUDENT MANAGEMENT SYSTEM\n");
        printf("=============================\n");
        printf("1. Add Student Record\n");
        printf("2. View All Student Records\n");
        printf("3. Exit\n");
        printf("Enter your choice (1-3): ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid choice. Exiting.\n");
            break;
        }

        switch (choice) {
            case 1:
                add_student(db);
                break;
            case 2:
                view_students(db);
                break;
            case 3:
                printf("\nExiting program. Goodbye!\n");
                break;
            default:
                printf("\nInvalid option! Please select 1, 2, or 3.\n");
        }
    } while (choice != 3);

    // Close database handle
    sqlite3_close(db);
    return 0;
}