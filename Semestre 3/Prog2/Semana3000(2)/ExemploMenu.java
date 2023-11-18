import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class ExemploMenu extends JFrame {
    public static void main(String[] args) {
        ExemploMenu em = new ExemploMenu();
        em.setup();
        em.setVisible(true);
    }

    public void setup() {
        setSize(400, 400);
        setTitle("Exemplo com Menu");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        ActionListener menuArquivoListener = new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        };

        JMenuBar menu = new JMenuBar();
        JMenu arquivo = new JMenu("Arquivo");
        JMenu ajuda = new JMenu("Ajuda");

        JMenuItem abrir = new JMenuItem("Abrir");
        JMenuItem sair = new JMenuItem("Sair");
        JMenuItem sobre = new JMenuItem("Sobre");

        setJMenuBar(menu);
        menu.add(arquivo);
        menu.add(ajuda);

        arquivo.add(abrir);
        arquivo.add(sair);

        ajuda.add(sobre);

        sobre.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JOptionPane.showMessageDialog(
                        ExemploMenu.this,
                        "Exemplo Menus P2",
                        "Exemplo",
                        JOptionPane.INFORMATION_MESSAGE
                );
            }
        });

        abrir.addActionListener(menuArquivoListener);
        sair.addActionListener(menuArquivoListener);
    }
}