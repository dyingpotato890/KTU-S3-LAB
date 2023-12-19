import java.util.*;

class Shapes{
	static double area(double r){
		return 3.14*r*r;
	}
	
	static double area(int w, double l, double b){
		if (w == 2)
			return l*b;
		else
			return 0.5*l*b;
	}
}

class AreaOfShapes{
	public static void main(String a[]){
		Scanner sc = new Scanner(System.in);
		Shapes obj = new Shapes();
		int flag = 1;
		
		double result, tempb, templ, tempr, temph;

		System.out.println("\n================ OPTIONS ================");
		System.out.println("\t1 - Circle");
		System.out.println("\t2 - Rectangle");
		System.out.println("\t3 - Triangle");
		System.out.println("\t4 - Exit");
		System.out.println("=========================================\n");
		
		while(flag == 1){	
			System.out.print("Enter Your Option: ");
			int o = sc.nextInt();
			
			switch(o){
				case 1:
					System.out.print("\nEnter The Radius Of Circle: ");
					tempr = sc.nextDouble();
			
					result = obj.area(tempr);
					System.out.println("Area Of Circle: " + result);
					break;
									
				case 2:
					System.out.print("\nEnter The Length Of Rectangle: ");
					templ = sc.nextDouble();
					System.out.print("Enter The Breadth Of Rectangle: ");
					tempb = sc.nextDouble();
				
					result = obj.area(2, templ, tempb);
					System.out.println("Area Of Rectangle: " + result);
					break;
						
				case 3:
					System.out.print("\nEnter The Base Of Triangle: ");
					tempb = sc.nextDouble();
					System.out.print("Enter The Height Of Triangle: ");
					temph = sc.nextDouble();
				
					result = obj.area(3, tempb, temph);
					System.out.println("Area Of Traingle: " + result);
					break;
				
				case 4:
					System.out.print("\nClosing...");
					flag = 0;
					break;
					
				default:
					System.out.print("\nPlease Enter A Valid Option!");
			}
		}
	}
}