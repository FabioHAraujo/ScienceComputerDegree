
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class MeClicou2 implements ActionListener
{
	private int numClicks = 0;

	public void actionPerformed(ActionEvent event)
	{
		numClicks++;
		System.out.println("Voce Clicou o Botao Direito " + numClicks + " Vezes");
	}
}