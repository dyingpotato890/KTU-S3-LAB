#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node *top, *front, *rear, *new, *ptr;

struct node* createNode(){
    int d;
    printf("\nEnter The Data: ");
    scanf("%d", &d);

    struct node *temp = (struct node*)malloc(sizeof(struct node*));
    temp -> data = d;
    temp -> link = NULL;
    return temp;
}

void enqueue(){  
    new = createNode();

    if (front != NULL){
    	rear -> link = new;    	
    	rear = new;
    }
    else
    	front = rear = new;

    printf("Item Inserted!\n");
}

void push(int item){  
    new = (struct node*)malloc(sizeof(struct node*));
    new -> link = NULL;
    new -> data = item;

    if (top != NULL)
    	new -> link = top;    	
    top = new;
}

void dequeue(){
	if (front -> link == NULL){
		push(front -> data);
		front = rear = NULL;
	}
	else{
		ptr = front;
		push(ptr -> data);
		front = ptr -> link;
		free(ptr);
	}
}

void displayStack(){
	if (top == NULL)
        printf("\nStack Empty!");
    else{
        ptr = top;
        printf("\nReversed Value: \n");

        while(ptr != NULL){
            printf("%d\t", ptr -> data);
            ptr = ptr -> link;
        }
    }
}

void displayQueue(){
	if (front == NULL)
        printf("\nQueue Empty!");
    else{
        ptr = front;
        printf("\nQueue Data: \n");

        while(ptr != NULL){
            printf("%d\t", ptr -> data);
            ptr = ptr -> link;
        }
    }
}

void deRev(){
	if (front == NULL)
		printf("\nNothing To Reverse!");
	else{
		displayQueue();
		while (front != NULL)
			dequeue();
		displayStack();
	}
}

void main(){
    int menuFlag = 1, o;
    
    printf("\n\t\t ============= MENU =============");
    printf("\n\t\t 1) Enqueue");
    printf("\n\t\t 2) Dequeue & Reverse");
    printf("\n\t\t 3) Display Queue");
    printf("\n\t\t 4) Exit");
    printf("\n\t\t ================================\n");
	
    while (menuFlag == 1){
        printf("\nEnter Your Option: ");
        scanf("%d", &o);
  
        switch(o){
            case 1:
                enqueue();
                break;
            case 2:
                deRev();
                break;
            case 3:
                displayQueue();
                break;
            case 4:
                printf("\nClosing...\n");
                menuFlag = 0;
                break;
            default:
                printf("\nPlease Enter A Valid Option!\n");
        }
    }
}