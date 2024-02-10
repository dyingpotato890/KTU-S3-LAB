#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* link;
};
struct node *m, *p, *n;

struct node* createNode(int val){
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new -> data = val;
    new -> link = NULL;
    return new;
}

void insert(struct node** temp, int d){
    struct node *ptr = *temp;
    struct node* new = createNode(d);

    if (ptr == NULL)
        *temp = new;
    else{
        while (ptr -> link != NULL)
            ptr = ptr -> link;
        ptr -> link = new;
    }
}

void display(struct node *head){
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

void shift(){
    struct node *ptr = m;

    while (ptr != NULL){
        if (ptr -> data < 0)
            insert(&n, ptr -> data);
        else
            insert(&p, ptr -> data);
        ptr = ptr -> link;
    }
}

void main(){
    int elem;
    for(int i = 0; i < 10; i++){
        printf("Enter Element %d: ", i+1);
        scanf("%d", &elem);
        insert(&m, elem);
    }
    shift();
    display(n);
    display(p);
}