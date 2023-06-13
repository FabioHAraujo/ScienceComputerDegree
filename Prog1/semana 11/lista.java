import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class ListaRamais {
    private List<Ramal> ramais;

    public ListaRamais() {
        ramais = new ArrayList<>();
    }

    public void adicionarRamal(Ramal ramal) {
        ramais.add(ramal);
        System.out.println("Ramal adicionado: " + ramal);
    }

    public void editarRamal(int indice, Ramal novoRamal) {
        if (indice >= 0 && indice < ramais.size()) {
            ramais.set(indice, novoRamal);
            System.out.println("Ramal editado: " + novoRamal);
        } else {
            System.out.println("Índice inválido.");
        }
    }

    public void excluirRamal(int indice) {
        if (indice >= 0 && indice < ramais.size()) {
            Ramal ramalRemovido = ramais.remove(indice);
            System.out.println("Ramal removido: " + ramalRemovido);
        } else {
            System.out.println("Índice inválido.");
        }
    }

    public void lerRamais() {
        System.out.println("Lista de Ramais:");
        for (int i = 0; i < ramais.size(); i++) {
            System.out.println(i + ": " + ramais.get(i));
        }
    }

    public static void main(String[] args) {
        ListaRamais listaRamais = new ListaRamais();
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.println("Escolha uma opção:");
            System.out.println("1. Adicionar ramal");
            System.out.println("2. Editar ramal");
            System.out.println("3. Excluir ramal");
            System.out.println("4. Ler ramais");
            System.out.println("0. Sair");

            int opcao = scanner.nextInt();

            if (opcao == 0) {
                break;
            }

            switch (opcao) {
                case 1:
                    System.out.print("Digite o número do ramal: ");
                    int numero = scanner.nextInt();
                    scanner.nextLine(); // Limpar o buffer
                    System.out.print("Digite o nome do usuário: ");
                    String usuario = scanner.nextLine();
                    Ramal ramal = new Ramal(numero, usuario);
                    listaRamais.adicionarRamal(ramal);
                    break;
                case 2:
                    System.out.print("Digite o índice do ramal a ser editado: ");
                    int indice = scanner.nextInt();
                    scanner.nextLine(); // Limpar o buffer
                    System.out.print("Digite o novo número do ramal: ");
                    int novoNumero = scanner.nextInt();
                    scanner.nextLine(); // Limpar o buffer
                    System.out.print("Digite o novo nome do usuário: ");
                    String novoUsuario = scanner.nextLine();
                    Ramal novoRamal = new Ramal(novoNumero, novoUsuario);
                    listaRamais.editarRamal(indice, novoRamal);
                    break;
                case 3:
                    System.out.print("Digite o índice do ramal a ser excluído: ");
                    int indiceExclusao = scanner.nextInt();
                    listaRamais.excluirRamal(indiceExclusao);
                    break;
                case 4:
                    listaRamais.ler
Ramais();
break;
default:
System.out.println("Opção inválida.");
}
}

go
Copy code
    System.out.println("Encerrando o programa.");
    scanner.close();
}
}

arduino
Copy code

Aqui está a classe `Ramal` que representa um ramal:

```java
public class Ramal {
    private int numero;
    private String usuario;

    public Ramal(int numero, String usuario) {
        this.numero = numero;
        this.usuario = usuario;
    }

    public int getNumero() {
        return numero;
    }

    public void setNumero(int numero) {
        this.numero = numero;
    }

    public String getUsuario() {
        return usuario;
    }

    public void setUsuario(String usuario) {
        this.usuario = usuario;
    }

    @Override
    public String toString() {
        return "Ramal{" +
                "numero=" + numero +
                ", usuario='" + usuario + '\'' +
                '}';
    }
}