public class Nodo {
    int conteudo;
    Nodo filhoDir;
    Nodo filhoEsq;

    public Nodo(int num) {
        filhoEsq = null;
        filhoDir = null;
        conteudo = num;
    }

    public int getConteudo() {
        return conteudo;
    }
    public void setConteudo(int conteudo) {
        this.conteudo = conteudo;
    }
    public Nodo getFilhoDir() {
        return filhoDir;
    }
    public void setFilhoDir(Nodo filhoDir) {
        this.filhoDir = filhoDir;
    }
    public Nodo getFilhoEsq() {
        return filhoEsq;
    }
    public void setFilhoEsq(Nodo filhoEsq) {
        this.filhoEsq = filhoEsq;
    }
}