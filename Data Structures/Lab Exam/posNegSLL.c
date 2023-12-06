#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* link;
};

struct node *hm, *hp, *hn;

struct node* createNode(){
    struct node *temp = (struct node*)malloc(sizeof(struct node*));
    temp -> link = NULL;
    return temp;
}

void insert(struct node** temp, int d){
    struct node *ptr = *temp;
    struct node* new = createNode();
    new -> data = d;

    if (ptr == NULL){
        *temp = new;
    }
    else{
        while (ptr -> link != NULL)
            ptr = ptr -> link;
        ptr -> link = new;
    }
}

void delete(struct node** temp){
    struct node *ptr = *temp;

    if (ptr == NULL){
        printf("\nList Empty!");
    }
    else{
        (*temp) = (*temp) -> link;
        free(ptr);
    }
}

void display(struct node* temp){
    struct node *head = temp;

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
    while (hm != NULL){
        if (hm -> data < 0){
            insert(&hp, hm -> data);
        }
        else{
            insert(&hn, hm -> data);
        }
        struct node *temp = hm;
        hm = hm -> link;
        free(temp);
    }
}

void main(){
    insert(&hm, 1);
    insert(&hm, -27);
    insert(&hm, 10);
    insert(&hm, -9);
    insert(&hm, 2);
    insert(&hm, 5);
    display(hm);
    shift();
    display(hp);
    display(hn);
    display(hm);
}