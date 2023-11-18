#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node *head;

struct node* createNode(){
    int d;
    printf("\nEnter The Data To Insert: ");
    scanf("%d", &d);

    struct node *temp = (struct node*)malloc(sizeof(struct node*));
    temp -> data = d;
    temp -> link = NULL;
    return temp;
}

void sortedInsert(){
	int searchFlag = 0;
	if (head == NULL){
		struct node* new = createNode();
    	new -> link = head;
    	head = new;
    }
	else{
		struct node* new = createNode();
		
		struct node* ptr = head;
		struct node* prev = head;
		
		while (ptr != NULL){
			if (ptr -> data > new -> data){
				searchFlag = 1;
				break;
			}
			prev = ptr;
			ptr = ptr -> link;
		}
		if (searchFlag == 1){
            if (ptr == head){
                new -> link = ptr;
                head = new;
            }
			else if (ptr != NULL){
                prev -> link = new;
				new -> link = ptr;
			}
			else{
				prev -> link = new;
			}
		}
        else
            prev -> link = new;	
	}
}

void reverse(){
    struct node* prev = NULL;
    struct node* next = head;
    struct node* current = head;
    if (head == NULL)
        printf("List Does Not Exist!");
    else{
        while(next != NULL){
            next = current -> link;
            current -> link = prev;
            prev = current;
            current = next;
        }
        head = prev;
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

void main(){
    int menuFlag = 1;
	
    while (menuFlag == 1){
        printf("\n\t\t ============= MENU =============");
        printf("\n\t\t 1) Insert Elements");
        printf("\n\t\t 2) Reverse");
        printf("\n\t\t 3) Display");
        printf("\n\t\t 4) Exit");
        printf("\n\t\t ================================\n");
  
        int o;
        printf("\nEnter Your Option: ");
        scanf("%d", &o);
  
        switch(o){
            case 1:
                sortedInsert();
                display();
                break;
            case 2:
                reverse();
                display();
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