import java.util.Scanner;

public class Contador {
    public static void main(String[] args) {
        int contagem;

        Scanner quest = new Scanner(System.in);

        contagem=0;

        System.out.println("Voce esta cuidando de uma festa, cabem 10 mil pessoas, nao deixe lotar");

        while (contagem < 10000){
            System.out.println("Quantas pessoas entraram agora?");
            contagem+= quest.nextInt();
            System.out.println("Há " + contagem + " Pessoas Dentro da Festa");
        }
        System.out.println("A festa lotou tendo " + contagem + " pessoas");
    }
}
