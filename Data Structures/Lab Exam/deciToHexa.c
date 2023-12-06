#include <stdio.h>
#include <string.h> 

int hexa, top = -1;
char binStack[50];

void push(int val){
    if (val < 10)
        binStack[++top] = val + '0';
    else{
        switch(val){
            case 10:
                binStack[++top] = 'A';
                break;
            case 11:
                binStack[++top] = 'B';
                break;
            case 12:
                binStack[++top] = 'C';
                break;
            case 13:
                binStack[++top] = 'D';
                break;
            case 14:
                binStack[++top] = 'E';
                break;
            case 15:
                binStack[++top] = 'F';
                break;
        }
    }
}

void main(){
    printf("Enter The Decimal Number: ");
    scanf("%d", &hexa);
    while(hexa != 0){
        push(hexa % 16);
        hexa = hexa / 16;
    }
    printf("\nHexadecimal Number: ");
    printf("%s", strrev(binStack));
}