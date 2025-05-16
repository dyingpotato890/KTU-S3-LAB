#include <stdio.h>

struct triplet{
	int row;
	int col;
	int val;
} A[30], B[30], C[30];

int r1, c1, r2, c2, arr1[50][50], arr2[50][50];

void sparseInput(struct triplet s[]){
	int r, c, n;

	printf("\nEnter The Total Number Of Elements: ");
	scanf("%d", &n);
	printf("\nEnter The Number Of Rows And Columns: ");
	scanf("%d %d", &r, &c);
	
	s[0].row = r;
	s[0].col = c;
	s[0].val = n;
	
	printf("\n");
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

void sparseAdd(struct triplet Ar[],struct triplet Br[],struct triplet r[]){
	int r1 = Ar[0].row, c1 = Ar[0].col, r2 = Br[0].row, c2 = Br[0].col;

 	if(r1 != r2 || c1 != c2)
  		printf("The Two Matrices Cannot Be Added!");
 	else{
  		r[0].row = Ar[0].row;
  		r[0].col = Ar[0].col;

  		int n = 1, m = 1, k = 1;

  		for(int i = 0; i < r1; i++){
   			for(int j = 0; j < c1; j++){
    			if(Ar[m].row == i && Ar[m].col == j && Br[n].row == i && Br[n].col == j){
     				r[k].row = Ar[m].row;
     				r[k].col = Br[n].col;
     				r[k++].val = Ar[m++].val + Br[n++].val;
    			}

    			else if(Ar[m].row == i && Ar[m].col == j){
     				r[k].row = Ar[m].row;
     				r[k].col = Ar[m].col;
     				r[k++].val = Ar[m++].val;
    			}
    			else if(Br[n].row == i && Br[n].col == j){
     				r[k].row = Br[n].row;
     				r[k].col = Br[n].col;
     				r[k++].val = Br[n++].val;
    			}
   			}
  		}
  		r[0].val = k-1;
 	}
}

void main(){
	printf("\n================== Sparse Matrix - A ==================\n");
	sparseInput(A);
	printf("\nSparse Representation Of A: \n");
	sparseDisplay(A);
	
	printf("\n================== Sparse Matrix - B ==================\n");
	sparseInput(B);
	printf("\nSparse Representation Of B: \n");
	sparseDisplay(B);
	
	/*Addition*/
	sparseAdd(A,B,C);
	printf("\nSum Of A And B: \n");
	sparseDisplay(C);
}