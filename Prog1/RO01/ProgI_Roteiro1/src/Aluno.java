
public class Aluno {

	String nome;
	double media;
	
	//construtor
	public Aluno() {
		this.nome = "Paulao";
	}
	
	//construtor
	public Aluno(String nome) {
		this.nome = nome;
	}
	
	//exibir estado
	void exibeEstado() {
		System.out.println("Média do aluno " + nome + " é: " + media);
	}
	
}
