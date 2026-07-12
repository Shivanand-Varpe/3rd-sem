#include<stdio.h>
int main(){
int n,i,found=0,key;
printf("Enter array size :");
scanf("%d",&n);
int arr[n];
printf("Array : ");
for(i=0;i<n;i++){
    arr[i]=(i*(i-(i/2)));}
for(i=0;i<n;i++){
    printf("%d ",arr[i]);}
printf("\nEnter Element to Search :");
scanf("%d",&key);
for(i=0;i<n;i++){
    if(arr[i]==key){
        printf("Found at location: %d",i+1);
        found=1; break;}}
if(found==0){
    printf("Element Not Found!");}
return 0;
}