import java.util.*;

class FrequencyString{
	public static void main(String args[]){
		Scanner obj = new Scanner(System.in);
	
		System.out.print("Enter The Word: ");
		String str = obj.nextLine();
		
		System.out.print("Enter The Character To Check: ");
		String str2 = obj.nextLine();
		char charVal = str2.charAt(0);
		
		int count = 0;
		for(int i = 0; i < str.length(); i++){
			if (str.charAt(i) == charVal)
				count++;
		}	
		System.out.println("Count Of " + charVal + " = " + count);
	}
}