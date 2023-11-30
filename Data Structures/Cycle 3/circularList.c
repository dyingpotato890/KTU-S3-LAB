#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head;

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

    if (head == NULL){
    	head = new;
    	head -> next = new;
    	head -> prev = new;
    }
    else{
    	new -> prev = head -> prev;
    	new -> next = head;
    	head -> prev -> next = new;
    	head -> prev = new;
    	head = new;
    }
    printf("Element Inserted!\n");
}

void insertEnd(){   
    struct node* new = createNode();

	if (head == NULL){
    	new -> next = new;
    	new -> prev = new;
    	head = new;
    }
    else{
    	new -> prev = head -> prev;
    	new -> next = head;
    	head -> prev -> next = new;
    	head -> prev = new;
    }
    printf("Element Inserted!\n");
}

/* =============== DELETION ===============*/

void deleteFront(){
	if (head == NULL)
		printf("\nQueue Empty!");
	else{
		struct node* ptr = head;	
		printf("\nDeleted Element: %d", ptr -> data);
		
		if (ptr -> next == head){
			head = NULL;
			free(ptr);
		}
		else{
			head = ptr -> next;
		
			ptr -> next -> prev = ptr -> prev;
			ptr -> prev -> next = head;
			free(ptr);
		}
	}
}

void deleteEnd(){
	if (head == NULL)
		printf("\nQueue Empty!");
	else{
		struct node* ptr = head -> prev;
		printf("\nDeleted Element: %d", ptr -> data);
		
		if (ptr == head){
			head = NULL;
			free(ptr);
		}
		else{
			head -> prev = head -> prev -> prev;
			head -> prev -> next = head;	
			free(ptr);
		}
	}
}

/* =============== DISPLAY ===============*/

void display(){
	if (head == NULL)
        printf("\nQueue Empty!");
    else{
        struct node* ptr = head;
        printf("\nQueue Data: \n");
        
		printf("%d", ptr -> data);
		ptr = ptr -> next;
        while(ptr != head){
        	if (ptr != head)
            	printf(" --> ");
            printf("%d", ptr -> data);
            ptr = ptr -> next;
            
        }
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