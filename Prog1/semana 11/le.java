import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class ObjFileReader {

    public static void main(String[] args) {
        String filePath = "input.obj";
        
        try (BufferedReader reader = new BufferedReader(new FileReader(filePath))) {
            String line;
            
            while ((line = reader.readLine()) != null) {
                // Processar cada linha do arquivo OBJ
                System.out.println(line);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
