import java.util.*;

class MatrixMulti{
	static Scanner myObj = new Scanner(System.in);

	static void insert(int arr[][], int n, int m, String w){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                System.out.print("Enter the element (" + i + "," + j + ") " + w + ": " );
                arr[i][j] = myObj.nextInt();
            }
			System.out.print("\n");
        }
    }
	public static void main(String args[]){
		System.out.print("Enter The Number Of Rows Of A: ");
		int n1 = myObj.nextInt();
		System.out.print("Enter The Number Of Columns Of A: ");
		int m1 = myObj.nextInt();
		System.out.print("\n");
		
		System.out.print("Enter The Number Of Rows Of B: ");
		int n2 = myObj.nextInt();
		System.out.print("Enter The Number Of Columns Of B: ");
		int m2 = myObj.nextInt();
		System.out.print("\n");
		
		if (m1 == n2){
			int[][] A = new int[n1][m1];
			int[][] B = new int[n2][m2];
			int[][] P = new int[n1][m2];
		
			insert(A, n1, m1, "A");
			insert(B, n2, m2, "B");
				
			for(int i = 0; i < n1; i++){
				for(int j = 0; j < m2; j++){
					P[i][j] = 0;
					for(int k = 0; k < m1; k++)
						P[i][j] += A[i][k]*B[k][j];
				}
			}
			
			System.out.println("Product :");
			for(int i = 0; i < n1; i++){
				for(int j = 0; j < m2; j++)
					System.out.print(P[i][j] + "\t");
				System.out.print("\n");
			}
		}
		else
			System.out.println("The Two Matrices Cannot Be Multiplied");
	}
}