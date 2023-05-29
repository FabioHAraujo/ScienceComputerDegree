
public abstract class Conta {

	private double saldo;
	private int codigo;
	
	public Conta(int codigo){
		this.saldo = 0;
		this.codigo = codigo;	
	}

	public int getCodigo(){
		return codigo;
	}
	
	public void exibeTipo(){
		System.out.println("Conta: " + getCodigo());
	}

}
