public class Calculadora {
    public static void main(String[] args) {
        try{
            Scanner in = new Scanner(System.in);

            System.out.print("VALOR A: ");
            int a = in.nextInt();
            in.nextLine();
            System.out.print("OPERADOR: ");
            String o = in.nextLine();
            System.out.print("VALOR B: ");
            int b = in.nextInt();

            switch(o){
                case "+":
                    System.out.println(a+b);
                break;
                case "-":
                    System.out.println(a-b);
                break;
                case "*":
                    System.out.println(a*b);
                break;
                case "/":
                    System.out.println(a/b);
                break;
            }
        } catch (Exception e) {
            System.out.println("ERRO NA LEITURA!")
            //e.printStackTrace();
        }
    }
}