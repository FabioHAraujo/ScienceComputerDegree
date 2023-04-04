import javax.swing.JOptionPane;
import java.util.Random;

public class App {
    public static void main(String[] args) {
        int sort = 100, resultado = 0;
        Random r = new Random();
        resultado  = r.nextInt(sort-0) + 0;
        JOptionPane.showMessageDialog(null, "Seja bem Vindo ao Cadastro de Funcionarios");
        JOptionPane.showMessageDialog(null, "A Matricula do Novo funcionario é: " + resultado);
        Funcionario am = new Funcionario("Nome", 18);
        String tempNome = JOptionPane.showInputDialog(null, "Informe o Nome do Funcionario: ");
        am.setNome(tempNome);
    }
}
