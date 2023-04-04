
public class AlunoUniversitario extends Aluno{
	private String tipo; //bacharel ou tecnologo
	
	public AlunoUniversitario(String tipo, String matricula, String nome, int idade) {
		super(matricula, nome, idade);
		this.tipo = tipo;
	}

	public String getTipo() {
		return tipo;
	}

	public void setTipo(String tipo) {
		this.tipo = tipo;
	}
	
	

}
