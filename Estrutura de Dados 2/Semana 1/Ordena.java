import java.awt.Image;
import java.awt.Toolkit;
import java.awt.event.ActionListener;

import javax.swing.JCheckBoxMenuItem;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;


public class Ordena extends JFrame {

	OrdenaListener ordenaListener = new OrdenaListener( this );
	
	public Ordena() {
		
		super( "Universidade Feevale - Ordenacoes" );
		
		Image icone = Toolkit.getDefaultToolkit().getImage(getClass().getClassLoader().getResource( "imagens/feevale.png" )); 
		setIconImage(icone); 
		
		this.setJMenuBar( getMenuOrdena() );
		
		setSize( 800, 600 );
		
		setDefaultLookAndFeelDecorated( true );
		
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		
		Ordena a = new Ordena();
        a.setVisible( true );

	}
	

	private JMenuBar getMenuOrdena() {
		
	    JMenuBar menubar = new JMenuBar();

	    JMenu menuOpcoes = new JMenu("Opcoes");
	    menubar.add(menuOpcoes);

	    JMenu menuOrdenacoes = new JMenu("Ordenacoes");
	    menubar.add(menuOrdenacoes);
	    
	    JCheckBoxMenuItem cbBubbleSort    = criaOrdenaItemMenu( "Bubble Sort", "BubbleSort" ); 
	    JCheckBoxMenuItem cbInsertionSort = criaOrdenaItemMenu( "Insertion Sort", "InsertionSort" ); 
	    JCheckBoxMenuItem cbSelectionSort = criaOrdenaItemMenu( "Selection Sort", "SelectionSort" ); 
	    JCheckBoxMenuItem cbComboSort = criaOrdenaItemMenu( "Combo Sort", "ComboSort" ); 
	    JCheckBoxMenuItem cbShellSort = criaOrdenaItemMenu( "Shell Sort", "ShellSort" ); 

	    menuOrdenacoes.add(cbBubbleSort);
	    menuOrdenacoes.add(cbInsertionSort);	    
	    menuOrdenacoes.add(cbSelectionSort);
	    menuOrdenacoes.add(cbComboSort);	    
	    menuOrdenacoes.add(cbShellSort);
	    
	    ordenaListener.setMnBubbleSort( cbBubbleSort );
	    ordenaListener.setMnInsertionSort( cbInsertionSort );
	    ordenaListener.setMnSelectionSort( cbSelectionSort );
	    ordenaListener.setMnComboSort( cbComboSort );
	    ordenaListener.setMnShellSort( cbShellSort );
	    ordenaListener.selecionaBubbleSort();
	    
	    JMenu menuSobre = new JMenu("Sobre");
	    menubar.add(menuSobre);

	    return menubar;
	}
	
	private JCheckBoxMenuItem criaOrdenaItemMenu( String titulo, String acao ) {

		JCheckBoxMenuItem it = new JCheckBoxMenuItem( titulo );
		it.setActionCommand( acao );
		it.addActionListener( ordenaListener );
		
		return it;
	}

}
