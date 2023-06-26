/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package br.com.forasteros.estoquefarmashow;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author super
 */
public class Produto {
    private int ID;
    private String nome;
    private String descricao;
    private String fornecedor;
    private String unidade;
    private int quantidade;

    // Construtor
    public Produto(int ID, String nome, String descricao, String fornecedor, String unidade, int quantidade) {
        this.ID = ID;
        this.nome = nome;
        this.descricao = descricao;
        this.fornecedor = fornecedor;
        this.unidade = unidade;
        this.quantidade = quantidade;
    }

    // Getters e Setters
    public int getID() {
        return ID;
    }

    public void setID(int ID) {
        this.ID = ID;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getDescricao() {
        return descricao;
    }

    public void setDescricao(String descricao) {
        this.descricao = descricao;
    }

    public String getFornecedor() {
        return fornecedor;
    }

    public void setFornecedor(String fornecedor) {
        this.fornecedor = fornecedor;
    }

    public String getUnidade() {
        return unidade;
    }

    public void setUnidade(String unidade) {
        this.unidade = unidade;
    }

    public int getQuantidade() {
        return quantidade;
    }

    public void setQuantidade(int quantidade) {
        this.quantidade = quantidade;
    }
    
    public static List<Produto> carregarProdutos() {
        try (ObjectInputStream inputStream = new ObjectInputStream(new FileInputStream("dados.obj"))) {
            return (List<Produto>) inputStream.readObject();
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
            return new ArrayList<>(); // Retorna uma lista vazia em caso de erro ou arquivo não encontrado
        }
    }
}
