#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node *top, *new, *ptr;

struct node* createNode(){
    int d;
    printf("\nEnter The Data: ");
    scanf("%d", &d);

    struct node *temp = (struct node*)malloc(sizeof(struct node*));
    temp -> data = d;
    temp -> link = NULL;
    return temp;
}

void push(){  
    new = createNode();

    if (top != NULL)
    	new -> link = top;    	
    top = new;
    printf("\nItem Inserted!");
}

void pop(){
	if (top == NULL)
		printf("\nStack Empty!");
	else{
		ptr = top;
		printf("\nPopped Item: %d", ptr -> data);
		top = ptr -> link;
		free(ptr);
	}
}

void peek(){
	if (top == NULL)
		printf("\nStack Empty!");
	else
		printf("\nStack Peek: %d", top -> data);
}

void display(){
	if (top == NULL)
        printf("\nStack Empty!");
    else{
        ptr = top;
        printf("\nStack Data: \n");

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
        printf("\n\t\t 1) Push");
        printf("\n\t\t 2) Pop");
        printf("\n\t\t 3) Peek");
        printf("\n\t\t 4) Display");
        printf("\n\t\t 5) Exit");
        printf("\n\t\t ================================\n");
  
        int o;
        printf("\nEnter Your Option: ");
        scanf("%d", &o);
  
        switch(o){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("\nClosing...\n");
                menuFlag = 0;
                break;
            default:
                printf("\nPlease Enter A Valid Option!\n");
        }
    }
}