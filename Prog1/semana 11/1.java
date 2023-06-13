import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

public class ObjFileWriter {

    public static void main(String[] args) {
        String filePath = "output.obj";
        
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(filePath))) {
            // Escrever as informações do arquivo OBJ
            writer.write("v 0.0 0.0 0.0\n");
            writer.write("v 1.0 0.0 0.0\n");
            writer.write("v 0.0 1.0 0.0\n");
            writer.write("f 1 2 3\n");
            
            System.out.println("Arquivo gravado com sucesso!");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
