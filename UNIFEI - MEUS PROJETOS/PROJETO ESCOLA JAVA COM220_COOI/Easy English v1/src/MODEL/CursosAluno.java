/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package MODEL;

/**
 *
 * @author Bruno
 */
public class CursosAluno {
    private float n1;
    private float n2;
    private String status;
    private ModelTurma turma;

    public float getN1() {
        return n1;
    }

    public void setN1(float n1) {
        this.n1 = n1;
    }

    public float getN2() {
        return n2;
    }

    public void setN2(float n2) {
        this.n2 = n2;
    }

    public String getStatus() {
        return status;
    }

    public void setStatus(String status) {
        this.status = status;
    }

    public ModelTurma getTurma() {
        return turma;
    }

    public void setTurma(ModelTurma turma) {
        this.turma = turma;
    }
    
    
}
