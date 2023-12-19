import java.io.*;

class FileHandling{
	public static void write(){
		try{
			File f = new File("ReadME.txt");
			
			if (f.createNewFile())
				System.out.println("File Has Been Created!");
			else
				System.out.println("File Already Exists!");
				
			FileWriter fw = new FileWriter("ReadME.txt");
			fw.write("Hello World\nThis is inside a file!");
			fw.close();
		}
		catch(java.lang.Exception e){
			e.printStackTrace();
		}
	}
	
	public static void read(){
		try{
			File f = new File("ReadME.txt");
			FileReader fr = new FileReader("ReadME.txt");

			int data = fr.read();
			while (data != -1) {
				System.err.print((char)data);
				data = fr.read();
			}
			fr.close();
		}
		catch(java.lang.Exception e){
			e.printStackTrace();	
		}
	}
	
	public static void main(String args[]){
		write();
		read();
	}
}