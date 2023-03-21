public class App {
    public static void main(String[] args) {
        Mensageiro rodrigo = new Mensageiro("Rodrigo");
        Mensageiro joao = new Mensageiro("João");
        Mensageiro Ana = new Mensageiro("Ana");


        ana.setDestino(joao);
        joao.setDestino(rodrigo);

        ana.receberMensagem("Hoje não está chovendo");
        ana.enviarMensagem();
        joao.enviarMensagem();
        rodrigo.enviarMensagem();

        println(rodrigo.msg);
    }
}
