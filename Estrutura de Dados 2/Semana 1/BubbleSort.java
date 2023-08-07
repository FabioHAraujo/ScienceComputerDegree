import javax.swing.JOptionPane;

/**
 * Metodo: BubbleSort 
 * Familia: Troca
 * 
 * @author Turma de Estrutura de Dados II
 * @author Professor Ricardo Ferreira de Oliveira
 *
 */

public class BubbleSort {

	public static int [] vetor  = new int[ 20 ];
	
	public static void main(String[] args) {

		String valorDigitado;
		
		for ( int i=0; i<20; i++ ) {
			valorDigitado = JOptionPane.showInputDialog( "Informe o elemento [" + i + "] : " );
			vetor[ i ] = Integer.parseInt( valorDigitado );
		}
		
		exibeVetor( "Vetor Informado: ", vetor );

		int aux;
		boolean trocou = true;
		
		while ( trocou ) {
			trocou = false;
			for ( int i=0; i<19; i++ ) {
				if ( vetor[ i ] > vetor[ i+1 ] ) {
					trocou = true;
					aux = vetor[i];
					vetor[i] = vetor[i+1];
					vetor[i+1] = aux;
				}
			}
		}
		
		exibeVetor( "Vetor Ordenado: ", vetor );
	}
	
	public static void exibeVetor( String mensagem, int [] meuVetor ) {
		
		StringBuffer sb = new StringBuffer();
		
		for ( int i = 0; i<20; i++ ) {
			sb.append( " " + vetor[ i ] );
		}

		JOptionPane.showMessageDialog( null, sb.toString(), mensagem, JOptionPane.INFORMATION_MESSAGE );
	}

}
