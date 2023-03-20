import java.util.Random;
import java.util.Scanner;

public class Aleatorio {
    public static void main(String[] args) {
        Random r = new Random();
        int min = 0, max = 0;

        Scanner quest = new Scanner(System.in);


        System.out.println("SEJA BEM VINDO AVENTUREIRO, DESEJA JOGAR O DADO DE QUANTOS NUMEROS?");
        max+= quest.nextInt();
        System.out.println("Certo, vamos ver se sua sorte está boa kekekeke");
        int resultado = r.nextInt(max-min) + min;
        if (resultado > (max-2)){
            System.out.println("MALDIÇÃO! VOCÊ CAUSOU DANO CRÍTICO DE: " + resultado);
        }
        else if (resultado > (max/2)){
            System.out.println("SUA SORTE ESTA POR UM FIO!!! SEU RESULTADO FOI: " + resultado);
        }
        else{
            System.out.println("olha só... Que peninha... VOCÊ MORREU! Resultado de: " + resultado);
        }
        System.out.println("");
    }
}
