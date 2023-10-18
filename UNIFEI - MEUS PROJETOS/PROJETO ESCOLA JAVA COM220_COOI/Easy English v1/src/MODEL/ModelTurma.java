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
public class ModelTurma implements Serializable {
    private String codigo;
    private String semeste;
    private int ano;
    private int qnt;
    private int max;
    private String horario;
    private String curso;
    private String periodo;
    private ModelProfessor profResponsavel;

    public String getCodigo() {
        return codigo;
    }

    public void setCodigo(String codigo) {
        this.codigo = codigo;
    }

    public String getSemeste() {
        return semeste;
    }

    public void setSemeste(String semeste) {
        this.semeste = semeste;
    }

    public int getAno() {
        return ano;
    }

    public void setAno(int ano) {
        this.ano = ano;
    }

    public int getQnt() {
        return qnt;
    }

    public void setQnt(int qnt) {
        this.qnt = qnt;
    }

    
    
    
    public int getMax() {
        return max;
    }

    public void setMax(int max) {
        this.max = max;
    }

    public String getHorario() {
        return horario;
    }

    public void setHorario(String horario) {
        this.horario = horario;
    }

    public String getCurso() {
        return curso;
    }

    public void setCurso(String curso) {
        this.curso = curso;
    }

    public String getPeriodo() {
        return periodo;
    }

    public void setPeriodo(String periodo) {
        this.periodo = periodo;
    }

    public ModelProfessor getProfResponsavel() {
        return profResponsavel;
    }

    public void setProfResponsavel(ModelProfessor profResponsavel) {
        this.profResponsavel = profResponsavel;
    }
    
    
}
