
public class ContaPoupanca extends Conta {
	
	private int diaAbertura;
	
	public ContaPoupanca(int codigo, int diaAbertura){
		super(codigo);
		this.diaAbertura = diaAbertura; 
	}

	void exibeTipo(){
		System.out.println("Conta Poupança: " + getCodigo());
	}
}
