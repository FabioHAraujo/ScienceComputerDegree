import java.sql.Time;

public class App {
    public static void main(String[] args) {

        Time t1 = new Time(System.currentTimeMillis());

        System.out.println(t1);

        Pessoa p1 = new Pessoa("João", 20, "123.456.789-00");
        Pessoa p2 = new Pessoa("Maria", 30, "987.654.321-00");
        Pessoa p3 = new Pessoa("José", 40, "111.222.333-44");
        Pessoa p4 = new Pessoa("Ana", 50, "555.666.777-88");

        if (p1.maiorQue(p2)) {
            System.out.println(p1.getNome() + " é mais velho(a) que " + p2.getNome());
        } else {
            System.out.println(p1.getNome() + " não é mais velho(a) que " + p2.getNome());
        }

        Programador prog1 = new Programador("Fabio", 200, "123.456.789-00", "Java", 2);
        Programador prog2 = new Programador("Fernanda", 30, "987.654.321-00", "C#", 5);
        Programador prog3 = new Programador("Felipe", 40, "111.222.333-44", "Python", 10);
        Programador prog4 = new Programador("Fernando", 50, "555.666.777-88", "JavaScript", 11);
        
        if(prog4.maiorQue(prog1)){
            System.out.println(prog4.getNome() + " tem mais tempo de experiencia que " + prog1.getNome());
        } else {
            System.out.println(prog4.getNome() + " tem menos tempo de experiencia que " + prog1.getNome());
        }
        
        Time t2 = new Time(System.currentTimeMillis());

        System.out.println(t2);

        if (t1.compareTo(t2) > 0){
            System.out.println("Tempo 1 é maior que tempo 2");
        }
        if (t1.compareTo(t2) == 0){
            System.out.println("iguais");
        }
        else {
            System.out.println("Tempo 2 é maior que tempo 1");
        }
    }
}
