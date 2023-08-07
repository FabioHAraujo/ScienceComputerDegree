
import javax.swing.JOptionPane;
import javax.swing.JTextArea;

/**
 * Metodo: Insertion Sort
 * Familia: Insercao
 * 
 * @author Turma de Estrutura de Dados II
 * @author Professor Ricardo Ferreira de Oliveira
 *
 */

public class InsertionSort {
	
	public static int [] vetor  = new int[ 10 ];
	public static StringBuffer area = new StringBuffer();
	public static int numeroPasso = 1;
	public static int numeroTrocas = 0;
	
	public static void main(String[] args) {

		String valorDigitado;
		
		for ( int i=0; i<10; i++ ) {
			valorDigitado = JOptionPane.showInputDialog( "Informe o elemento [" + i + "] : " );
			vetor[ i ] = Integer.parseInt( valorDigitado );
		}
		
		exibeVetor( "Vetor Informado: " );

		int posicaoEntrada;
		int posicaoTentada;
		int chave;
		
		numeroPasso = 1;
		acumulaPasso();
		
		for ( int i=1; i<10; i++ ) {
			
		    posicaoEntrada = 0;
	    	posicaoTentada = i - 1;
	        chave          = vetor[ i ];

	        while ((posicaoTentada >= 0) && (posicaoEntrada == 0)) {
	              // Se chave < Casa Atual 
	              if ( chave < vetor[ posicaoTentada ] ) {
	                // Trago o atual para a direita 
	                vetor[ posicaoTentada+1] = vetor[ posicaoTentada ];
	                // Passo a pesquisar uma casa para a esquerda 
	                posicaoTentada = posicaoTentada - 1;
	    			numeroTrocas++;
	              } else {
	                // Insiro a direita da casa pesquisada 
	                posicaoEntrada = posicaoTentada + 1;
	              }
	        }
	        // insercao da chave 
	        vetor[ posicaoEntrada ] = chave;
			numeroTrocas++;
			acumulaPasso();
			numeroPasso++;
		}
		exibePassos();
		exibeVetor( "Vetor Ordenado: " );
		JOptionPane.showMessageDialog( null, "Numero de trocas " + numeroTrocas, "Numero de passos " + numeroTrocas, JOptionPane.INFORMATION_MESSAGE );

	}
	
	public static void exibePassos() {
		
		JTextArea texto = new JTextArea();
		texto.append( area.toString() );
		JOptionPane.showMessageDialog(null, texto, "Passos", JOptionPane.INFORMATION_MESSAGE );
	}
	
	public static void acumulaPasso() {

		area.append( "Passo [ " + numeroPasso + " ] : " );
		for ( int i = 0; i<10; i++ ) {
			area.append( " " + vetor[ i ] );
		}
		area.append( "\n" );
		
	}
	
	public static void exibeVetor( String mensagem ) {
		
		StringBuffer sb = new StringBuffer();
		
		for ( int i = 0; i<10; i++ ) {
			sb.append( " " + vetor[ i ] );
		}

		JOptionPane.showMessageDialog( null, sb.toString(), mensagem, JOptionPane.INFORMATION_MESSAGE );
	}

}