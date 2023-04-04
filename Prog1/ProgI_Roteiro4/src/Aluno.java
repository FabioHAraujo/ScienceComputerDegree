public class Aluno extends Pessoa {

	private String matricula;
	
	public Aluno(String matricula, String nome, int idade)
	{
		super(nome, idade);
		this.matricula = matricula;
	}

	public String getMatricula() {
		return matricula;
	}

	public void setMatricula(String matricula) {
		this.matricula = matricula;
	}
	
	
}
