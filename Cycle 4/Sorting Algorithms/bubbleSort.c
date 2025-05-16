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

void insertionSort(int arr[5]){
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    display(arr, "Insertion Sort");
}

void main(){
    initArr();
    insertionSort(arr);
}