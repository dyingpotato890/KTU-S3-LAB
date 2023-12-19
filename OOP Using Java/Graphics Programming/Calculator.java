import java.awt.event.*;
import java.awt.*;
import javax.swing.*;

public class Calculator extends JFrame implements ActionListener {
    JButton b10, b11, b12, b13, b14, b15;
    JButton b[] = new JButton[10];
    int i;
    double n1;
    JTextField res;
    String input = "";
    char op;

    public Calculator() {
        super("Calculator");

        setLayout(new BorderLayout());
        JPanel p = new JPanel();
        p.setLayout(new GridLayout(4, 4));
        for (int i = 0; i <= 9; i++) {
            b[i] = new JButton(i + "");
            p.add(b[i]);
            b[i].addActionListener(this);
        }
        b10 = new JButton("+");
        p.add(b10);
        b10.addActionListener(this);

        b11 = new JButton("-");
        p.add(b11);
        b11.addActionListener(this);

        b12 = new JButton("*");
        p.add(b12);
        b12.addActionListener(this);

        b13 = new JButton("/");
        p.add(b13);
        b13.addActionListener(this);

        b14 = new JButton("=");
        p.add(b14);
        b14.addActionListener(this);

        b15 = new JButton("C");
        p.add(b15);
        b15.addActionListener(this);

        res = new JTextField(10);
        res.setEditable(false);
        add(p, BorderLayout.CENTER);
        add(res, BorderLayout.NORTH);
        setVisible(true);
        setSize(200, 200);
    }

    public void actionPerformed(ActionEvent ae) {
        JButton pb = (JButton) ae.getSource();
        if (pb == b15) {
            n1 = 0;
            input = "";
            res.setText("");
        } else if (pb == b14) {
            if (!input.isEmpty()) {
                input += "=" + evaluateExpression(input);
                res.setText(input);
            }
        } else {
            boolean opf = false;
            if (pb == b10) {
                op = '+';
                opf = true;
            }
            if (pb == b11) {
                op = '-';
                opf = true;
            }
            if (pb == b12) {
                op = '*';
                opf = true;
            }
            if (pb == b13) {
                op = '/';
                opf = true;
            }

            if (opf == false) {
                for (i = 0; i < 10; i++) {
                    if (pb == b[i]) {
                        input += i;
                        res.setText(input);
                    }
                }
            } else {
                input += op;
                res.setText(input);
            }
        }
    }

    String evaluateExpression(String expression) {
        String[] parts = expression.split("[\\+\\-\\*\\/]");
        String result1;
        double result = 0;
        try {
            double num1 = Double.parseDouble(parts[0]);
            double num2 = Double.parseDouble(parts[1]);

            switch (op) {
                case '+':
                    result = num1 + num2;
                    break;
                case '-':
                    result = num1 - num2;
                    break;
                case '*':
                    result = num1 * num2;
                    break;
                case '/':
                    System.out.println(num2);
                        if (num2 == 0.0) {
                            result1="Can't divide by zero";
                            return result1;
                        
                        } 
                        else 
                        result = num1 / num2; 
                    break;
            }
        } catch (NumberFormatException | ArrayIndexOutOfBoundsException | ArithmeticException e) {
            System.out.println("Error!!");
        }
        result1 = "" + result;
        return result1;
    }

    public static void main(String arg[]) {
        new Calculator();
    }
}