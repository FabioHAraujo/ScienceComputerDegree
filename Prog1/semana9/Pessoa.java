public class Pessoa implements Comparavel{
    private String nome;
    private int idade;
    private String cpf;

    public Pessoa(String nome, int idade, String cpf) {
        this.nome = nome;
        this.idade = idade;
        this.cpf = cpf;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getIdade() {
        return idade;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }

    public String getCpf() {
        return cpf;
    }

    public void setCpf(String cpf) {
        this.cpf = cpf;
    }

    @Override
    public String toString() {
        return "Pessoa [nome=" + nome + ", idade=" + idade + ", cpf=" + cpf + "]";
    }

    @Override
    /* 
    public boolean maiorQue(Object o) {
        if (o instanceof Pessoa) {
            Pessoa p = (Pessoa) o;
            if (this.idade > p.idade) {
                return true;
            }
        }
        return false;
    }
    Esse é meu
    */
    
    /*Esse é do professor */
    public boolean maiorQue(Object o) {
        if(o instanceof Pessoa && this.idade > ((Pessoa)o).idade){
            return true;
        }
        return false;
    }

    
    
}