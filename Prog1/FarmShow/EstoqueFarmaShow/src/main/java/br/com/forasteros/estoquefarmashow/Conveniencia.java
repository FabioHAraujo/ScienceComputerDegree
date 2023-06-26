/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package br.com.forasteros.estoquefarmashow;

/**
 *
 * @author super
 */
public class Conveniencia extends Produto {
    private String categoria;
    private String validade;

    public Conveniencia(int ID, String nome, String descricao, String fornecedor, String unidade, int quantidade, String categoria, String validade) {
        super(ID, nome, descricao, fornecedor, unidade, quantidade);
        this.categoria = categoria;
        this.validade = validade;
    }

    public String getCategoria() {
        return categoria;
    }

    public void setCategoria(String categoria) {
        this.categoria = categoria;
    }

    public String getValidade() {
        return validade;
    }

    public void setValidade(String validade) {
        this.validade = validade;
    }
}