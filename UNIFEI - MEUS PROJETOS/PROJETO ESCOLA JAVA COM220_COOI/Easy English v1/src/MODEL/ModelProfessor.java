/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package MODEL;

import java.io.Serializable;

/**
 *
 * @author Bruno
 */
public class ModelProfessor implements Serializable{
    private String nome;
    private String cpf;
    private String atua;

    public String getAtua() {
        return atua;
    }

    public void setAtua(String atua) {
        this.atua = atua;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getCpf() {
        return cpf;
    }

    public void setCpf(String cpf) {
        this.cpf = cpf;
    }
    
}
