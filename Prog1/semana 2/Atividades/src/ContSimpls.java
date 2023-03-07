import java.util.Scanner;

public class ContSimpls {
    public static void main(String[] args) {
        int cont=0;

        Scanner linha = new Scanner(System.in);
        
        System.out.println("Voce é o guarda dessa festa, cabem 20 pessoas, nao deixa lotar, hein!");

        while (cont<20){
            linha.nextLine();
            cont++;
            System.out.println("Ja sao " + cont + " pessoas");
        }
        System.out.println("A FESTA LOTO RAPÁ, VAZA!!!");
    }
}
