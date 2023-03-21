public class Mensageiro {
    public String msg = "";

    public void receberMensagem(String msg) {
		this.msg = msg;
	}

    public void setDestino(Mensageiro temp){
        temp.msg=msg;
    }

    public void enviarMensagem(){
        String enviada = msg;
        msg = temp;
        enviada = temp;
    }


}
