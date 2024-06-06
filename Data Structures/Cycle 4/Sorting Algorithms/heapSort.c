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

void heapify(int arr[100], int n, int i) {
    int l = (2 * i) + 1;
    int r = (2 * i) + 2;
    int largest = i;
    while (l < n && arr[l] > arr[largest])
        largest = l;
    while (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        int temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[100], int n) {
    for (int i = n / 2; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

void main(){
    initArr();
    heapSort(arr, n);
    display(arr, "Heap Sort");
}