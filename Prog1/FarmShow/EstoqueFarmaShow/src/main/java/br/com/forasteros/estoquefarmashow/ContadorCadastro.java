/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package br.com.forasteros.estoquefarmashow;

/**
 *
 * @author super
 */
import java.io.Serializable;

public class ContadorCadastro implements Serializable {
    private static final long serialVersionUID = 1L;
    
    private int proximoCadastro;

    public ContadorCadastro(int proximoCadastro) {
        this.proximoCadastro = proximoCadastro;
    }

    public int getProximoCadastro() {
        return proximoCadastro;
    }

    public void setProximoCadastro(int proximoCadastro) {
        this.proximoCadastro = proximoCadastro;
    }
}
