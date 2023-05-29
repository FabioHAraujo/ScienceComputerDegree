
public class ContaEspecial extends Conta{

	private double limite;
	
	public ContaEspecial(int codigo, double limite){
		super(codigo);
		this.limite = limite; 
	}
	
	public void exibeTipo(){
		System.out.println("Conta Especial: " + getCodigo());
	}
}
