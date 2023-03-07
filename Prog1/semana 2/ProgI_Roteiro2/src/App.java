import java.util.Scanner;
//import java.util.*;

public class App {
	public static void main (String args[]){
		Scanner leitor = new Scanner(System.in);
		//variáveis
		int idade;
		String nome;
		String endereco;
		double salario;
		//leitura
		System.out.printf("Informe a sua idade:");
		idade = leitor.nextInt();
		leitor.nextLine(); //limpeza do buffer do teclado
		
		System.out.printf("Informe o seu nome:");
		nome = leitor.nextLine();
		
		System.out.printf("Informe o seu endereco:");
		endereco = leitor.next();
		leitor.nextLine();
		
		System.out.printf("Informe o seu salario:");
		salario = leitor.nextDouble();
		//Verificando...
		System.out.printf("Dados lidos: %s tem %d anos, ganha %.2f, e mora em %s.\n",nome,idade,salario,endereco);
		//Criando objeto
		Atleta a = new Atleta(nome,idade);
		System.out.printf("Dados do Atleta: %s tem %d anos.\n",a.getNome(),a.getIdade());
	}
}