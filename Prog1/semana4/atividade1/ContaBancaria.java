public class ContaBancaria {
	//atributos
	private int numero;
	private double saldo;
	private Correntista cc;
	
	//construtores
	public ContaBancaria()
	{
		
	}
	
	public ContaBancaria(int numero, double saldo)
	{
		this.numero = numero;
		this.saldo = saldo;
	}
	
	public ContaBancaria(int numero, double saldo, Correntista cc, double limite)
	{
		this.numero = numero;
		this.saldo = saldo;
		this.cc = cc;
	}
	
	public int getNumero()
	{
		return numero;
	}
	
	public double getSaldo()
	{
		return saldo;
	}
	
	public void setNumero(int numero)
	{
		this.numero = numero;
	}
	
	public void depositar(double valor)
	{
		saldo = saldo + valor;
	}
	
	public void retirar(double valor)
	{
		if (valor > saldo)
			System.out.println("Saldo Insuficiente... ");
		else saldo = saldo - valor;
	}
	
	public void transferir(double valor, ContaBancaria cDestino)
	{
		if (valor > saldo)
		{
			System.out.println("Saldo insuficiente...");
		}else{
				saldo = saldo - valor;
				cDestino.depositar(valor);
			 }
	}

	public Correntista getCc() {
		return cc;
	}

	public void setCc(Correntista cc) {
		this.cc = cc;
		// Aciona método do Correntista para atualiza-lo com este objeto
		this.cc.setC(this);
	}
	
	/* Opera��o de Extrato */
	public void extrato() {
		System.out.println(cc.getNome() + " seu saldo � " + saldo);
	}

}
