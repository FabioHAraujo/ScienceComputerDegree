public class Main {
    private static final int TAM = 3;
    public static void main(String[] args) {
        Forma[] formas = new Forma[TAM];
        formas[0] = new Circulo(3);
        formas[1] = new Esfera(4);
        formas[2] = new Quadrado(5);

        for (Forma forma : formas) {
            System.out.println(forma.getDescricao());
            if (forma instanceof FormaBidimensional) {
                System.out.println("Area: " + ((FormaBidimensional) forma).getArea());
            } else if (forma instanceof FormaTridimensional) {
                System.out.println("Area da superfície: " + ((FormaTridimensional) forma).getAreaSuperficie());
                System.out.println("Volume: " + ((FormaTridimensional) forma).getVolume());
            }
            System.out.println();
        }
    }
}