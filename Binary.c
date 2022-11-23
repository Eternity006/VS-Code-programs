#include<stdio.h>
int binarysearch(int arr[],int low,int high,int key){
    while (low <= high) {
        int mid=low+(high-low)/2;
        if(arr[mid] < key)
            low = mid + 1;
        else if (arr[mid] == key) {
            printf("Present");
            break;
    }
        else
            high = mid - 1;
    }
    return -1;
}    
int main(){
    int n;
    printf("Input number of array elements: ");
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++){
        printf("Number %d element: ", i+1);
        scanf("%d", &arr[n]);
    }
    int element;
    printf("enter the element you want to search: ");
    scanf("%d", &element);
    int search;
    search=binarysearch(arr, 0, n-1 ,element);
    if(search==-1)
        printf("absent");
    else
        printf("present");
    return 0;
}