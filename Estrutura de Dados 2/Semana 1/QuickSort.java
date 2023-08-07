

import javax.swing.JOptionPane;
import javax.swing.JTextArea;

/**
 * Metodo: Quick Sort
 * Familia: Troca
 * 
 * @author Turma de Estrutura de Dados II
 * @author Professor Ricardo Ferreira de Oliveira
 *
 */

public class QuickSort {
	
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
		
		// 
		quickSort( vetor, 0, vetor.length - 1 );
		
  		acumulaPasso();
		numeroPasso++;
		
		exibePassos();
		exibeVetor( "Vetor Ordenado: " );
	}
	
	public static void quickSort(int[] vetor, int inicio, int fim) {
		
		int posicaoPivo;
		
	    if (inicio < fim) {
	  		acumulaPasso();
			numeroPasso++;

	    	posicaoPivo = particiona2(vetor, inicio, fim);
		    quickSort(vetor, inicio, posicaoPivo - 1);
		    quickSort(vetor, posicaoPivo + 1, fim); 
		}
	}
	
	// Este método particiona todos os elementos criando 3 segmentos de dados: 
	// 1) o pivo
	// 2) os elementos menores que o pivo
	// 3) os elementos maiores do que o pivo
	// Se um elemento já está no segmento correto, move o ponteiro (i ou f).
	// Caso contrário, troca-se os elementos inicial e final
	public static int particiona(int[] vetor, int inicio, int fim) {
		
	      int pivo = vetor[inicio];
	      int i = inicio + 1; 
	      int f = fim;
	      
	      while (i <= f) {
	         if (vetor[i] <= pivo) 
	            i++;
	         else if (pivo < vetor[f])
	            f--;
	         else {
	            int troca = vetor[i];
	            vetor[i] = vetor[f];
	            vetor[f] = troca;
	            i++;
	            f--;
	         }
	      }
	      
	      vetor[inicio] = vetor[f];
	      vetor[f] = pivo;
	      
	      return f;
	}

	// Este método particiona todos os elementos criando 3 segmentos de dados: 
	// 1) o pivo
	// 2) os elementos menores que o pivo
	// 3) os elementos maiores do que o pivo
	// Se um elemento já está no segmento correto, move o ponteiro (i ou f).
	// Caso contrário, troca-se os elementos inicial e final
	public static int particiona2(int[] vetor, int inicio, int fim) {
		
	      int pivo = vetor[inicio];
	      int i = inicio; 
	      int f = fim;
	      boolean esquerda = true;
	      int k;
	      
	      while (i < f) {
	    	 if ( esquerda ) {
	    		 if ( pivo >= vetor[ f ]) {
	    			 vetor[i] = vetor[f];
	    			 i++;
	    			 esquerda = false;
	    		 } else 
	    			 f--;
	    	 } else {
	    		 if ( pivo < vetor[i] ) {
	    			 vetor[f] = vetor[i];
	    			 f--;
	    			 esquerda = true;
	    		 } else 
	    			 i++;
	    	 }
	      }
	      
	      k = i;
	      vetor[k] = pivo;
	      
	      return k;
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