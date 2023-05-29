public class Programador extends Pessoa implements ProgramadorComparavel{
    private String favLanguage;
    private int tempoExp;
    public Programador(String nome, int idade, String cpf, String favLanguage, int tempoExp) {
        super(nome, idade, cpf);
        this.favLanguage = favLanguage;
        this.tempoExp = tempoExp;
    }
    public String getFavLanguage() {
        return favLanguage;
    }
    public void setFavLanguage(String favLanguage) {
        this.favLanguage = favLanguage;
    }
    public int getTempoExp() {
        return tempoExp;
    }
    public void setTempoExp(int tempoExp) {
        this.tempoExp = tempoExp;
    }
    @Override
    public String toString() {
        return super.toString() + " | Programador [Linguagem Favorita= " + favLanguage + ", Tempo de Experiencia=" + tempoExp + "]";
    }
    @Override
    public boolean maiorQue(Programador p) {
        if (this.tempoExp > p.tempoExp)
            return true;
        return false;
    }

    

}
