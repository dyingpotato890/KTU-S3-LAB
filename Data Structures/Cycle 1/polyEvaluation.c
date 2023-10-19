#include <stdio.h>

struct poly {
	int coeff;
	int expo;
}p[20];

int plen, x;

void read(){
	for(int i = 0; i < plen; i++){
		printf("\n");
		printf("Enter The Enter The Coefficient & Exponent Value Of t%d: ", i+1);
		scanf("%d %d", &p[i].coeff, &p[i].expo);
	}
}

void display(){
	printf("\nPolynomial: ");
	for(int i = 0; i < plen; i++){
		if (p[i].expo == 0){
			if (p[i].coeff > 0){
				printf(" + %d", p[i].coeff, p[i].expo);
			}
			else{
				printf(" +%d", p[i].coeff, p[i].expo);
			}
		}
		else if (p[i].coeff > 0){
			printf(" + %dx^%d", p[i].coeff, p[i].expo);
		}
		else if (p[i].coeff < 0){
			printf(" + %dx^%d", p[i].coeff, p[i].expo);
		}
	}
}

void eval(){
	int result = 0;
	for(int i = 0; i < plen; i++){
		if (p[i].expo == 0){
			result += p[i].coeff;
		}
		else{
			int pow = 1;
			for(int _ = 0; _ < p[i].expo; _++){
				pow = pow * x;  
			}
			result += (p[i].coeff * pow);
		}
	}
	printf("\nResult = %d\n", result);
}

void main(){	
	printf("\nEnter The Number Of Terms In The Polynomial: ");
	scanf("%d", &plen);
	read();
	
	printf("\nEnter The Value Of x: ");
	scanf("%d", &x);

	display();
	eval();
}