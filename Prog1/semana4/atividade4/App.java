import javax.swing.JOptionPane;

public class App {
	public static void main (String args[]){
		//vari�veis
		int idade;
		String nome;
		String endereco;
		double salario;
		//leitura
        JOptionPane.showMessageDialog(null, "Olá, vamos te registrar na tabela de atletas");
        String tempNum = JOptionPane.showInputDialog(null, "Informe a sua idade:");
        idade = Integer.parseInt(tempNum);
		
		nome = JOptionPane.showInputDialog(null, "Informe seu Nome:");
		
		endereco = JOptionPane.showInputDialog(null, "Inform seu Endereço:");
		
		tempNum = JOptionPane.showInputDialog(null, "Informe seu salário:");
        salario = Double.parseDouble(tempNum);
		//Verificando...
        JOptionPane.showMessageDialog(null, "Dados Lidos do Atleta"  + nome + ":\n" + "Tem " + idade + " Anos de Idade\n" + "Recebe R$" + salario + "\n" +  "e mora em: " + endereco);
		//Criando objeto
		Atleta a = new Atleta(nome,idade);
        JOptionPane.showMessageDialog(null, "Dados do Atleta: " + a.getNome() + " Tem " + a.getIdade() + " Anos de Idade." );
	}
}