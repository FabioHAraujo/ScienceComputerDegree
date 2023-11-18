

import javax.swing.JOptionPane;
import javax.swing.JTextArea;

/**
 * Metodo: Merge Sort
 * Familia: Intercalação
 * 
 * @author Turma de Estrutura de Dados II
 * @author Professor Ricardo Ferreira de Oliveira
 *
 */

public class MergeSort {
	
	public static int [] vetor  = new int[ 16 ];
	public static int [] vetorAuxiliar  = new int[ 16 ];
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
		acumulaPasso( "Inicio" );
		
		mergeSort( vetor, vetorAuxiliar, 0, vetor.length-1 );
		
  		acumulaPasso( "Fim" );
		numeroPasso++;
		
		exibePassos();
		exibeVetor( "Vetor Ordenado: " );
	}
	
	public static void mergeSort(int[] vetor, int n ) {
		
	}
	
	/* 
	 * int [] x     ===== vetor a ser ordenado 
	 * int [] xTemp ===== vetor auxiliar de mesmo tamanho ( obs: precisa ser inicializado ) 
	 * int esq      ===== posição inicial, ou seja, 0 
	 * int dir      ===== posição final , x.length -1 
	 */  
    public static void mergeSort(int [] x,int [] xTemp, int esq, int dir)  
    {  
    	
  			acumulaPasso( "merge( vetor, vetorAuxiliar, " + esq + ", " + dir + " )" );
  			numeroPasso++;
    	
            if(esq < dir)  
            {  
                    int medio = (esq + dir)/2;  
                    mergeSort(x,xTemp,esq,medio);  
                    mergeSort(x,xTemp,medio+1,dir);  
                    mezclar(x,xTemp,esq,medio+1,dir);  
            }  
    }  
      
    public static void mezclar (int [ ] x,int [ ] xAux,int posEsq, int posDir,int posFin)  
    {  
    	
            int finIzq = posDir - 1;  
            int posAux = posEsq;  
            int numElementos = posFin - posEsq +1;  
            // Busca principal  
            while(posEsq <= finIzq && posDir <= posFin)  
                    if( x[posEsq] < x[posDir] )  
                            xAux[posAux++] = x[posEsq++];  
                    else  
                            xAux[posAux++] = x[posDir++];  
                    // Copia primeira metade  
                    while (posEsq <= finIzq)  
                            xAux[posAux++] = x[posEsq++];  
                    // Copia segunda metade  
                    while (posDir <= posFin)  
                            xAux[posAux++] = x[posDir++];  
                    // Copia vetor temporário no principal  
                    for(int i = 0; i < numElementos; i++, posFin--)  
                            x[posFin] = xAux[posFin];  
              
    } 
   
	public static void exibePassos() {
		
		JTextArea texto = new JTextArea();
		texto.append( area.toString() );
		JOptionPane.showMessageDialog(null, texto, "Passos", JOptionPane.INFORMATION_MESSAGE );
	}
	
	public static void acumulaPasso( String msg ) {

		area.append( "Passo [ " + numeroPasso + " ] : " );
		for ( int i = 0; i<16; i++ ) {
			area.append( " " + vetor[ i ] );
		}
		area.append( " " );
		area.append( msg );
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