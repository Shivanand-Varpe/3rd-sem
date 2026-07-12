#include<stdio.h>
#include<string.h>
void main(){
int n,i,found=0;
char key[50];
printf("Enter number of strings :");
scanf("%d",&n);
printf("Enter strings :\n");
char arr[n][50];
for(i=0;i<n;i++){
    scanf("%s",arr[i]);}
printf("Strings are :");
for(i=0;i<n;i++){
    printf("%s,",arr[i]);}
printf("\nEnter string to Search :");
scanf("%s",key);
for(i=0;i<n;i++){
    if(strcmp(arr[i],key)==0){
        printf("Found at location: %d",i+1);
        found=1; break;}}
if(found==0){
    printf("String Not Found!");}}