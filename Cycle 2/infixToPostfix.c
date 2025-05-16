#include <stdio.h>
#include <stdbool.h>

char infixExp[50], stack[50], top = -1;

void push(char e){
	stack[++top] = e;
}

char pop(){
	return (stack[top--]);
}

bool isOperator(char op){
	if (op == '+' || op == '-' || op == '*' || op == '/' || op == '^' || op == '(')
		return true;
	else
		return false;
}

int precedence(char op){
	if (op == '+' || op == '-')
		return 1;
	else if(op == '*' || op == '/')
		return 2;
	else if(op == '^')
		return 3;
	else if (op == '(')
		return 0;
}

void toPostfix(){
	int i = 0;
	while (infixExp[i] != '\0'){				
		if (infixExp[i] == ')'){
			while (stack[top] != '('){
				char Item = pop();
				printf("%c", Item);
			}
			pop();
		}
		
		else if (isOperator(infixExp[i])){
			if (infixExp[i] == '(')
				push(infixExp[i]);
			else if (precedence(infixExp[i]) > precedence(stack[top]))
					push(infixExp[i]);
			else{
				while (precedence(stack[top]) >= precedence(infixExp[i]))
					printf("%c", stack[top--]);
				push(infixExp[i]);
			}	
		}

		else{printf("%c", infixExp[i]);}	
		i++;
	}
	while(top != -1)
		printf("%c", pop());	
}

void main(){
	printf("\nEnter The Infix Expression: ");
	scanf("%[^\n]", &infixExp);
	printf("\nPostfix Expression: ");
	toPostfix();
	printf("\n");
}