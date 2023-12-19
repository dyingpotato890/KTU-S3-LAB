import java.util.Scanner;

class BinarySearch{
	static int flag = 0;
	static int[] arr = new int[20];
	static int i;

	public static void sort(){
		for(int j = 0; j < i; j++){
			for(int k = 0; k < i-j-1; k++){
				if (arr[k] > arr[k+1]){
					int temp = arr[k];
					arr[k] = arr[k+1];
					arr[k+1] = temp;
				}
			}
		}
		System.out.print("\nSorted Array: ");
		for(int j = 0; j < i; j++)
			System.out.print(" " + arr[j]);
	}
	
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
		
		System.out.print("Enter The No. Of Elements: ");
		int n = s.nextInt();
		
		for (i = 0; i < n; i++){
			System.out.print("Enter The Element " + (i+1) + " : ");
			arr[i] = s.nextInt();
		}
		
		sort();
		System.out.print("\nEnter The Search Element: ");
		int search = s.nextInt();
		obj.binarySearch(arr,i,search);
	}
}