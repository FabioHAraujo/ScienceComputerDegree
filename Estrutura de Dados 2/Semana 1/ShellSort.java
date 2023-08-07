

import javax.swing.JOptionPane;
import javax.swing.JTextArea;

/**
 * Metodo: Shell Sort
 * Familia: Insercao
 * 
 * @author Turma de Estrutura de Dados II
 * @author Professor Ricardo Ferreira de Oliveira
 *
 */

public class ShellSort {
	
	public static int [] vetor  = new int[ 16 ];
	public static StringBuffer area = new StringBuffer();
	public static int numeroPasso = 1;
	public static int posicaoEntrada;
	public static int posicaoTentada;
	public static int chave, h;
	
	public static void main(String[] args) {

		String valorDigitado;
		
		for ( int i=0; i<16; i++ ) {
			valorDigitado = JOptionPane.showInputDialog( "Informe o elemento [" + i + "] : " );
			vetor[ i ] = Integer.parseInt( valorDigitado );
		}
		
		exibeVetor( "Vetor Informado: " );
		
		numeroPasso = 1;
		acumulaPasso();
		
		h = 16;
		while ( h >= 1 ) {
			h = h / 2;
			for ( int j=0; j<h; j++ ) {
				insercaoDireta( j, h );
			}
			acumulaPasso();
			numeroPasso++;
		}
		
		exibePassos();
		exibeVetor( "Vetor Ordenado: " );
	}
	
	public static void insercaoDireta( int celulaInicial, int h ) {
		int i;
		
		i = celulaInicial + h;
		while ( i < 16 ) {
			
		    posicaoEntrada = celulaInicial;
	    	posicaoTentada = i - h;
	        chave          = vetor[ i ];
	        
	        while ((posicaoTentada >= celulaInicial) && (posicaoEntrada == celulaInicial)) {
	              // Se chave < Casa Atual 
	              if ( chave < vetor[ posicaoTentada ] ) {
	                // Trago o atual para a direita 
	                vetor[ posicaoTentada+h] = vetor[ posicaoTentada ];
	                // Passo a pesquisar uma casa para a esquerda 
	                posicaoTentada = posicaoTentada - h;
	              } else {
	                // Insiro a direita da casa pesquisada 
	                posicaoEntrada = posicaoTentada + h;
	              }
	        }
	        vetor[ posicaoEntrada ] = chave;
			i = i + h;
		}
	}
	
	public static void exibePassos() {
		
		JTextArea texto = new JTextArea();
		texto.append( area.toString() );
		JOptionPane.showMessageDialog(null, texto, "Passos", JOptionPane.INFORMATION_MESSAGE );
	}
	
	public static void acumulaPasso() {

		area.append( "Passo [ " + numeroPasso + " ] : " );
		for ( int i = 0; i<16; i++ ) {
			area.append( " " + vetor[ i ] );
		}
		area.append( "\n" );
		
	}
	
	public static void exibeVetor( String mensagem ) {
		
		StringBuffer sb = new StringBuffer();
		
		for ( int i = 0; i<16; i++ ) {
			sb.append( " " + vetor[ i ] );
		}

		JOptionPane.showMessageDialog( null, sb.toString(), mensagem, JOptionPane.INFORMATION_MESSAGE );
	}

}