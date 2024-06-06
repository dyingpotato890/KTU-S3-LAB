#include <stdio.h>

int arr[50], n , search;

void display(int ar[], char* type) {
    printf("%s: {", type);
    for (int i = 0; i < n; i++)
        printf("\t%d", ar[i]);
    printf("\t}\n");
}

void initArr(){
    int temp;
    printf("Enter The Number Of Elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter The Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    display(arr, "Original Array");
}

int partition(int arr[100], int low, int high) {
    int pivot = arr[low];
    int i = low, j = high;
    while (i < j) {
        while (pivot >= arr[i])
            i++;
        while (pivot < arr[j])
            j--;
        if (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    arr[low] = arr[j];
    arr[j] = pivot;
    return j;
}

void quickSort(int arr[100], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

void main(){
    initArr();
    quickSort(arr, 0, n - 1);
    display(arr , "Quick Sort");
}