#include <stdio.h>
#define MAX 100
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int array[], int low, int high) {
  int pivot = array[high];
  int i = (low - 1);
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) { 
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

void quickSort(int array[], int low, int high, int size) {
  int count=1;
  if (low < high) {
        int pi = partition(array, low, high);
        printf("%d:",count);
        for (int i = 0; i < size; ++i) {
            printf("%d  ", array[i]);
            count++;
        }
        printf("\n");
        quickSort(array, low, pi - 1, size);
        printf("%d:",count);
        for (int i = 0; i < size; ++i) {
            printf("%d  ", array[i]);
            count++;
        }
        printf("\n");
        quickSort(array, pi + 1, high, size);
    }
}
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}
int main() {
  int data[MAX];
  int n;
  printf("Enter the number of elements to enter in the array:");
  scanf("%d", &n);
  //int n = sizeof(data) / sizeof(data[0]);
  for(int i=0;i<n;i++)
  {
      scanf("%d", &data[i]);
  }
  printf("Unsorted Array\n");
  printArray(data, n);
  
  // perform quicksort on data
  quickSort(data, 0, n - 1, n);
  
  printf("Sorted array in ascending order: \n");
  printArray(data, n);
}