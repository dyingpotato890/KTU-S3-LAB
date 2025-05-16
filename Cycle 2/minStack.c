#include <stdio.h>
#define n 100

int stack[n], auxStack[n], top1 = -1, top2 = -1;

void display(){
	printf("\nStack: \n");
	for(int i = top1; i >= 0; i--)
		printf("%d\n", stack[i]);	
}

void push(){
	if (top1 == n)
		printf("\nEnd Of Stack!");
	else{
		int e;
		printf("\nEnter The Element To Push: ");
		scanf("%d",&e);
		stack[++top1] = e;
		
		if (top2 != -1){
			if (auxStack[top2] > stack[top1])
				auxStack[++top2] = stack[top1];
		}
		else{
			auxStack[++top2] = stack[top1];
		}
	}
}

void peak(int top, int s[n]){
	if (top == -1)
		printf("\nStack Empty!");
	else
		printf("Peak Value: %d\n", s[top]);
}

void pop(){
	if (top1 != -1){
		int popElement = stack[top1--];
		printf("\nPopped Element: %d", popElement);
		if (auxStack[top2] == popElement)
			top2--;
		if (top1 != -1)
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
		printf("\n\t\t 4) Minimum Element");
		printf("\n\t\t 5) Display");
		printf("\n\t\t 6) Exit");
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
				peak(top1, stack);
				break;
			case 4:
				peak(top2, auxStack);
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
				break;
		}
	}
}
