/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package br.com.forasteros.estoquefarmashow;

/**
 *
 * @author super
 */
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class Usuario implements Serializable {
    private static final long serialVersionUID = 1L;
    
    private static final String ARQUIVO_CONTADOR = "contador.obj";
    
    private String nome;
    private String sobrenome;
    private String email;
    private String usuario;
    private String senha;
    private String cpf;
    private int cadastro;

    public Usuario() {
        this.cadastro = obterProximoCadastro();
    }
    
    private int obterProximoCadastro() {
        try (ObjectInputStream inputStream = new ObjectInputStream(new FileInputStream(ARQUIVO_CONTADOR))) {
            ContadorCadastro contador = (ContadorCadastro) inputStream.readObject();
            int proximoCadastro = contador.getProximoCadastro();
            contador.setProximoCadastro(proximoCadastro + 1);
            salvarContador(contador);
            return proximoCadastro;
        } catch (IOException | ClassNotFoundException e) {
            // Arquivo não encontrado ou erro de leitura
            // Cria um novo objeto ContadorCadastro com o valor inicial e salva no arquivo
            ContadorCadastro contador = new ContadorCadastro(1);
            salvarContador(contador);
            return 1;
        }
    }

    private void salvarContador(ContadorCadastro contador) {
        try (ObjectOutputStream outputStream = new ObjectOutputStream(new FileOutputStream(ARQUIVO_CONTADOR))) {
            outputStream.writeObject(contador);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    
    public static void salvarDados(List<Usuario> usuarios) {
        List<Usuario> usuariosExistente = carregarDados(); // Carregar a lista de usuários existente
        usuariosExistente.addAll(usuarios); // Adicionar os novos usuários à lista existente

        try (ObjectOutputStream outputStream = new ObjectOutputStream(new FileOutputStream("dados.obj"))) {
            outputStream.writeObject(usuariosExistente);
            System.out.println("Dados salvos com sucesso!");
            imprimirDados(usuariosExistente); // Imprimir o conteúdo da lista
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    
    public static void imprimirDados(List<Usuario> usuarios) {
        System.out.println("Conteúdo da lista de usuários:");
        for (Usuario usuario : usuarios) {
            System.out.println(usuario.toString());
        }
    }

    public static List<Usuario> carregarDados() {
        try (ObjectInputStream inputStream = new ObjectInputStream(new FileInputStream("dados.obj"))) {
            return (List<Usuario>) inputStream.readObject();
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
            return new ArrayList<>(); // Retorna uma lista vazia em caso de erro ou arquivo não encontrado
        }
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getSobrenome() {
        return sobrenome;
    }

    public void setSobrenome(String sobrenome) {
        this.sobrenome = sobrenome;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getUsuario() {
        return usuario;
    }

    public void setUsuario(String usuario) {
        this.usuario = usuario;
    }

    public String getSenha() {
        return senha;
    }

    public void setSenha(String senha) {
        this.senha = senha;
    }
    
    public String getCpf() {
        return cpf;
    }

    public void setCpf(String cpf) {
        this.cpf = cpf;
    }

    public int getCadastro() {
        return cadastro;
    }

    public void setCadastro(int cadastro) {
        this.cadastro = cadastro;
    }
    public static boolean excluirUsuario(int cadastro) {
        List<Usuario> usuarios = carregarDados();

        boolean usuarioEncontrado = false;
        Iterator<Usuario> iterator = usuarios.iterator();

        while (iterator.hasNext()) {
            Usuario usuario = iterator.next();
            if (usuario.getCadastro() == cadastro) {
                iterator.remove(); // Remove o usuário encontrado da lista
                usuarioEncontrado = true;
                break; // Sai do loop após encontrar o usuário
            }
        }

        if (usuarioEncontrado) {
            salvarDados(usuarios); // Salva a lista atualizada no arquivo
            return true; // Usuário encontrado e excluído com sucesso
        } else {
            return false; // Usuário não encontrado
        }
    }
}