import javax.swing.JOptionPane;
import javax.swing.JTextArea;

/**
 * Metodo: ShakeSort
 * Familia: Troca
 * 
 * @author Turma de Estrutura de Dados II
 * @author Professor Ricardo Ferreira de Oliveira
 *
 */


public class ShakeSort {
	
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

		int aux;
		numeroPasso = 1;
		int max = 9;
		int min = 0;
		boolean trocou = true;
		
		while ( trocou ) {
			trocou = false;
			for ( int i=min; i<max; i++ ) {
				if ( vetor[ i ] > vetor[ i+1 ] ) {
					trocou = true;
					aux = vetor[i];
					vetor[i] = vetor[i+1];
					vetor[i+1] = aux;
					numeroTrocas++;
				}
			}
			max--;
			acumulaPasso();
			numeroPasso++;

			if ( trocou ) {
				trocou = false;
				for ( int i=max; i>=min; i-- ) {
					if ( vetor[ i ] > vetor[ i+1 ] ) {
						trocou = true;
						aux = vetor[i];
						vetor[i] = vetor[i+1];
						vetor[i+1] = aux;
						numeroTrocas++;
					}
				}
				min++;
				acumulaPasso();
				numeroPasso++;
			}
		
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