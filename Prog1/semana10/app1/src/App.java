import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class App{
    public static void main(String[] args) {
        Conta conta = new Conta(1010);

        Conta conta2 = new Conta(20);

        List<Conta> ListaDeContas = new ArrayList<Conta>();

        ListaDeContas.add(conta);
        ListaDeContas.add(conta2);
        ListaDeContas.add(new Conta(3030));

        System.out.println(ListaDeContas);

        ListaDeContas.remove(2);

        System.out.println(ListaDeContas);

        ListaDeContas.add(new Conta(3030));
        ListaDeContas.add(new Conta(30));

        Collections.sort(ListaDeContas);

        System.out.println(ListaDeContas);
    }
}