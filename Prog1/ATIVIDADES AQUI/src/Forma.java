abstract class Forma {
    public abstract String getDescricao();
}

abstract class FormaTridimensional extends Forma {
    public abstract double getAreaSuperficie();
    public abstract double getVolume();
}

class Circulo extends FormaBidimensional {
    private double raio;

    public Circulo(double raio) {
        this.raio = raio;
    }

    @Override
    public double getArea() {
        return Math.PI * raio * raio;
    }

    @Override
    public String getDescricao() {
        return "Circulo com raio: " + raio;
    }
}

class Esfera extends FormaTridimensional {
    private double raio;

    public Esfera(double raio) {
        this.raio = raio;
    }

    @Override
    public double getAreaSuperficie() {
        return 4 * Math.PI * raio * raio;
    }

    @Override
    public double getVolume() {
        return (4.0 / 3.0) * Math.PI * Math.pow(raio, 3);
    }

    @Override
    public String getDescricao() {
        return "Esfera com raio: " + raio;
    }
}

class Quadrado extends FormaBidimensional {
    private double lado;

    public Quadrado(double lado) {
        this.lado = lado;
    }

    @Override
    public double getArea() {
        return lado * lado;
    }

    @Override
    public String getDescricao() {
        return "Quadrado com lado: " + lado;
    }
}

class Triangulo extends FormaBidimensional {
    private double lado;

    public Triangulo(double lado) {
        this.lado = lado;
    }

    @Override
    public double getArea() {
        return lado * lado;
    }

    @Override
    public String getDescricao() {
        return "Quadrado com lado: " + lado;
    }
}