#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    char c;
    struct node *next;
    struct node *prev;
};

struct node *head;
char str[50];

void addToDLL(char ci){
	struct node *new = (struct node*)malloc(sizeof(struct node*));
	new -> c = ci;
	new -> next = NULL;
	
	if (head == NULL){
    	new -> prev = NULL;
    	head = new;
	}
	else{
		struct node *ptr = head;
		while(ptr -> next != NULL)
			ptr = ptr -> next;
		ptr -> next = new;
		new -> prev = ptr;
	}
    
}

int isPalindrome(){
	struct node *left = head;
	struct node *right = head;
	
	while(right -> next != NULL)
		right = right -> next;
			
	while(left != right){
		if (left -> c != right -> c)
			return 0;
		left = left -> next;
		right = right -> prev;
	}
		return 1;
}

void main(){
	int result;
    printf("\nEnter The String: ");
    scanf("%s", &str);
    
    for(int i = 0; i < strlen(str); i++)
    	addToDLL(str[i]);
    
    result = isPalindrome();
    if (result == 1)
    	printf("\nGiven String Is A Palindrome!");
    else
    	printf("\nGiven String Is Not A Palindrome!");
}