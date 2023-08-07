

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

public class RadixSort10 {

	public static int n = 16;
	
	public static int [] vetor  = new int[ n ];
	public static StringBuffer area = new StringBuffer();
	public static int numeroPasso = 1;
	
	public static int numeroDigitos = 3;
	public static int baseNumerica = 10;
	
	public static void main(String[] args) {

		String valorDigitado;
		
		for ( int i=0; i<n; i++ ) {
			valorDigitado = JOptionPane.showInputDialog( "Informe o elemento [" + i + "] : " );
			vetor[ i ] = Integer.parseInt( valorDigitado );
		}
		
		exibeVetor( "Vetor Informado: " );
		
		numeroPasso = 0;
		acumulaPasso();
	
		
		radixSort10( vetor );
		
		numeroPasso++;
  		acumulaPasso();
  		
  		exibePassos();
		exibeVetor( "Vetor Ordenado: " );
	}
	
	
    public static void radixSort10( int[] vetor )
    {  
    		for ( int i=1; i<=numeroDigitos; i++ ) {
    			contagemRadixSort( vetor, i );
    			numeroPasso++;
    	  		acumulaPasso();
    		}
    }

    public static void contagemRadixSort( int[] vetor, int posicaoDigito )
    {  

    	int p;	
    	int[] vetorTemp = new int[ n ];
    	int[] vetorBase = new int[ baseNumerica ];
    	
    	for ( int i=0; i<baseNumerica; i++ ) {
    		vetorBase[i] = 0;
    	}
    	
    	for ( int i=0; i<n; i++ ) {
    		vetorBase[digito( vetor[i], posicaoDigito )] += 1;
    	}
    	
    	// Calculo do offset
    	for ( int i=1; i<baseNumerica; i++ ) {
    		vetorBase[i] += vetorBase[i-1];
    	}
    	
    	for ( int i=0; i<n; i++ ) {
    		p = digito( vetor[i], posicaoDigito );
    		vetorTemp[n-vetorBase[p]] = vetor[i];
    		vetorBase[p] -= 1;
    	}
    		
    	for ( int i=0; i<n; i++ ) {
    		if ( posicaoDigito == numeroDigitos ) {
    			vetor[ n-(i+1) ] = vetorTemp[ i ];
    		} else {
    			vetor[ i ] = vetorTemp[ i ];
    		}
    	}    	
    	
    }
    
    public static int digito( int valor, int posicaoDigito ) {
    	
    	String s = "00000" + valor;
    	String digito = s.substring( s.length() - posicaoDigito, s.length() - posicaoDigito + 1 );
    	System.out.println( s + " " + valor + " " + digito );
    	return Integer.parseInt( digito );
    }
    
	public static void exibePassos() {
		
		JTextArea texto = new JTextArea();
		texto.append( area.toString() );
		JOptionPane.showMessageDialog(null, texto, "Passos", JOptionPane.INFORMATION_MESSAGE );
	}
	
	public static void acumulaPasso() {

		area.append( "Passo [ " + numeroPasso + " ] : " );
		for ( int i = 0; i<n; i++ ) {
			area.append( " " + vetor[ i ] );
		}
		area.append( "\n" );
		
	}
	
	public static void exibeVetor( String mensagem ) {
		
		StringBuffer sb = new StringBuffer();
		
		for ( int i = 0; i<n; i++ ) {
			sb.append( " " + vetor[ i ] );
		}

		JOptionPane.showMessageDialog( null, sb.toString(), mensagem, JOptionPane.INFORMATION_MESSAGE );
	}

}