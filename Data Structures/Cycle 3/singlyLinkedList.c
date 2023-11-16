#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};
struct node *head = NULL;

struct node* createNode(){
    int d;
    printf("\nEnter The Data: ");
    scanf("%d", &d);

    struct node *temp = (struct node*)malloc(sizeof(struct node*));
    temp -> data = d;
    temp -> link = NULL;
    return temp;
}

/* =============== INSERTION ===============*/

void insertFront(){  
    struct node* new = createNode();
    new -> link = head;
    head = new;
}

void insertAfter(){
    if (head != NULL){
    	struct node* ptr = head;

        int item;
        printf("\nEnter The Element After Which You Want To Insert: ");
        scanf("%d", &item);

        while (ptr != NULL && ptr -> data != item){
        	ptr = ptr -> link;
        }
        if (ptr == NULL)
            printf("\nEntered Element Does Not Exist!");
        else{
            struct node* new = createNode();
            new -> link = ptr -> link;
            ptr -> link = new;
        }
    }
    else
    	insertFront();
}

void insertBefore(){
    if (head != NULL){
    	struct node* ptr = head;
        struct node* prev = ptr;

        int item;
        printf("\nEnter The Element Before Which You Want To Insert: ");
        scanf("%d", &item);

        if (head -> data == item)
            insertFront();
        else{
            while (ptr != NULL && ptr -> data != item){
                prev = ptr;
        	    ptr = ptr -> link;
            }
            if (ptr == NULL)
                printf("\nEntered Element Does Not Exist!");
            else{
                struct node* new = createNode();
    	        prev -> link = new;
                new -> link = ptr;
            }
        } 	
    }
    else
    	insertFront();
}

void insertAny(){
    struct node* ptr = head;
    int searchCount = 1, pos, d;
    
    if (head != NULL){
    	printf("\nEnter The Node After Which You Want To Insert: ");
    	scanf("%d", &pos);
    
    	while (ptr != NULL && searchCount != pos){
    		ptr = ptr -> link;
    		searchCount++;
    	}
    
    	if (ptr == NULL)
    		printf("\nNode Out Of Bound!");

    	else{
    		struct node* new = createNode();
    		new -> link = ptr -> link;
    		ptr -> link = new;
    	}
    }
    else
    	insertFront();
}

/* =============== DELETION ===============*/

void deleteFront(){
	if (head == NULL)
		printf("\nList Empty!");
	else{
		struct node* ptr = head;	
		head = ptr -> link;
		free(ptr);
	}
}

void deleteEnd(){
	if (head == NULL)
		printf("\nList Empty!");
	else{
		struct node* ptr = head;
		struct node* prev = ptr;
		
		while (ptr -> link != NULL){
			prev = ptr;
			ptr = ptr -> link;
		}
		prev -> link = NULL;
		free(ptr);
	}
}

void deleteAny(){
	struct node* ptr = head;
	struct node* prev = head;
    int flag = 1, searchCount = 1, pos, d;
    
    printf("\nEnter The Node To Delete: ");
    scanf("%d", &pos);
    
    while (ptr != NULL && searchCount != pos){
    	prev = ptr;
    	ptr = ptr -> link;
    	searchCount++;
    }
    
    if (ptr == NULL)
    	printf("\nNode Out Of Bound!");
    else if (pos == 1)
    	deleteFront();
    else if (ptr -> link == NULL)
    	deleteEnd();
    else{
    	prev -> link = ptr -> link;
    	free(ptr);
    }
}

void deleteValue(int val){
    if (head != NULL){
        struct node* ptr = head;
	    struct node* prev = ptr;
        struct node* temp;
	    int delFlag = 0;
	
	    if (head -> data == val)
		    deleteFront();
        else if (head == NULL)
            printf("\nList Empty!");
	    else{
		    while(ptr!=NULL){
		        if(ptr -> data != val){
			        prev = ptr;
			        ptr = ptr -> link;
		        }
		        else{
				    temp = ptr;
				    prev -> link = ptr-> link;
				    ptr = ptr -> link;
				    free(temp);
				    delFlag = 1;		
		        }
	        }

		    if (delFlag == 0)
			    printf("\nData Item Not Found!");
	    }
    }
}

void deleteSmallest(){
    if (head != NULL){
        struct node* ptr = head;
	    int small = ptr -> data;

	    while (ptr != NULL){
		    if (ptr -> data < small)
			    small = ptr -> data;
		    ptr = ptr -> link;
	    }
        deleteValue(small);
    }
}

/* =============== SEARCH AND DISPLAY ===============*/

void search(){
    struct node* ptr = head;
    int count = 1, item, d;
    
    printf("\nEnter The Item To Search: ");
    scanf("%d", &item);
    
    while (ptr != NULL && ptr -> data != item){
    	ptr = ptr -> link;
    	count++;
    }
    
    if (ptr == NULL)
    	printf("\nThe Element Does Not Exist In The Linked List!");
    else
    	printf("\nThe Element Exists At Node %d!", count);
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

/* =============== MENUS ===============*/

void insertMenu(){
    int menuInsert = 1;
	
    while (menuInsert == 1){
        printf("\n\t\t ============= INSERT MENU =============");
        printf("\n\t\t 1) After A Value");
        printf("\n\t\t 2) Before A Value");
        printf("\n\t\t 3) At Any Position");
        printf("\n\t\t 4) Exit");
        printf("\n\t\t =====================================\n");
  
        int o;
        printf("\nEnter Your Option: ");
        scanf("%d", &o);
  
        switch(o){
            case 1:
                insertAfter();
                display();
                break;
            case 2:
                insertBefore();
                display();
                break;
            case 3:
                insertAny();
                display();
                break;
            case 4:
                menuInsert = 0;
                break;
            default:
                printf("\nPlease Enter A Valid Option!\n");
        }
    }
}

void deleteMenu(){
    int menuDelete = 1, delVal;
	
    while (menuDelete == 1){
        printf("\n\t\t ============= DELETE MENU =============");
        printf("\n\t\t 1) From Given Position");
        printf("\n\t\t 2) Smallest Value");
        printf("\n\t\t 3) By Value");
        printf("\n\t\t 4) Exit");
        printf("\n\t\t =====================================\n");
  
        int o;
        printf("\nEnter Your Option: ");
        scanf("%d", &o);
  
        switch(o){
            case 1:
                deleteAny();
                display();
                break;
            case 2:
                deleteSmallest();
                display();
                break;
            case 3:
            	printf("\nEnter The Data To Delete: ");
        	    scanf("%d", &delVal);
                deleteValue(delVal);
                display();
                break;
            case 4:
                menuDelete = 0;
                break;
            default:
                printf("\nPlease Enter A Valid Option!\n");
        }
    }
}

void main(){
    int menuFlag = 1;
	
    while (menuFlag == 1){
        printf("\n\t\t ============= MENU =============");
        printf("\n\t\t 1) Insert");
        printf("\n\t\t 2) Delete");
        printf("\n\t\t 3) Search");
        printf("\n\t\t 4) Display");
        printf("\n\t\t 5) Exit");
        printf("\n\t\t ================================\n");
  
        int o;
        printf("\nEnter Your Option: ");
        scanf("%d", &o);
  
        switch(o){
            case 1:
                insertMenu();
                break;
            case 2:
                deleteMenu();
                break;
            case 3:
                search();
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
