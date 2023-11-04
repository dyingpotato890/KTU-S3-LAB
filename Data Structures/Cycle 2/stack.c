#include <stdio.h>
#define n 100

int stack[n], top = -1;

void display(){
	printf("\nStack: \n");
	for(int i = top; i >= 0; i--)
		printf("%d\n", stack[i]);	
}

void push(){
	if (top == n)
		printf("\nEnd Of Stack!");
	else{
		int e;
		printf("\nEnter The Element To Push: ");
		scanf("%d",&e);
		stack[++top] = e;
	}
}

void peak(){
	if (top == -1)
		printf("\nStack Empty!");
	else
		printf("Peak Value: %d\n",stack[top]);
}

void pop(){
	if (top != -1){
		int popElement = stack[top--];
		printf("\nPopped Element: %d", popElement);
		if (top != -1)
			display();
	}
	else
		printf("\nStack Empty!");
}

void main(){
	int menuFlag = 1;
	
	while (menuFlag == 1){
		printf("\n\t\t ============= MENU =============");
		printf("\n\t\t 1) Push");
		printf("\n\t\t 2) Pop");
		printf("\n\t\t 3) Peak");
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
				peak();
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
				break;
		}
	}
}
