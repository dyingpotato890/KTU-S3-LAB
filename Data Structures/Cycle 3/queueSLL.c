#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node *front, *rear, *new, *ptr;

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

    printf("\nItem Inserted!");
}

void dequeue(){
	if (front == NULL)
		printf("\nQueue Empty!");
	else{
			if (front -> link == NULL){
				printf("Dequeued Item: %d", front -> data);
				front = rear = NULL;
				free(front);
				free(rear);
			}
			else{
				ptr = front;
				printf("Dequeued Item: %d", ptr -> data);
				front = ptr -> link;
				free(ptr);
			}
	}
}

void display(){
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

void main(){
    int menuFlag = 1;
	
    while (menuFlag == 1){
        printf("\n\t\t ============= MENU =============");
        printf("\n\t\t 1) Enqueue");
        printf("\n\t\t 2) Dequeue");
        printf("\n\t\t 3) Display");
        printf("\n\t\t 4) Exit");
        printf("\n\t\t ================================\n");
  
        int o;
        printf("\nEnter Your Option: ");
        scanf("%d", &o);
  
        switch(o){
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
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