public class AppTeste {
    public static void main(String[] args) {
        String nome;
        int idade;

        nome = "pastelzinho";
        idade = 12;

        Atleta at = new Atleta(nome, idade);
        System.out.println(at.getNome());
        System.out.println(at.getIdade());
    }
}
