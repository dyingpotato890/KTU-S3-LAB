#include <stdio.h>
#include <stdlib.h>

struct term {
    int coeff;
    int expo;
    struct term* link;
};

struct term *p1, *p2, *r;

struct term* polyInit(){
	int n, ctemp, etemp;  
	printf("\nEnter The Number Of Polynomial Terms: ");
	scanf("%d", &n);

    struct term* ptr = (struct term*)malloc(sizeof(struct term));
    struct term *head = ptr;

	for (int i = 1; i < n+1; i++){
        printf("\nEnter The Coefficient For T%d: ", i);
        scanf("%d", &ctemp);
        printf("Enter The Exponent For T%d: ", i);
        scanf("%d", &etemp);
		
        ptr -> coeff = ctemp;
        ptr -> expo = etemp;

        if(i != n){
			ptr -> link = (struct term*)malloc(sizeof(struct term));
			ptr = ptr -> link;
		}
		else
			ptr -> link = NULL;
	}
    return head;
}

void display(struct term* ptemp){
    struct term* ptr  = ptemp;

	if (ptr == NULL)
        printf("Polynomial Does Not Exist!");
    else{
        while(ptr != NULL){
		    if(ptr -> expo != 0)
			    printf("%dx^%d", ptr-> coeff, ptr -> expo);
		    else
			    printf("%d", ptr -> coeff);
		    if(ptr -> link != NULL)
			    printf("+");
		    ptr = ptr -> link;
	    }
    }
}

void add(){
	struct term *ptr1, *ptr2, *ptrR, *ptrr;
	ptr1 = p1;
	ptr2 = p2;
    ptrR  = (struct term*)malloc(sizeof(struct term));
    r = ptrR;
	
	while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1 -> expo < ptr2 -> expo) {
            ptrR -> coeff = ptr2 -> coeff;
            ptrR -> expo = ptr2 -> expo;
            ptr2 = ptr2 -> link;
        }
        else if (ptr1 -> expo > ptr2 -> expo) {
            ptrR -> coeff = ptr1 -> coeff;
            ptrR -> expo = ptr1 -> expo;
            ptr1 = ptr1 -> link;
        }
        else{
			if(ptr1 -> coeff + ptr2 -> coeff != 0){
				ptrR -> coeff = ptr1 -> coeff + ptr2 -> coeff;
				ptrR -> expo = ptr1 -> expo;
				ptr1 = ptr1 -> link;
				ptr2 = ptr2 -> link;
			}
			else{
				ptr1 = ptr1 -> link;
				ptr2 = ptr2 -> link;
				continue;
			}
		}
        ptrR -> link = (struct term*)malloc(sizeof(struct term));
		ptrR = ptrR -> link;
    }
    
    if (ptr1 != NULL)
		ptrr = ptr1;
	else
		ptrr = ptr2;

	while(ptrr != NULL){
		ptrR -> coeff = ptrr -> coeff;
		ptrR -> expo = ptrr -> expo;

		if(ptrr -> link != NULL){
			ptrR -> link = (struct term*)malloc(sizeof(struct term));
			ptrR = ptrR -> link;
		}
		else
			ptrR -> link = NULL;
		ptrr = ptrr -> link;
	}
}

void main(){
	printf("\n======= Inititializing P1 =======");
	p1 = polyInit();   
	printf("\n======= Inititializing P2 =======");
	p2 = polyInit();

    printf("\nPolynomial 1: ");
    display(p1);
    printf("\nPolynomial 2: ");
    display(p2);

    add();
    printf("\nResult: ");
    display(r);
}
