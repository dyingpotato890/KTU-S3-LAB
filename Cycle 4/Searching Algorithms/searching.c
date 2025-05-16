#include <stdio.h>

int arr[50], n, search;

void display(int arr[]){
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
    printf("Created Array: {");
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
    display(arr);
}

void linearSearch(int arr[], int search){
    int flag = 0; 
    for (int i = 0; i < n; i++) {
        if (arr[i] == search) {
            printf("Element Found At Postion %d\n", (i + 1));
            flag = 1;
        }
    }
    if (flag == 0)
        printf("The Element Is Not Present In The Array\n");
}

void binarySearch(int arr[], int search){
	int i, l, u, mid, flag = 0;
	l = 0;
	u = n - 1;

	while (l <= u){
		mid = (l + u) / 2;
		if (arr[mid] == search){
			printf("Element Found At Postion %d\n",(mid + 1));
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

void main() {
    int menuFlag = 1, o;

    initArr();
	printf("\n\t\t ============= MENU =============");
    printf("\n\t\t 1) Linear Search");
    printf("\n\t\t 2) Binary Search");
    printf("\n\t\t 3) Exit");
    printf("\n\t\t ================================\n");

    while (menuFlag != 0) {
		printf("\nEnter Your Option: ");
        scanf("%d", & o);
        switch (o) {
            case 1:
                printf("Enter The Element To Search For: ");
	            scanf("%d", &search);
                linearSearch(arr, search);
                break;
            case 2:
                printf("Sorted Array: {");
                bubbleSort(arr);
                printf("Enter The Element To Search For: ");
	            scanf("%d", &search);
                binarySearch(arr, search);
                break;
            case 3: menuFlag = 0; printf("Closing...\n"); break;
            default: printf("Invalid choice!\n");
        }
    }
}