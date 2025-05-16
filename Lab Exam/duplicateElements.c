#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* link;
};
struct node *head = NULL;

void create(){
    int elem, n;
    printf("Enter The Number Of Nodes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        printf("Enter Element %d: ", i);
        scanf("%d", &elem);
        struct node *new = (struct node*)malloc(sizeof(struct node));
        new -> data = elem;
        new -> link = head;
        head = new;
    }
}

void display(){
	if (head == NULL)
        printf("\nList Empty!");
    else{
        struct node* ptr = head;
        printf("\nLinked List Data: \n");

        while(ptr != NULL){
            printf("%d --> ", ptr -> data);
            ptr = ptr -> link;
        }
        printf("NULL\n");
    }
}

void delDup(){
    if (head == NULL)
        printf("\nList Empty!");
    else{
        struct node *ptr1 = head;
        struct node *ptr2 = NULL;
        struct node *prev = NULL;

        while (ptr1 != NULL){
            ptr2 = ptr1 -> link;
            prev = ptr1;
            while (ptr2 != NULL){
                if ((ptr2 -> data) == (ptr1 -> data)){
                    struct node *temp = ptr2;
                    prev -> link = ptr2 -> link;
                    ptr2 = ptr2 -> link;
                    free(temp);
                }
                else{
                    prev = ptr2;
                    ptr2 = ptr2 -> link;
                }
            }
            ptr1 = ptr1 -> link;
        }
    }
}

void main(){
    create();
    display();
    delDup();
    display();
}