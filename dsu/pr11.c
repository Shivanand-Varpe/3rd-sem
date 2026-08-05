#include<stdio.h>
#include<string.h>
void main(){
int n,i,j;
char temp[50];
printf("Enter number of strings :");
scanf("%d",&n);
printf("Enter strings :\n");
char arr[n][50];
for(i=0;i<n;i++){
    scanf("%s",arr[i]);}
for(i=1;i<n;i++){
    strcpy(temp,arr[i]);
    j=i-1;
    while(j>=0 && strcmp(arr[j],temp)>0){
        strcpy(arr[j+1],arr[j]);
        j--;}
    strcpy(arr[j+1],temp);}
printf("Sorted strings are :\n");
for(i=0;i<n;i++){
    printf("%s\n",arr[i]);}
}
