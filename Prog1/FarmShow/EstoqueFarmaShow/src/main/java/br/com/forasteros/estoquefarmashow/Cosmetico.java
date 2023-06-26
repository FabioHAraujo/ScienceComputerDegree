/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package br.com.forasteros.estoquefarmashow;

/**
 *
 * @author super
 */
public class Cosmetico extends Produto {
    private String marca;
    private String tipoProduto;

    public Cosmetico(int ID, String nome, String descricao, String fornecedor, String unidade, int quantidade, String marca, String tipoProduto) {
        super(ID, nome, descricao, fornecedor, unidade, quantidade);
        this.marca = marca;
        this.tipoProduto = tipoProduto;
    }

    public String getMarca() {
        return marca;
    }

    public void setMarca(String marca) {
        this.marca = marca;
    }

    public String getTipoProduto() {
        return tipoProduto;
    }

    public void setTipoProduto(String tipoProduto) {
        this.tipoProduto = tipoProduto;
    }
}

