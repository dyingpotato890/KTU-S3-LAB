#include <stdio.h>

struct triplet{
	int row;
	int col;
	int val;
} s[30], t[30];

int r, c, n;

void sparseInput(){
	printf("\nEnter The Total Number Of Elements: ");
	scanf("%d", &n);
	printf("\nEnter The Number Of Rows And Columns: ");
	scanf("%d %d", &r, &c);
	
	s[0].row = r;
	s[0].col = c;
	s[0].val = n;
	
	for(int i = 1; i <= n; i++){
		printf("Enter The Row, Column & Value Of Element %d: ", i);
		scanf("%d %d %d", &s[i].row, &s[i].col, &s[i].val);
	}
}

void sparseDisplay(struct triplet S[]){
	printf("\nRow\tColumn\tValue\n");
	for(int i=0 ; i < S[0].val + 1 ; i++){
		printf("%d\t%d\t%d\n", S[i].row, S[i].col, S[i].val);
	}
}

void sparseTranspose(){
	int k = 1;
	
	t[0].row = s[0].col;
	t[0].col = s[0].row;
	t[0].val = s[0].val;
	
	for(int i = 0; i < s[0].col; i++){
		for(int j = 1; j <= s[0].val; j++){
			if (s[j].col == i){
				t[k].row = s[j].col;
				t[k].col = s[j].row;
				t[k].val = s[j].val;
				k++;
			}
		}
	}
}

void main(){
	sparseInput();
	printf("\nSparse Representation: \n");
	sparseDisplay(s);
	
	sparseTranspose();
	printf("\nSparse Transpose:\n ");
	sparseDisplay(t);
}
