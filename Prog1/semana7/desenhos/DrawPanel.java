import java.awt.Graphics;   
import javax.swing.JPanel;

public class DrawPanel extends JPanel{
    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        int width = getWidth();
        int height = getHeight();
        while (width > 0 && height > 0) {
            g.drawLine(0, 0, width, height);
            g.drawLine(0, height, width, 0);
            width -= 5;
            height -= 30;
        }
    }       
}
