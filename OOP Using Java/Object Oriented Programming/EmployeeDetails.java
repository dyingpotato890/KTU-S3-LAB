import java.util.*;

class Employee{
	String name;
	int age;
	String phNo;
	String ad;
	int sal;
	
	void print_Salary(){
		System.out.print("Salary: " + sal);
	}
}

class Officer extends Employee{
	String spec;
}

class Manager extends Employee{
	String dep;
}

class EmployeeDetails{
	static void Input(Employee tempObj){
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter The Name: ");
		tempObj.name = sc.nextLine();
		
		System.out.print("Enter The Age: ");
		tempObj.age = sc.nextInt();
		
		sc.nextLine();
		System.out.print("Enter The Phone Number: ");
		tempObj.phNo = sc.nextLine();
		
		System.out.print("Enter The Address Of The Employee: ");
		tempObj.ad = sc.nextLine();
		
		System.out.print("Enter The Salary Of The Employee: ");
		tempObj.sal = sc.nextInt();
	}
	
	static void display(Employee tempObj, String emp){
		System.out.println("\n\n" + emp + " Name: " + tempObj.name);
		System.out.println(emp + " Age: " + tempObj.age);
		System.out.println(emp + " Phone Number: " + tempObj.phNo);
		System.out.println(emp + " Address: " + tempObj.ad);
	}
	
	public static void main(String a[]){
		Officer ofcObj = new Officer();
		Manager mngObj = new Manager();
		
		System.out.println("\n\t\t\t\t\t================= Details Of Officer =================");
		Input(ofcObj);
		System.out.println("\n\t\t\t\t\t================= Details Of Manager =================");
		Input(mngObj);
		
		display(ofcObj, "Officer");
		ofcObj.print_Salary();
		
		display(mngObj, "Manager");
		mngObj.print_Salary();
	}
}
