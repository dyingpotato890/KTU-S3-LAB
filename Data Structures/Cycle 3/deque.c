#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *front, *rear;

struct node* createNode(){
    int d;
    printf("\nEnter The Data: ");
    scanf("%d", &d);

    struct node *temp = (struct node*)malloc(sizeof(struct node*));
    temp -> data = d;
    temp -> next = NULL;
    temp -> prev = NULL;
    return temp;
}

/* =============== INSERTION ===============*/

void insertFront(){  
    struct node* new = createNode();

    if (front == NULL)
    	front = rear = new;
    else{
    	front -> prev = new;
    	new -> next = front;
    	front = new;
    }
    printf("Element Inserted!\n");
}

void insertEnd(){   
    struct node* new = createNode();

	if (rear != NULL){
    	rear -> next = new;
    	new -> prev = rear;
    	rear = new;
    }
    else
    	front = rear = new;
    printf("Element Inserted!\n");
}

/* =============== DELETION ===============*/

void deleteFront(){
	if (front == NULL)
		printf("Queue Empty!\n");
	else{
		struct node* ptr = front;	
		printf("\nDeleted Element: %d", ptr -> data);
		front = ptr -> next;
		free(ptr);
	}
}

void deleteEnd(){
	if (front == NULL)
		printf("Queue Empty!\n");
	else{
		struct node* ptr = rear;
		
		if (rear -> prev != NULL){
			rear = rear -> prev;
			rear -> next = NULL;
		}
		else
			front = rear = NULL;
		printf("\nDeleted Element: %d", ptr -> data);
		free(ptr);
	}
}

/* =============== DISPLAY ===============*/

void display(){
	if (front == NULL)
        printf("Queue Empty!\n");
    else{
        struct node* ptr = front;
        printf("\nQueue Data: \n");

        while(ptr != NULL){
            printf("%d --> ", ptr -> data);
            ptr = ptr -> next;
        }
        printf("NULL\n");
    }
}

void main(){
    int menuFlag = 1, o;
    
    printf("\n\t\t ============= MENU =============");
    printf("\n\t\t 1) Insert At The Front");
    printf("\n\t\t 2) Insert At The End");
    printf("\n\t\t 3) Delete From The Front");
    printf("\n\t\t 4) Delete From The End");
    printf("\n\t\t 5) Display");
    printf("\n\t\t 6) Exit");
    printf("\n\t\t ================================\n");
	
    while (menuFlag == 1){
        printf("\nEnter Your Option: ");
        scanf("%d", &o);
  
        switch(o){
            case 1:
                insertFront();
                break;
            case 2:
                insertEnd();
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteEnd();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("\nClosing...\n");
                menuFlag = 0;
                break;
            default:
                printf("\nPlease Enter A Valid Option!\n");
        }
    }
}