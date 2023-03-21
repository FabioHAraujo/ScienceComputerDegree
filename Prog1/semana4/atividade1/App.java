import javax.swing.JOptionPane;

public class App {
    public static void main(String[] args) {
        String nome = "";
        String cidade = "";
        int numeroConta = 0;
        nome = JOptionPane.showInputDialog("Seja bem Vindo ao Banco Bom Demaise. Para os devidos Fins, informe seu nome completo");
        JOptionPane.showConfirmDialog(null, "O Seu nome é: " + nome + "?");
        cidade = JOptionPane.showInputDialog("Agora, por gentileza, informe a cidade onde reside:");
        JOptionPane.showConfirmDialog(null, "Confirma a cidade: " + cidade + "?");
        String tempNum = JOptionPane.showInputDialog(null, "Agora Informe Numero da Conta: ");
        numeroConta = Integer.parseInt(tempNum);
        JOptionPane.showConfirmDialog(null, "Confirma a conta: " + numeroConta + "?");

        ContaBancaria c1 = new ContaBancaria();
        Correntista co1 = new Correntista(nome,cidade);
        c1.setCc(co1);
        c1.setNumero(numeroConta);

        numeroConta = c1.getNumero();
        nome = co1.getNome();
        cidade = co1.getEndereco();

        JOptionPane.showConfirmDialog(null,"Por favor, confirme as informacoes:\n" +  "Sua Conta é: " + numeroConta + "\nSeu Nome é: " + nome + "\nSua Cidade é: " + cidade + "?");
    }
}
