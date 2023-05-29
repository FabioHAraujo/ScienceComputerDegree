
public class App {

	public static void main(String[] args) {
		ContaEspecial ce = new ContaEspecial(123,1000.00);
		ContaPoupanca cp = new ContaPoupanca(123,12);
		ce.exibeTipo();
		cp.exibeTipo();
		cp.exibeTipo('c');
	}

}
