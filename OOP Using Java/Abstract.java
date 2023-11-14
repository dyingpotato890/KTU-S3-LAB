abstract class Shape{
	abstract void noOfSides();
}

class rectangle extends Shape{
	void noOfSides(){
		System.out.println("A Rectangle Has 4 Sides.");
	}
}
class triangle extends Shape{
	void noOfSides(){
		System.out.println("A Triangle Has 3 Sides.");
	}
}
class hexagon extends Shape{
	void noOfSides(){
		System.out.println("A Hexagon Has 6 Sides.");
	}
}

class Abstract{
	public static void main(String args[]){
		rectangle robj = new rectangle();
		triangle tobj = new triangle();
		hexagon hobj = new hexagon();
	
		robj.noOfSides();
		tobj.noOfSides();
		hobj.noOfSides();
	}
}