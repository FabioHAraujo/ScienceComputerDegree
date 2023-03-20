import java.util.Scanner;

public class Conta {
    Scanner quest = new Scanner(System.in);
    public int numero;
    public double saldo;
    public Conta(){    
    }
    public int getNumero() {
          return numero;
    }
    public void retirar(double valor){
        if(saldo-valor>0)
        {
            System.out.printf("Voce Retirou R$ %.2f", valor);
            System.out.printf(" E Seu saldo atual eh: R$ %.2f\n ", saldo);
        }
        else {
            System.out.println("Não ha saldo suficiente");
        }
        
    }
    public void setNumero(int numero) {
          this.numero = numero;
    }
    public double getSaldo() {
          return saldo;
    }
    //método retirar
    public void depositar(double valor){
          saldo = saldo + valor;
    }
    public void transferir(double valor, Conta destino){
          if(saldo>=valor){
                 saldo = saldo - valor;
                 destino.depositar(valor);
          }else System.out.printf("Valor indisponivel!\n");
    }
}