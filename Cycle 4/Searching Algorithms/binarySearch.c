#include <stdio.h>

int arr[50], n, search;

void display(int arr[]){
    printf("{");
    for (int i = 0; i < n; i++)
        printf("\t%d", arr[i]);
    printf("\t}\n");
}

void initArr(){
    printf("Enter The Number Of Elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Created Array: ");
    display(arr);
}

void bubbleSort(int arr[]){
    int i, j, swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
    }
}

void binarySearch(int arr[], int search){
    int l = 0, u = n - 1, mid, flag = 0;

    while (l <= u){
        mid = (l + u) / 2;
        if (arr[mid] == search){
            printf("Element Found At Position %d\n", (mid + 1));
            flag = 1;
            break;
        }
        else if (arr[mid] < search)
            l = mid + 1;
        else
            u = mid - 1;
    }
    if (flag == 0)
        printf("The Element Is Not Present In The Array\n");
}

int main(){
    initArr();
    
    bubbleSort(arr);
    printf("Sorted Array: ");
    display(arr);
    
    printf("Enter The Element To Search For: ");
    scanf("%d", &search);
    
    binarySearch(arr, search);
    return 0;
}
