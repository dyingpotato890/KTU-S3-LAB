import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class TrafficLight extends JFrame implements ActionListener {
    private JPanel lightPanel;
    private JTextField messageField;
    private Color currentColor;

    private JRadioButton redRadioButton;
    private JRadioButton yellowRadioButton;
    private JRadioButton greenRadioButton;

    public TrafficLight() {
        setTitle("Traffic Light GUI");
        setSize(300, 500);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        currentColor = Color.RED;

        lightPanel = new JPanel() {
            protected void paintComponent(Graphics g) {
                super.paintComponent(g);
                g.setColor(Color.BLACK);
                g.fillRect(100, 50, 100, 300);

                g.setColor(currentColor == Color.RED ? Color.RED : Color.GRAY);
                g.fillOval(125, 75, 50, 50);

                g.setColor(currentColor == Color.YELLOW ? Color.YELLOW : Color.GRAY);
                g.fillOval(125, 175, 50, 50);

                g.setColor(currentColor == Color.GREEN ? Color.GREEN : Color.GRAY);
                g.fillOval(125, 275, 50, 50);
            }
        };
        lightPanel.setPreferredSize(new Dimension(300, 400));
        lightPanel.setBackground(Color.WHITE);

        redRadioButton = new JRadioButton("Red");
        yellowRadioButton = new JRadioButton("Yellow");
        greenRadioButton = new JRadioButton("Green");

        ButtonGroup group = new ButtonGroup();
        group.add(redRadioButton);
        group.add(yellowRadioButton);
        group.add(greenRadioButton);

        JPanel radioButtonPanel = new JPanel();
        radioButtonPanel.add(redRadioButton);
        radioButtonPanel.add(yellowRadioButton);
        radioButtonPanel.add(greenRadioButton);

        messageField = new JTextField();
        messageField.setEditable(false);
        messageField.setHorizontalAlignment(JTextField.CENTER);

        redRadioButton.addActionListener(this);
        yellowRadioButton.addActionListener(this);
        greenRadioButton.addActionListener(this);

        add(lightPanel, BorderLayout.CENTER);
        add(radioButtonPanel, BorderLayout.SOUTH);
        add(messageField, BorderLayout.NORTH);
        
        setVisible(true);
    }

    public void changeColor(Color color, String message) {
        currentColor = color;
        messageField.setText(message);
        lightPanel.repaint();
    }

    public void actionPerformed(ActionEvent e) {
        Object src = e.getSource();
        if (src == yellowRadioButton) {
            changeColor(Color.YELLOW, "READY!");
        } else if (src == greenRadioButton) {
            changeColor(Color.GREEN, "GO!");
        } else if (src == redRadioButton) {
            changeColor(Color.RED, "STOP!");
        }
    }

    public static void main(String[] args) {
        new TrafficLight();
    }
}
