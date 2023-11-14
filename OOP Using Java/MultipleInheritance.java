import java.io.*;
import java.util.Scanner;

interface Sports{
	final float sportwt = 6.0F;
	public void putwt();
}

class Student{
	static Scanner s = new Scanner(System.in);
	static int rollnumber;
	
	static void getNumber(){
		System.out.print("Enter The Roll Number: ");
		rollnumber = s.nextInt();
	};
	
	static void putNumber(){
		System.out.println("Roll Number: " + rollnumber);
	};
}

class Test extends Student{
	static int term1, term2;
	
	static void getMarks(){
		System.out.print("Enter The Term 1 Marks: ");
		term1 = s.nextInt();
		System.out.print("Enter The Term 2 Marks: ");
		term2 = s.nextInt();
	}
	
	static void putMarks(){
		System.out.println("Term 1 Marks: " + term1);
		System.out.println("Term 2 Marks: " + term2);
	}
}

class MultipleInheritance extends Test implements Sports{	
	public void putwt(){
		System.out.println("Sports Weightage: " + sportwt);
		float total = (float)term1 + (float)term2 + sportwt;
		System.out.println("Total Score: " + total);
	}

	public static void main(String arg[]){
		MultipleInheritance obj = new MultipleInheritance();
		obj.getNumber();
		obj.getMarks();
		obj.putNumber();
		obj.putMarks();
		obj.putwt();
	}
}