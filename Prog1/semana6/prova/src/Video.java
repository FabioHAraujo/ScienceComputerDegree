import javax.swing.JOptionPane;

public class Video {
    private String titulo;
    private String nomeDoAutor;
    private int visualizacoes;
    private String URL;

    void setTitulo(String Titulo) {
        this.titulo = Titulo;
    }
    String getTitulo() {
        return ("TITULO: " + titulo);
    }


    void setNomeDoAutor(String nomeDoAutor) {
        this.nomeDoAutor = nomeDoAutor;
    }
    String getNomeDoAutor() {
        return ("AUTOR: " + nomeDoAutor);
    }

    int setVisualizacoes(int visualizacoes) {
        this.visualizacoes += visualizacoes;
        return visualizacoes;
    }
    int getVisualizacoes() {
        return visualizacoes;
    }

    boolean setURL(String URL) {
        if(URL.contains("https://www.youtube.com/")){
            this.URL = URL;
            return true;
        } else {
            return false;
        }
    }
    String getURL() {
        return ("URL: " + URL);
    }
}
