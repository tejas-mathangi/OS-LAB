#include<stdio.h>

void merge(int arr[] , int l ,int m , int h){
    int n1=m-l+1;
    int n2=h-m;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++) L[i]=arr[l+i];
    for(int i=0;i<n2;i++) R[i]=arr[i+m+1];
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(L[i] < R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];

    }
    while(i<n1) arr[k++]=L[i++];
    while(j<n2) arr[k++]=R[j++];
}

void mergeSort(int arr[],int l,int h){
    if(l<h){
        int m = (l+h)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,h);
    merge(arr,l,m,h);
    }
}
int main(){
    int arr[] = {8, 3, 6, 2};
    mergeSort(arr, 0, 3);
    for (int i = 0; i < 4; i++)
    {
       printf("%d ",arr[i]); 
    }
    return 0;
}