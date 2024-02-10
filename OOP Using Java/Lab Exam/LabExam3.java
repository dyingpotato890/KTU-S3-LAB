import java.util.Scanner;

class Global {
    public static String str = "Hello World!";
}

class Thread1 extends Thread {
    public void run() {
        try {
            synchronized (Global.str) {
                Scanner sc = new Scanner(System.in);
                System.out.print("Enter The String: ");
                Global.str = sc.nextLine();
            }
            sleep(1000);
        } catch (java.lang.Exception e) {
            e.printStackTrace();
        }
    }
}

class Thread2 extends Thread {
    public void run() {
        boolean flag = true;
        try {
            while (flag) {
                System.out.println("The String: " + Global.str);
                Thread.sleep(1000);
            }
                
        } catch (java.lang.Exception e) {
            e.printStackTrace();
        }
    }
}

public class LabExam3 {
    public static void main(String args[]) throws InterruptedException {
        Thread1 t1 = new Thread1();
        Thread2 t2 = new Thread2();
        t2.start();
        t1.start();
        t1.join();
    }
}