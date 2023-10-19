#include <stdio.h>

struct triplet{
	int row;
	int col;
	int val;
} s[30];

int r, c, arr[50][50], count0 = 0, tcount = 0;

void createMatrix(){
	for(int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			printf("\nEnter The Element [%d,%d]: ",(i+1),(j+1));
			scanf("%d", &arr[i][j]);
		}
	}
}

void displayMatrix(){
	printf("\nSparse Matrix: \n");
	printf("\nRow\tColumn\tValue\n");
	for(int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			if (arr[i][j] == 0)
				count0++;
			tcount++;
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}
}

void sparseRep(){
	int k = 1;
	
	s[0].row = r;
	s[0].col = c;
	s[0].val = k;
	for(int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			if (arr[i][j] != 0){
				s[k].row = i;
				s[k].col = j;
				s[k].val = arr[i][j];
				k++;
			}
		}
	}
	s[0].val = k-1;
}

void sparseDisplay(){
	printf("\nSparse Representation: \n");
	for (int i = 0; i <= s[0].val; i++)
		printf("%d\t%d\t%d\t\n", s[i].row, s[i].col, s[i].val);

	float sparsity = (float)count0/(float)tcount;
	printf("\nSparsity Of The Given Representation: %.2f\n", sparsity);
}

void main(){
	printf("\nEnter The Number Of Rows And Columns For Sparse Matrix: ");
	scanf("%d %d", &r, &c);
	createMatrix();
	displayMatrix();
	sparseRep();
	sparseDisplay();
}
