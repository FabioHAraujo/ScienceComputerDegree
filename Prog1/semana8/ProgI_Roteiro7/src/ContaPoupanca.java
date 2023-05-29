
public class ContaPoupanca extends Conta implements Investimento {
	
	private int diaAbertura;
	
	public ContaPoupanca(int codigo, int diaAbertura){
		super(codigo);
		this.diaAbertura = diaAbertura; 
	}

	public void exibeTipo(char formato){
		if (formato == 's')
			System.out.println("Conta Poupan�a: " + getCodigo());
		else System.out.println("Conta Poupan�a: " + getCodigo() + " data: " + diaAbertura);
	}
	
	public void calculaJuros() {
		System.out.println("Sua poupan�a rende: " + Investimento.GANHOS);
	}
}
