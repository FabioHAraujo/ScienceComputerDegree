public class Aluno extends Pessoa {
    
    private String matricula;
    private String curso;

    public Aluno(String nome, String endereco, String matricula, String curso) {
        super(nome, endereco);
        this.matricula = matricula;
        this.curso = curso;
    }

    @Override
    public String imprimeDados() {
        return "Nome: " + super.nome + "\nEndereço: " + super.endereco + "\nCurso: " + curso + "\nMatricula: " + matricula;
    }
}
