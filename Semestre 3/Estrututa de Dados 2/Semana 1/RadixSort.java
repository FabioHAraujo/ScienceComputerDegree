

import javax.swing.JOptionPane;
import javax.swing.JTextArea;

/**
 * Metodo: Radix Sort
 * Familia: Distribuição
 * 
 * @author Turma de Estrutura de Dados II
 * @author Professor Ricardo Ferreira de Oliveira
 *
 */

public class RadixSort {
	
	public static int [] vetor  = new int[ 16 ];
	public static int [] vetorTemp = new int[ 16 ];
	public static StringBuffer area = new StringBuffer();
	public static int numeroPasso = 1;
	
	// r = log2R
	public static final int r = 8; 
	
	// Radical, ou seja 256
	public static final int R = 1 << 8;
	
	// p=passos de ordenação necessários
	public static final int p = ( 32 + r - 1 )/r;
	
	// contador de passos da ordenação
	public static int [] count = new int[ R ];

	public static int n = 16;
	
	public static void main(String[] args) {

		String valorDigitado;
		
		for ( int i=0; i<16; i++ ) {
			valorDigitado = JOptionPane.showInputDialog( "Informe o elemento [" + i + "] : " );
			vetor[ i ] = Integer.parseInt( valorDigitado );
		}
		
		exibeVetor( "Vetor Informado: " );
		
		numeroPasso = 0;
		acumulaPasso();
		
		radixSort( vetor, vetorTemp );
		
		numeroPasso++;
  		acumulaPasso();
  		
  		exibePassos();
		exibeVetor( "Vetor Ordenado: " );
	}
	
	
    public static void radixSort( int[] vetor, int[] vetorTemp )
    {  

       System.out.println( "Serão exexutados " + p + " passos" );
    	for (int i = 0; i < p; ++i )  
        {
    		numeroPasso++;
      		acumulaPasso();
    		
    		// Zero contadores
    		for ( int j = 0; j < R; ++j ) {
    			count[j] = 0;
    		}
    		for ( int k = 0; k < n; ++k ) {
    			++count[ (vetor[k] >>> (r*i)) & (R-1)];
    			vetorTemp[k] = vetor[k];
    		}
    		int pos = 0;
    		for ( int j=0; j<R; ++j ) {
    			int tmp=pos;
    			pos += count[j];
    			count[j] = tmp;
    		}
    		for (int k = 0; k < n; ++k ) {
    			int j = ( vetorTemp[k] >>> (r*i)) & (R-1);
    			vetor[ count[j]++ ] = vetorTemp[k];
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