abstract class Pessoa {
    String nome;
    String endereco;
    public Pessoa(String nome, String endereco) {
        this.nome = nome;
        this.endereco = endereco;
    }

    public abstract String imprimeDados();

}