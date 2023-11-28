import java.util.Scanner;

class BubbleSort{
	static Scanner s = new Scanner(System.in);
	static int[] arr = new int[20];
	static int n;
	
	public static void sort(){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n-i-1; j++){
				if (arr[j] > arr[j+1]){
					int temp = arr[j];
					arr[j] = arr[j+1];
					arr[j+1] = temp;
				}
			}
		}
		System.out.print("\nSorted Array: ");
		for(int i = 0; i < n; i++)
			System.out.print(" " + arr[i]);
	}
	
	public static void main(String arg[]){
		System.out.print("No. Of Array Elements: ");
		n = s.nextInt();
	
		for(int i = 0; i < n; i++){
			System.out.print("\nEnter The Element: ");
			int e = s.nextInt();
			arr[i] = e;
		}
		sort();
	}
}