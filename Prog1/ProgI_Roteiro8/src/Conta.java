
public class Conta {

	private double saldo;
	private int codigo;
	
	public Conta(int codigo){
		this.saldo = 0;
		this.codigo = codigo;	
	}

	int getCodigo(){
		return codigo;
	}
	
	void exibeTipo(){
		System.out.println("Conta: " + getCodigo());
	}

}
