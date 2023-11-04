#include <stdio.h>
#include <stdbool.h>
#include <math.h>

char postfix[50];
int stack[50], top = -1;

void push(int e){
	stack[++top] = e;
}

int pop(){
	return stack[top--];
}

bool isOperator(char op){
	if (op == '+' || op == '-' || op == '*' || op == '/' || op == '^' || op == '(')
		return true;
	else
		return false;
}

int postfixEval(){
	int i = 0;
	 
	while(postfix[i] != '\0'){
		if(isOperator(postfix[i])){
			int result = 0, y = pop(), x = pop();
			char op = postfix[i];
			
			switch(op){
				case '+':
					result = x + y;
					break;
				case '-':
					result = x - y;
					break;
				case '*':
					result = x * y;
					break;
				case '/':
					result = x / y;
					break;
				case '^':
					result = pow(x,y);
					break;
			}
			push(result);
		}
		else{
			int pushVal = 0;
			pushVal = pushVal * 10 + ( postfix[i] - '0' );
			push(pushVal);
		}
		i++;
	}
	return(pop());
}

void main(){
	char postExp[50];
	printf("\nEnter The Postfix Expression: ");
	scanf("%[^\n]", &postfix);
	printf("\nValue: %d", postfixEval());
	printf("\n");
}