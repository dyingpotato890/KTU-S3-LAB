import java.util.Random;

class Global{
	static int num;
}

class ThreadA extends Thread{
	public void run(){  
		Random r = new Random();
		while(true){
			Global.num = r.nextInt(10);
			try{
		    	this.sleep(1000);    
			} catch(InterruptedException e){
				e.printStackTrace();
			}
		}
	}
}

class ThreadB extends Thread{
	public void run(){	
		while(true){
			if(Global.num % 2 == 0)
				System.out.println("\n" + Global.num*Global.num);
			try{
		    	this.sleep(1000);    
			} catch(InterruptedException e){
				e.printStackTrace();
			}
		}
	}
}

class ThreadC extends Thread{
	public void run(){
		while(true){
			if(Global.num % 2 != 0)
				System.out.println("\n" + Global.num*Global.num*Global.num);
			try{
		    	this.sleep(1000);    
			} catch(InterruptedException e){
				e.printStackTrace();
			}
		}
	}
}

class MultiThread{
	public static void main(String args[]){
			ThreadA t1 = new ThreadA();
			ThreadB t2 = new ThreadB();
			ThreadC t3 = new ThreadC();

			t1.start();
			t2.start();
			t3.start();
	}
}