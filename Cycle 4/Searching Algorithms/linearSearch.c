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

void linearSearch(int arr[], int search){
    int flag = 0; 
    for (int i = 0; i < n; i++) {
        if (arr[i] == search) {
            printf("Element Found At Position %d\n", (i + 1));
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        printf("The Element Is Not Present In The Array\n");
}

int main(){
    initArr();

    printf("Enter The Element To Search For: ");
    scanf("%d", &search);

    linearSearch(arr, search);
    return 0;
}