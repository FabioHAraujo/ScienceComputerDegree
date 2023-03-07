import java.util.Scanner;

public class Mouse {
    public static void main(String[] args) {
        boolean parada;
        int clicsDir, clicsEsq, aux;
        double x, y;

        Scanner leitor = new Scanner(System.in);

        x=0;
        y=0;
        parada = false;

        while (parada==false){
            x++;
            y++;
            aux = leitor.nextInt();
            while (aux==0){
                parada = true;
            }
            System.out.println(parada);
            System.out.println(x);
            System.out.println(y);
        }
    }
}
