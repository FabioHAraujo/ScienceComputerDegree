import javax.swing.JOptionPane;

public class Teste{
    public static void main(String[] args) {
        String nome = JOptionPane.showInputDialog("Seu nome");
        JOptionPane.showConfirmDialog(null, "O Seu nome é: " + nome + "?");
        
    }

}