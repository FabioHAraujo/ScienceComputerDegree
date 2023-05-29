import javax.swing.JOptionPane;

public class App {
    public static void main(String[] args) {
        JOptionPane.showMessageDialog(null, "Seja bem Vindo ao Youtube, versao Alfa do Alfa do Alfa");
        JOptionPane.showMessageDialog(null, "Voce Eh o Administrador do Sistema, sua missao eh Cadastrar Corretamente os Videos!!!");
        JOptionPane.showMessageDialog(null, "Sempre ao cadastrar um video, devera o Titulo, Nome do Autor, URL e Quantidade de Visualizacoes.\nA URL deve conter o seguinte padrao: https://www.youtube.com/, caso contrario sera rejeiada pelo sistema");
        JOptionPane.showMessageDialog(null, "Agora vamos cadastrar o primeiro video, por favor, tente inserir uma URL INVALIDA, para fins de teste :)");
        Video v1 = new Video();
        String tempTitulo = JOptionPane.showInputDialog(null, "Informe o Titulo do Video: ");
        v1.setTitulo(tempTitulo);
        String tempNome = JOptionPane.showInputDialog(null, "Informe o Nome do Autor: ");
        v1.setNomeDoAutor(tempNome);
        while(v1.setURL(JOptionPane.showInputDialog(null, "Informe a URL do Video: ")) == false){
            JOptionPane.showMessageDialog(null, "URL INVALIDA, por favor, tente novamente");
        }
        v1.setVisualizacoes(Integer.parseInt(JOptionPane.showInputDialog(null, "Informe a Quantidade de Visualizacoes: ")));
        JOptionPane.showMessageDialog(null, "Video Cadastrado com Sucesso!!!");
        JOptionPane.showMessageDialog(null, "INFORMACOES DO VIDEO CADASTRADO\n" + v1.getTitulo() + "\n" + v1.getNomeDoAutor() + "\n" + v1.getURL() + "\n" + "VISUALIZACOES: " + v1.getVisualizacoes());
        Video[] ListaVideos = new Video[100];
        int qtdVideos = (Integer.parseInt(JOptionPane.showInputDialog(null,"Quantos Videos Deseja Cadastrar agora? (infelizmente por ora temos limite de 100 :(")));
        int i = 0;
        for(i=0; i < qtdVideos; i++){
            ListaVideos[i] = new Video();
            tempTitulo = JOptionPane.showInputDialog(null, "Informe o Titulo do Video: ");
            ListaVideos[i].setTitulo(tempTitulo);
            tempNome = JOptionPane.showInputDialog(null, "Informe o Nome do Autor: ");
            ListaVideos[i].setNomeDoAutor(tempNome);
            while(ListaVideos[i].setURL(JOptionPane.showInputDialog(null, "Informe a URL do Video: ")) == false){
                JOptionPane.showMessageDialog(null, "URL INVALIDA, por favor, tente novamente");
            }
            ListaVideos[i].setVisualizacoes(Integer.parseInt(JOptionPane.showInputDialog(null, "Informe a Quantidade de Visualizacoes: ")));
            JOptionPane.showMessageDialog(null, "Video Cadastrado com Sucesso!!!");
        }
        for(i=0; i < qtdVideos; i++){
            JOptionPane.showMessageDialog(null, "INFORMACOES DO VIDEO NUMERO " + (i+1) + "\n" + ListaVideos[i].getTitulo() + "\n" + ListaVideos[i].getNomeDoAutor() + "\n" + ListaVideos[i].getURL() + "\n" + "VISUALIZACOES: " + ListaVideos[i].getVisualizacoes());
        }
        JOptionPane.showMessageDialog(null, "FIM DO PROGRAMA, BOM DESCANSO!!!");
    }
}