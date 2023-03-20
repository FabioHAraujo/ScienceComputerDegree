public class App {
    public static void main(String args[]){

        Conta c1 = new Conta();

        Conta c2 = new Conta();

        c1.setNumero(31);

        c2.setNumero(38);

        c1.depositar(500);

        c1.transferir(200, c2);

        System.out.printf("Saldo da conta %d: %.2f\n", c1.numero, c1.saldo);

        System.out.printf("Saldo da conta %d: %.2f\n", c2.numero, c2.saldo);

        c1.retirar(30.50);

        c2.retirar(20.34);

        System.out.println("Apos os saques feitos: ");
        
        System.out.printf("Saldo da conta %d: %.2f\n", c1.numero, c1.saldo);

        System.out.printf("Saldo da conta %d: %.2f\n", c2.numero, c2.saldo);
    }
}
