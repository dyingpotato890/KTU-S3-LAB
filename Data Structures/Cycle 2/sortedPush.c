#include <stdio.h>
#define n 100

int stack[n], topS = -1;

void display(){
	printf("\nStack: \n");
	for(int i = topS; i >= 0; i--)
		printf("%d\n", stack[i]);
}

void push(int elem){
	if (topS == n - 1)
		printf("Stack Full!\n");
	else if(topS == -1)
		stack[++topS] = elem;
	else{
		int auxStack[n], temptop=-1;

		while(elem > stack[topS] && topS!=-1)
			auxStack[++temptop] = stack[topS--];
		stack[++topS] = elem;

		while(temptop>-1)
			stack[++topS] = auxStack[temptop--];
	}
}

int pop(){
	if (topS != -1)
		return(stack[topS--]);
	else
		printf("\nStack Empty!");
}

void peak(){
	if (topS == -1)
		printf("\nStack Empty!");
	else
		printf("Peak Value: %d\n", stack[topS]);
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
		
		int o, e;
		printf("\nEnter Your Option: ");
		scanf("%d", &o);
		
		switch(o){
			case 1:
				printf("Enter The Element To Be Pushed: ");
				scanf("%d", &e);
				push(e);
				break;
			case 2:
				pop(stack, topS);
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
