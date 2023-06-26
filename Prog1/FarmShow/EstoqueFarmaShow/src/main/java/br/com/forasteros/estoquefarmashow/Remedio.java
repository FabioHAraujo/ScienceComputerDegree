/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package br.com.forasteros.estoquefarmashow;

/**
 *
 * @author super
 */
public class Remedio extends Produto {
    private String dosagem;
    private String fabricante;
    private String tipo;

    public Remedio(int ID, String nome, String descricao, String fornecedor, String unidade, int quantidade, String dosagem, String fabricante, String tipo) {
        super(ID, nome, descricao, fornecedor, unidade, quantidade);
        this.dosagem = dosagem;
        this.fabricante = fabricante;
        this.tipo = tipo;
    }

    public String getDosagem() {
        return dosagem;
    }

    public void setDosagem(String dosagem) {
        this.dosagem = dosagem;
    }

    public String getFabricante() {
        return fabricante;
    }

    public void setFabricante(String fabricante) {
        this.fabricante = fabricante;
    }

    public String getTipo() {
        return tipo;
    }

    public void setTipo(String tipo) {
        this.tipo = tipo;
    }
}
