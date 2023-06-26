/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package telas;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.nio.channels.FileChannel;
import javax.swing.JFileChooser;
import javax.swing.JOptionPane;

/**
 *
 * @author Henike
 */
public class TelaBrowser extends javax.swing.JFrame {

    private String dirImg;

    /**
     * Creates new form Browser
     */
    public TelaBrowser() {
        initComponents();
        txtDiretorio.setText(arquivos.getCurrentDirectory().getAbsolutePath());
        arquivos.setCurrentDirectory(null);
        arquivos.setFileFilter(new javax.swing.filechooser.FileFilter() {
            //Filtro, converte as letras em minúsculas antes de comparar
            @Override
            public boolean accept(File f) {
                return f.getName().toLowerCase().endsWith(".jpg")
                        || f.getName().toLowerCase().endsWith(".jpeg")
                        || f.getName().toLowerCase().endsWith(".png")
                        || f.isDirectory();
            }

            //Texto que será exibido para o usuário
            @Override
            public String getDescription() {
                return "Arquivos de imagem (*.jpg; *.jpeg; *.png)";
            }
        });
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        corpo = new javax.swing.JPanel();
        arquivos = new javax.swing.JFileChooser();
        txtDiretorio = new javax.swing.JTextField();
        jLabel1 = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);
        setResizable(false);

        arquivos.setApproveButtonText("Abrir");
        arquivos.setCurrentDirectory(new java.io.File("J:\\segmentador2\\src\\segmentador\\grafico\\img"));
        arquivos.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                arquivosActionPerformed(evt);
            }
        });
        arquivos.addPropertyChangeListener(new java.beans.PropertyChangeListener() {
            public void propertyChange(java.beans.PropertyChangeEvent evt) {
                arquivosPropertyChange(evt);
            }
        });

        txtDiretorio.setFont(new java.awt.Font("Tahoma", 0, 12)); // NOI18N
        txtDiretorio.addKeyListener(new java.awt.event.KeyAdapter() {
            public void keyReleased(java.awt.event.KeyEvent evt) {
                txtDiretorioKeyReleased(evt);
            }
        });

        jLabel1.setFont(new java.awt.Font("Tahoma", 1, 12)); // NOI18N
        jLabel1.setText("Diretório:");

        javax.swing.GroupLayout corpoLayout = new javax.swing.GroupLayout(corpo);
        corpo.setLayout(corpoLayout);
        corpoLayout.setHorizontalGroup(
            corpoLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, corpoLayout.createSequentialGroup()
                .addContainerGap(24, Short.MAX_VALUE)
                .addComponent(jLabel1)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(txtDiretorio, javax.swing.GroupLayout.PREFERRED_SIZE, 508, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(15, 15, 15))
            .addGroup(corpoLayout.createSequentialGroup()
                .addContainerGap()
                .addComponent(arquivos, javax.swing.GroupLayout.PREFERRED_SIZE, 0, Short.MAX_VALUE))
        );
        corpoLayout.setVerticalGroup(
            corpoLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(corpoLayout.createSequentialGroup()
                .addGap(14, 14, 14)
                .addGroup(corpoLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(txtDiretorio, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel1))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(arquivos, javax.swing.GroupLayout.DEFAULT_SIZE, 355, Short.MAX_VALUE)
                .addGap(5, 5, 5))
        );

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addComponent(corpo, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addContainerGap())
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(corpo, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );

        pack();
        setLocationRelativeTo(null);
    }// </editor-fold>//GEN-END:initComponents

    private void arquivosActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_arquivosActionPerformed
        // TODO add your handling code here:
        this.setVisible(false);

        if (JFileChooser.APPROVE_SELECTION.equals(evt.getActionCommand())) {
            this.carregaImagem("" + arquivos.getSelectedFile());
            JOptionPane.showMessageDialog(null, "O sistema deve ser reiniciado para as alterações serem aplicadas!");
        }
    }//GEN-LAST:event_arquivosActionPerformed

    private void txtDiretorioKeyReleased(java.awt.event.KeyEvent evt) {//GEN-FIRST:event_txtDiretorioKeyReleased
        String dir = txtDiretorio.getText();
        arquivos.setCurrentDirectory(new File(dir));
    }//GEN-LAST:event_txtDiretorioKeyReleased

    private void arquivosPropertyChange(java.beans.PropertyChangeEvent evt) {//GEN-FIRST:event_arquivosPropertyChange
        txtDiretorio.setText(arquivos.getCurrentDirectory().getAbsolutePath());
    }//GEN-LAST:event_arquivosPropertyChange

    public JFileChooser getJFileChooser() {
        return this.arquivos;
    }

    public String getDirImg() {
        return this.dirImg;
    }

    private void carregaImagem(String diretorio) {
        try {
            FileInputStream origem;
            FileOutputStream destino;

            FileChannel fcOrigem;
            FileChannel fcDestino;

            origem = new FileInputStream(diretorio);//arquivo que você quer copiar
            destino = new FileOutputStream("img\\image.jpg");//onde irá ficar a copia do arquivo

            fcOrigem = origem.getChannel();
            fcDestino = destino.getChannel();

            fcOrigem.transferTo(0, fcOrigem.size(), fcDestino);//copiando o arquivo e salvando no diretório que você escolheu

            origem.close();
            destino.close();
        } catch (FileNotFoundException ex) {
            //Logger.getLogger(TelaInicial.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            //Logger.getLogger(TelaInicial.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    /**
     * @param args the command line arguments
     */

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JFileChooser arquivos;
    private javax.swing.JPanel corpo;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JTextField txtDiretorio;
    // End of variables declaration//GEN-END:variables

}
