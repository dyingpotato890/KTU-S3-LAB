import java.io.*;

class FileExceptions {
    static void outputFile(){
        try{
            FileOutputStream out = new FileOutputStream("ReadME.txt");
            String str = "Hello World!";
            byte b[] = str.getBytes();
            out.write(b);
            out.close();
            System.out.println("Content Stored!");
        }
        catch(java.lang.Exception e){
            e.printStackTrace();
        }
    }

    static void inputFile(){
        try{
            FileInputStream in = new FileInputStream("ReadME.txt");
            int i = 0; 
            System.out.println("File Contents:\n");
            while((i = in.read()) != -1)    
                System.out.print((char)i);        
            in.close();
        }
        catch(java.lang.Exception e){
            e.printStackTrace();
        }
    }
    public static void main(String arg[]){
        outputFile();
        inputFile();
    } 
}