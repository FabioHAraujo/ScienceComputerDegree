

import javax.swing.JOptionPane;
import javax.swing.JTextArea;

/**
 * Metodo: Heap Sort
 * Familia: Seleção
 * 
 * @author Turma de Estrutura de Dados II
 * @author Professor Ricardo Ferreira de Oliveira
 *
 */

public class HeapSort {
	
	public static int [] vetor  = new int[ 16 ];
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
		
		heapSort( vetor );
		
  		acumulaPasso();
		numeroPasso++;
		
		exibePassos();
		exibeVetor( "Vetor Ordenado: " );
	}
	
	
    public static void heapSort( int[] vetor )
    {  
        constroiHeapInicial(vetor);
        int n = vetor.length;

  	  	acumulaPasso();
    	numeroPasso++;
        
    	// Percorro o vetor de trás-para-frente
        for (int i = vetor.length - 1; i > 0; i--) 
        { 
        	 acumulaPasso();
        	 numeroPasso++;

        	 // Coloco a maior chave na posição definitiva
        	 // e diminuo o tamanho do vetor a ordenar
        	 troca(vetor, i , 0);
        	 
        	 // Refaço o heap
        	 montaHeap(vetor, 0, --n);
        }
    }

    private static void constroiHeapInicial( int[] vetor )
    { 
        for (int i = vetor.length/2 - 1; i >= 0; i--)
     	   montaHeap(vetor, i , vetor.length );
    }

    private static void montaHeap(int[] vetor, int pos, int n) 
    { 

    	  // Inicialmente, o Maior dos filhos é o filho da esquerda
    	  int maiorDosFilhos = 2 * pos + 1;
    	  int filhoDaDireita = maiorDosFilhos + 1;
    	  
          if (maiorDosFilhos < n)
          { 
             // Se o filho da direita é maior, mudo o maiorDosFilhos 
        	 if ( filhoDaDireita < n && vetor[maiorDosFilhos] < vetor[filhoDaDireita])
            	 maiorDosFilhos = filhoDaDireita;
             
        	 // Se o maiorDosFilhos > nodo pai troco ele e recalculo o heap do maiorDosFilhos
             if (vetor[maiorDosFilhos] > vetor[pos]) 
             { 
                troca(vetor, maiorDosFilhos, pos);
                montaHeap(vetor, maiorDosFilhos, n);
             }
          }
    }

    public static void troca ( int[ ] v, int j, int aposJ )
    {
       int aux = v [ j ];
       v [ j ] = v [ aposJ ];
       v [ aposJ ] = aux;
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