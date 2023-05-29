public class Conta implements Comparable<Conta>{
    public Conta(int numero) {
        this.numero = numero;
    }

    private int numero;

    public int getNumero() {
        return numero;
    }

    public void setNumero(int numero) {
        this.numero = numero;
    }

    @Override public String toString() {
        return "Conta{" +
                "numero=" + numero +
                '}';
    }

    @Override
    public int compareTo(Conta o) {
        if (this.numero > o.numero) {
            return 1;
        }
        else {
            if(this.numero < o.numero) {
                return -1;
            }
            else {
                return 0;
            }
        }
    }
}
