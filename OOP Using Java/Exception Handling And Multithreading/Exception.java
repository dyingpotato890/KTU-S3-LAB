import java.util.Scanner;

class Exception{
	public static void divide(float n1 , float n2) throws ArithmeticException{
		if (n2 == 0)
			throw new ArithmeticException("Division By 0 Not Possible");
		else
			System.out.println("Result = " + (n1/n2));	
	}
	
	public static void main(String args[]){	
		try{
			Scanner s = new Scanner(System.in);	
			System.out.print("Enter Your First Number: ");
			float a = s.nextFloat();
			System.out.print("Enter Your Second Number: ");
			float b = s.nextFloat();
			divide(a,b);
		}
		catch(ArithmeticException e){
			e.printStackTrace();
		}
		finally{
			System.out.println("Inside Finally Block");
		}
		System.out.println("Outside Finally Block");
	}
}