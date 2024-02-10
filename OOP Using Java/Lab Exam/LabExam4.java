import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;
import java.awt.*;
import java.awt.event.*;
import java.io.BufferedReader;
import java.io.FileReader;
import java.util.StringTokenizer;

class GUI extends JFrame implements ActionListener{
    JButton importbtn, calculatebtn;
    JPanel pnl, pnl2;
    JTextField tf1, tf2, tf3, tf4, tf5;
    JLabel l1, l2, l3, l4, l5;
    public BufferedReader br;

    GUI() throws java.lang.Exception{
        br = new BufferedReader(new FileReader("inputfile.txt"));
        br.readLine();
        br.readLine();
        br.readLine();

        importbtn = new JButton("Import Data");
        calculatebtn = new JButton("Calculate");
        importbtn.setFocusable(false);
        calculatebtn.setFocusable(false);
        importbtn.addActionListener(this);
        calculatebtn.addActionListener(this);
        
        pnl = new JPanel();
        pnl.setLayout(new FlowLayout());;
        pnl.add(importbtn);
        pnl.add(calculatebtn);

        pnl2 = new JPanel();
        pnl2.setLayout(new FlowLayout());;
        l1 = new JLabel("ROLL NO: ");
        l2 = new JLabel("NAME: ");
        l3 = new JLabel("MARK 1: ");
        l4 = new JLabel("MARK 2: ");
        l5 = new JLabel("TOTAL MARKS: ");
        tf1 = new JTextField();
        tf2 = new JTextField();
        tf3 = new JTextField();
        tf4 = new JTextField();
        tf5 = new JTextField();
        tf1.setPreferredSize(new Dimension(350,20));
        tf2.setPreferredSize(new Dimension(350,20));
        tf3.setPreferredSize(new Dimension(350,20));
        tf4.setPreferredSize(new Dimension(350,20));
        tf5.setPreferredSize(new Dimension(350,20));
        tf1.setEditable(false);
        tf2.setEditable(false);
        tf3.setEditable(false);
        tf4.setEditable(false);
        tf5.setEditable(false);
        pnl2.add(l1);
        pnl2.add(tf1);
        pnl2.add(l2);
        pnl2.add(tf2);
        pnl2.add(l3);
        pnl2.add(tf3);
        pnl2.add(l4);
        pnl2.add(tf4);
        pnl2.add(l5);
        pnl2.add(tf5);

        setLayout(new BorderLayout());
        add(pnl, BorderLayout.SOUTH);
        add(pnl2, BorderLayout.CENTER);

        setSize(new Dimension(450,300));
        setVisible(true);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    public void actionPerformed(ActionEvent ae){
        if (ae.getSource() == importbtn){
            try{
                tf5.setText("");
                String line = br.readLine();
                if (line != null){
                    StringTokenizer st = new StringTokenizer(line);
                    tf1.setText(st.nextToken());
                    tf2.setText(st.nextToken());
                    tf3.setText(st.nextToken());
                    tf4.setText(st.nextToken());
                }
            } catch (java.lang.Exception e){
                e.printStackTrace();
            }
        }

        if (ae.getSource() == calculatebtn){
            int totalmrk = Integer.parseInt(tf3.getText()) + Integer.parseInt(tf4.getText());
            tf5.setText(String.valueOf(totalmrk));
        }
    }
}

public class LabExam4 {
    public static void main(String[] args) {
        try{
            new GUI();
        } catch (java.lang.Exception e){
            e.printStackTrace();
        }
    }
}