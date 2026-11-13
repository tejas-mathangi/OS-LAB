#include <stdio.h>

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b=temp;
}
int partition(int arr[],int l , int h){
    int pi = arr[h];
    int i = l-1;
    for(int j=l ;j<h;j++){
        if(arr[j]<pi){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[h]);
    return i+1;
}

void quickSort(int arr[],int l ,int h){
    if(l<h){
        int p = partition(arr,l,h);
        quickSort(arr,l,p-1);
        quickSort(arr,p+1,h);
    }
}