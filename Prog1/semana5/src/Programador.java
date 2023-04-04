public class Programador extends Funcionario{
    private String codigo;
    private String linguagem;
	
	public Programador(String codigo, String nome, int idade)
	{
		super(nome, idade);
		this.codigo = codigo;
	}

	public String getCod() {
		return codigo;
	}

	public void setCod(String cod) {
		this.codigo = cod;
	}

    public String getLing() {
        return linguagem;
    }

    public void setLing(String ling) {
        this.linguagem = ling;
    }
}
