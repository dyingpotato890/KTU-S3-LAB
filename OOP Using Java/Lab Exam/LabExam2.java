import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class Global{
    public static Integer n;
} 

class Thread1 extends Thread{
    public void run(){
        try{
            synchronized(Global.n){
                for (int i = 0; i < Global.n; i++){
                    System.out.println("Thrikkakara");
                    Thread.sleep(1000);
                }   
            }
        } catch( java.lang.Exception e){
            e.printStackTrace();
        }
    }
}

class Thread2 extends Thread{
    public void run(){
        try{
            synchronized(Global.n){
                for (int i = 0; i < Global.n; i++){
                    System.out.println("Kochi");
                    Thread.sleep(1000);
                }   
            }
        } catch( java.lang.Exception e){
            e.printStackTrace();
        }
    }
}

class GUI extends JFrame implements ActionListener{
    JButton b1;
    JTextField text1;
    JLabel label1;
    GUI(){
        label1 = new JLabel("Enter The Value Of N:");

        b1 = new JButton("PRINT");
        b1.setBounds(250,400,200,150);
        b1.setFocusable(false);
        b1.addActionListener(this);

        text1 = new JTextField();
        text1.setPreferredSize(new Dimension(500, 100));
        setSize(500,500);
        setLayout(new BorderLayout());

        add(label1, BorderLayout.NORTH);
        add(text1, BorderLayout.CENTER);
        add(b1, BorderLayout.SOUTH);

        setVisible(true);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    public void actionPerformed(ActionEvent e){
        if (e.getSource() == b1){
            String str = text1.getText();
            Global.n = Integer.parseInt(str);
            Thread1 t1 = new Thread1();
            Thread2 t2 = new Thread2();
            t1.start();
            t2.start();
        }
    }
}

class LabExam2{
    public static void main(String[] args) {
        new GUI();
    }
}