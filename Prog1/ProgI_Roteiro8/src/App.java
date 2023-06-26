//Classe que integra o framework de Coleções do Java
import java.util.ArrayList;


public class App {

	public static void main(String args[]){
		int i;
		
		System.out.println("***** Controle de Contas *****\n");
		
		//ArrayList<Tipo de dado> nome = new ArrayList<Tipo de dado>();
		ArrayList<Object> contas = new ArrayList<Object>();
		
		if (contas.isEmpty())
			System.out.printf("Nenhuma conta registrada!\n\n");
		
		contas.add(new Conta(1001));
		contas.add(new ContaEspecial(1002, 950.0));
		contas.add(new ContaPoupanca(1003, 12));
		
		i = contas.size(); //retorna a quantidade de elementos da coleção
		System.out.printf("Quantidade de contas: %d\n", i);
		
		Object x;
		Conta c;
		ContaEspecial ce;
		ContaPoupanca cp;
		
		for (int j = 0; j < i; j++){
			x = contas.get(j);
			if (x instanceof Conta){
				c = (Conta)x;
				c.exibeTipo();
			}
			else {
					if (x instanceof ContaEspecial){
						ce = (ContaEspecial)x;
					    ce.exibeTipo();
					}
					else {
							cp = (ContaPoupanca)x;
					        cp.exibeTipo();
				     	}			
			     }
		}

		Conta poup = (ContaPoupanca)contas.get(2);
		if (contas.contains(poup))
			System.out.printf("\n\nConta %d já existe!\n", poup.getCodigo());
	}
}
