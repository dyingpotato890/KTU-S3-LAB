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

void sparseDisplay(struct triplet temp[30]){
	for (int i = 0; i <= temp[0].val; i++){
		printf("%d\t%d\t%d\t", temp[i].row, temp[i].col, temp[i].val);
		printf("\n");
	}
}

void sparseTranspose(){
	int k = 1;
	
	t[0].row = s[0].col;
	t[0].col = s[0].row;
	t[0].val = s[0].val;
	
	for(int i = 0; i < t[0].row; i++){
		for(int j = 1; j <= t[0].val; j++){
			if (s[j].col == i){
				t[k].row = s[j].col;
				t[k].col = s[j].row;
				t[k].val = s[j].val;
				k++;
			}
		}
	}
}

void sparseSymmetry(){
	if (r != c)
		printf("\nThe Given Sparse Matrix Is Not Symmetric!");
	else{
		int flag = 1;
		for(int i = 1; i <= t[0].val; i++){
			if ((s[i].row != t[i].row) || (s[i].col != t[i].col) || (s[i].val != t[i].val)){
				flag = 0;
				break;
			}
		}
	
		if (flag == 1)
			printf("\nThe Given Sparse Matrix Is Symmetric!");
		else
			printf("\nThe Given Sparse Matrix Is Not Symmetric!");
	}
}

void main(){	
	sparseInput();
	printf("\nSparse Representation: \n");
	sparseDisplay(s);
	
	sparseTranspose();
	printf("\nSparse Transpose:\n ");
	sparseDisplay(t);
	
	sparseSymmetry();
}
