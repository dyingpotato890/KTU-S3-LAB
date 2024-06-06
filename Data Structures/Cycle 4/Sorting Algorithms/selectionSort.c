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

void selectionSort(int arr[5]){
    int pos, min;

    for(int i = 0; i < n-1; i++){
        min = arr[i];
        pos = i;
        for(int j = i+1; j < n; j++){
            if (arr[j] < min){
                min = arr[j];
                pos = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[pos];
        arr[pos] = temp;
    }
    display(arr, "Selection Sort");
}

void main(){
    initArr();
    selectionSort(arr);
}