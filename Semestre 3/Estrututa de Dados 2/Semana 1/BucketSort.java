

import javax.swing.JOptionPane;
import javax.swing.JTextArea;

/**
 * Metodo: Bucket Sort
 * Familia: Distribuição
 * 
 * @author Turma de Estrutura de Dados II
 * @author Professor Ricardo Ferreira de Oliveira
 *
 */

public class BucketSort {
	
	public static int [] vetor  = new int[ 16 ];
	public static int [] contadores = new int[ 100 ];
	public static StringBuffer area = new StringBuffer();
	public static int numeroPasso = 1;
	
	public static void main(String[] args) {

		String valorDigitado;
		
		for ( int i=0; i<16; i++ ) {
			valorDigitado = JOptionPane.showInputDialog( "Informe o elemento [" + i + "] : " );
			vetor[ i ] = Integer.parseInt( valorDigitado );
		}
		
		exibeVetor( "Vetor Informado: " );
		
		numeroPasso = 1;
		acumulaPasso();
		
		bucketSort( vetor, contadores );
		
		numeroPasso++;
  		acumulaPasso();
		
		exibePassos();
		exibeVetor( "Vetor Ordenado: " );
	}
	
	
    public static void bucketSort( int[] vetor, int[] contadores )
    {  

       
    	// zero vetor de contadores
    	for (int i = 0; i < contadores.length; i++ )  
        {
    		contadores[i] = 0;
        }
    	// Incremento o contador conforme a 
    	// frequencia do elemento encontrado
    	for (int j = 0; j < vetor.length; j++ )  
        {
    		++contadores[vetor[j]];
        }
    	// Realimento o vetor a medida que 
    	// tenho numeros > 0 nos contadores 
    	for (int i = 0, j=0; i < contadores.length; ++i ) {
    		for ( ; contadores[i] > 0; --contadores[i] ) {
    			vetor[j++] = i;
    		}
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