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

void merge(int arr[100], int low, int mid, int high) {
    int i, j, k, a[100];
    i = low, k = low, j = mid + 1;
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            a[k] = arr[i];
            i++;
        } else if (arr[i] > arr[j]) {
            a[k] = arr[j];
            j++;
        }
        k++;
    }
    while (i <= mid) {
        a[k] = arr[i];
        i++, k++;
    }
    while (j <= high) {
        a[k] = arr[j];
        j++, k++;
    }
    for (int i = low; i <= high; i++)
        arr[i] = a[i];
}

void mergeSort(int arr[100], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

void main(){
    initArr();
    mergeSort(arr, 0, n - 1);
    display(arr, "Merge Sort");
}