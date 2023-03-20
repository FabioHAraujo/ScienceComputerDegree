import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class Botoes
{
   private static final int FRAME_WIDTH = 100;
   private static final int FRAME_HEIGHT = 100;

   public static void main(String[] args)
   {
      JFrame frame = new JFrame();
      JPanel panel = new JPanel();

      JButton button1 = new JButton("Botao Esquerdo");
      panel.add(button1);
      JButton button2 = new JButton("Botao Direito");
      panel.add(button2);
      frame.add(panel);

      ActionListener listener = new MeClicou();
      button1.addActionListener(listener);
      ActionListener listener2 = new MeClicou2();
      button2.addActionListener(listener2);



      frame.setSize(FRAME_WIDTH, FRAME_HEIGHT);
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      frame.setVisible(true);
   }
}