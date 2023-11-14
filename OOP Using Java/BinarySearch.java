import java.io.*;
import java.util.Scanner;

class BinarySearch{
	static int flag = 0;
	
	public static void binarySearch(int arr[], int ub, int search){
		int l = 0, u = ub;
		
		while (l <= u){
			int mid = (l+u)/2;
			
			if (arr[mid] == search){
				System.out.println("The Search Element Has Been Found At Position "+ (mid+1));
				flag = 1;
				break;
			}
			else if (arr[mid] > search)
				u = mid - 1;
			else
				l = mid + 1;
		}
		if (flag == 0)
			System.out.println("The Search Element Has Not Been Found");
	}
	
	public static void main(String args[]){
		BinarySearch obj = new BinarySearch();
		Scanner s = new Scanner(System.in);
		int[] arr = new int[20];
		int i;
		
		System.out.print("Enter The No. Of Elements: ");
		int n = s.nextInt();
		
		for (i = 0; i < n; i++){
			System.out.print("Enter The Element " + (i+1) + " : ");
			arr[i] = s.nextInt();
		}
		
		System.out.print("Enter The Search Element: ");
		int search = s.nextInt();
		obj.binarySearch(arr,i,search);
	}
}