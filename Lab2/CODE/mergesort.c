#include <stdio.h>
void merge(int arr[],int low,int mid,int high){
int n1=mid-low+1,n2=high-mid;
int left[n1],right[n2];
for(int i=0;i<n1;i++) left[i]=arr[low+i];
for(int j=0;j<n2;j++) right[j]=arr[mid+1+j];

int i=0,j=0,k=low;
while(i<n1 && j<n2){
if(left[i]<=right[j]) arr[k++]=left[i++];
else arr[k++]=right[j++];
}
while(i<n1) arr[k++]=left[i++];
while(j<n2) arr[k++]=right[j++];
}
void mergesort(int arr[],int low,int high){
if(low<high){
int mid=low+(high-low)/2;
mergesort(arr,low,mid);
mergesort(arr,mid+1,high);
merge(arr,low,mid,high);
}
}
void printArray(int arr[],int size){
for(int i=0;i<size;i++) printf("%d ",arr[i]);
printf("\n");
}
int main(){
int arr[]={12,11,13,5,6,7};
int n=sizeof(arr)/sizeof(arr[0]);
printf("Given array:\n");
printArray(arr,n);
mergesort(arr,0,n-1);
printf("Sorted array:\n");
printArray(arr,n);
return 0;
}
