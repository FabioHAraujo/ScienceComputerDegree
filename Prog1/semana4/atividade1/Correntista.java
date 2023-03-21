public class Correntista {
	public String nome;
	public String endereco;
	private ContaBancaria c;
	
	public Correntista()
	{
		
	}
	
	public Correntista (String nome, String endereco)
	{
		this.nome = nome;
		this.endereco =  endereco;
	}

	public String getEndereco() {
		return endereco;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public void setEndereco(String endereco) {
		this.endereco = endereco;
	}

	public ContaBancaria getC() {
		return c;
	}

	public void setC(ContaBancaria c) {
		this.c = c;
	}

	
}
