#include <stdio.h>

int arr[50], originalValues[50], n , search;

void display(int ar[], char* type) {
    printf("%s: {", type);
    for (int i = 0; i < n; i++)
        printf("\t%d", ar[i]);
    printf("\t}\n");
}

void resetArray() {
    for (int i = 0; i < n; i++)
        arr[i] = originalValues[i];
}

void initArr(){
    int temp;
    printf("Enter The Number Of Elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter The Element %d: ", i + 1);
        scanf("%d", &originalValues[i]);
        arr[i] = originalValues[i];
    }
    display(arr, "Original Array");
}

void bubbleSort(int arr[5]){
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
    display(arr, "Bubble Sort");
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

void main() {
    int menuFlag = 1, o, d, p;
    initArr();

	printf("\n\t\t ============= MENU =============");
    printf("\n\t\t 1) Bubble Sort");
    printf("\n\t\t 2) Insertion Sort");
    printf("\n\t\t 3) Selection Sort");
    printf("\n\t\t 4) Quick Sort");
    printf("\n\t\t 5) Merge Sort");
    printf("\n\t\t 6) Heap Sort");
    printf("\n\t\t 7) Exit");
    printf("\n\t\t ================================\n");

    while (menuFlag != 0) {
		printf("\nEnter Your Option: ");
        scanf("%d", & o);
        switch (o) {
            case 1: bubbleSort(arr); resetArray(); display(arr , "Original Array"); break;
            case 2: insertionSort(arr); resetArray(); display(arr , "Original Array"); break;
            case 3: selectionSort(arr); resetArray(); display(arr , "Original Array"); break;
            case 4: quickSort(arr, 0, n - 1); display(arr , "Quick Sort"); resetArray(); display(arr , "Original Array"); break;
            case 5: mergeSort(arr, 0, n - 1); display(arr, "Merge Sort"); resetArray(); display(arr , "Original Array"); break;
            case 6: heapSort(arr, n); display(arr, "Heap Sort"); resetArray(); display(arr , "Original Array"); break;
            case 7: menuFlag = 0; printf("Closing...\n"); break;
            default: printf("Invalid choice!\n");
        }
    }
}