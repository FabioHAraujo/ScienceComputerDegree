import javax.swing.JOptionPane;
import java.util.Random;

public class App {
    public static void main(String[] args) {
        int dado = 0, resultado = 0;
        JOptionPane.showMessageDialog(null, "Seja Bem Vindo ao Sorteador de Dados Ultra Pro Top Demais");
        String tempNum = JOptionPane.showInputDialog(null, "Por Favor, o dado que deseja sortear é de quanos numeros?");
        dado = Integer.parseInt(tempNum);
        Random r = new Random();
        resultado  = r.nextInt(dado-0) + 0;
        if (resultado > (resultado/3) || resultado < (resultado-2) ) {
            JOptionPane.showMessageDialog(null, "Seu Resulado Foi: " + resultado + " E Você causou " + resultado + " de dano!!!");
        }
        else if (resultado > (resultado-2)) {
            JOptionPane.showMessageDialog(null, "UAAAAU, UM CRÍTICO! Seu Resulado Foi: " + resultado + " E Você causou " + resultado*2 + " de dano!!!");
        }
        else {
            JOptionPane.showMessageDialog(null, "Seu Resulado Foi: " + resultado + " E Não Surtiu Efeio :( !");
        }
    }
}
