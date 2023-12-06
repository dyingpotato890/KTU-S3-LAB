#include <stdio.h>

int p1len, p2len, starta, startb, startc;

struct poly {
	int coeff;
	int expo;
} p[100];

void read(struct poly p[100], int n, int start){
	for(int i = start; i < n; i++){
		printf("\n");
		printf("Enter The Coefficient And Exponent Value Of t%d: ", i+1);
		scanf("%d %d", &p[i].coeff, &p[i].expo);
	}
}

void display(int n, int start){
	for(int i = start; i < n; i++){
		if (p[i].expo != 0){
			printf("%dx^%d", p[i].coeff, p[i].expo);
		}
		else
			printf("%d", p[i].coeff);
		if((i + 1) != n)
			printf(" + ");
	}
}

int add(int a, int b, int c){
	while((a < p1len) && (b < (p1len + p2len))){
		if (p[a].expo == p[b].expo){
			p[c].expo = p[a].expo;
			p[c++].coeff = p[a++].coeff + p[b++].coeff;
		}
		else if (p[a].expo > p[b].expo){
			p[c].expo = p[a].expo;
			p[c++].coeff = p[a++].coeff;
	}
		else{
			p[c].expo = p[b].expo;
			p[c++].coeff = p[b++].coeff;
		}
	}
	while(a != p1len){
		p[c].expo = p[a].expo;
		p[c++].coeff = p[a++].coeff;
	}
	while(b < (p1len + p2len)){
		p[c].expo = p[b].expo;
		p[c++].coeff = p[b++].coeff;
	}
	return c;
}

void main(){	
	printf("\nEnter The Number Of Terms In P1: ");
	scanf("%d", &p1len);
	read(p,p1len,0);	
	
	printf("\nEnter The Number Of Terms In P2: ");
	scanf("%d", &p2len);
	read(p,(p1len + p2len),p1len);
	
	starta = 0;
	startb = p1len;
	startc = p1len + p2len ;

	int endb = (p1len+p2len);
	int endc = add(starta, startb, startc);

	printf("\nPolynomial 1 = ");
	display(startb, 0);
	printf("\nPolynomial 2 = ");
	display(endb, startb);
	printf("\nSum Of P1 & P2 = ");
	display(endc, endb);
	printf("\n");
}
