#include <stdio.h>
int binarysearch(int arr[],int low,int high,int mid,int x){
   int flag=0;
    for(int i=low;i<=high;i++) {
      mid=(low+high)/2;
      if(x==arr[mid]){
            printf("\nPresent");
            flag=1;
            break;
        }
        else
            if(x>arr[mid])
                low=mid+1;
            else
                high=mid-1;
    }
    if(flag==0)
      printf("\nAbsent");
      return 0;
}
int main(void){
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
    binarysearch(arr, 0, n,0, element);
   return 0;
}