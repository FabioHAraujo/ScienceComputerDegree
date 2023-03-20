import java.util.Random;
import java.util.Scanner;

public class Termometro {
    public static void main(String[] args) {
        Random r = new Random();
        int baixa = 35, alta = 42;
        int qtdAlunos = 1;

        Scanner quest = new Scanner(System.in);


        System.out.println("Seja bem Vindo Professor, quantos alunos estao com o senhor?");
        qtdAlunos+= quest.nextInt();
        System.out.println("Certo, vamos medir a temperatura de todos: ");
        for (int i=1; i<qtdAlunos;i++){
            int resultado = r.nextInt(alta-baixa) + baixa;
            System.out.println("A temperatura do Aluno Numero " + i + " É de: " + resultado + "°");
            if (resultado > 39){
                System.out.println("###########################################################################################");
                System.out.println("A temperatura do Aluno Numero " + i + " está alta e nao poderá ser tratada aqui, leve-o ao hospital!!");
                System.out.println("###########################################################################################");
            }
            System.out.println("");
        }
    }
}
