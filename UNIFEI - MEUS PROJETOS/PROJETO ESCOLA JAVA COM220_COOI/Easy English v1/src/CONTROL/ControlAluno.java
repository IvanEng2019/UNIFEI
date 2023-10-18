/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package CONTROL;

import MODEL.ModelAluno;
import VIEW.ViewAluno;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.time.LocalDate;
import java.time.Month;
import java.time.Period;
import java.util.ArrayList;
import java.util.Date;

/**
 *
 * @author Bruno
 */
public class ControlAluno {

    private ArrayList<ModelAluno> lstAluno;
    private ViewAluno objViewAluno;
    private ModelAluno objModelAluno;
    private String[] aDadosForm;
    //private ControlProfessor objControlProfessor;
    //private ArrayList<ModelProfessor> lstProfessores = new ArrayList();

    public ControlAluno(boolean chamaView) throws Exception {
        lstAluno = new ArrayList<>();
        desserializaAluno();
        if (chamaView) {
            objViewAluno = new ViewAluno(this);
            objViewAluno.setVisible(true);
        }

    }

    public void cadAluno() throws Exception {
        System.out.println("SIZE>" + lstAluno.size());
        aDadosForm = new String[7];
        aDadosForm = objViewAluno.getDadosAluno();
        boolean camposPreenchidos = true;

        for (int i = 0; i < 4; i++) {
            if (aDadosForm[i].length() <= 0) {
                camposPreenchidos = false;
                break;
            }
        }
        if (Integer.parseInt(aDadosForm[4]) < 18) {
            if ((aDadosForm[5].length() <= 0) || (aDadosForm[6].length() <= 0)) {
                camposPreenchidos = false;
            }
        }
        if (camposPreenchidos) {
            objModelAluno = new ModelAluno();
            objModelAluno.setNome(aDadosForm[0]);
            objModelAluno.setCpf(aDadosForm[1]);
            objModelAluno.setEmail(aDadosForm[2]);
            objModelAluno.setNascimento(aDadosForm[3]);
            objModelAluno.setIdade(Integer.parseInt(aDadosForm[4]));
            if (Integer.parseInt(aDadosForm[4]) < 18) {
                objModelAluno.setResponsavel(aDadosForm[5]);
                objModelAluno.setCpfResponsavel(aDadosForm[6]);
            } else {
                objModelAluno.setResponsavel(null);
                objModelAluno.setCpfResponsavel(null);
            }
            lstAluno.add(objModelAluno);
            System.out.println("SIZE!: " +lstAluno.size());
        } else {
            throw new Exception("Preencha todos os campos.");
        }
    }

    public Period getIdade(String nascimento) throws Exception {
        Period p = null;
        LocalDate today = LocalDate.now();
        int iYear = Integer.parseInt(nascimento.substring(6, 10));
        String iMon = nascimento.substring(3, 5);
        Month mon = Month.JANUARY;
        switch (iMon) {
            case "01":
                mon = Month.JANUARY;
                break;
            case "02":
                mon = Month.FEBRUARY;
                break;
            case "03":
                mon = Month.MARCH;
                break;
            case "04":
                mon = Month.APRIL;
                break;
            case "05":
                mon = Month.MAY;
                break;
            case "06":
                mon = Month.JUNE;
                break;
            case "07":
                mon = Month.JULY;
                break;
            case "08":
                mon = Month.AUGUST;
                break;
            case "09":
                mon = Month.SEPTEMBER;
                break;
            case "10":
                mon = Month.OCTOBER;
                break;
            case "11":
                mon = Month.NOVEMBER;
                break;
            case "12":
                mon = Month.DECEMBER;
                break;
            default:
                mon = Month.JANUARY;
                break;
        }
        int iDay = Integer.parseInt(nascimento.substring(0, 2));
        LocalDate birthday = LocalDate.of(iYear, mon, iDay);
        p = Period.between(birthday, today);
        System.out.println("DIA>" + iDay + "MES>" + mon + "ANO> " + iYear);
        if (p.getYears() <= 0) {
            throw new Exception("Nascimento inválido.");
        } else {
            return p;
        }
    }

    public ArrayList<ModelAluno> getLstAluno() {
        return lstAluno;
    }

    public void desserializaAluno() throws Exception {
        File oflAlunoLoad = new File("alunos.dat");
        if (oflAlunoLoad.exists()) {
            FileInputStream oflAlunoLoadIS = new FileInputStream("alunos.dat");
            ObjectInputStream objIS = new ObjectInputStream(oflAlunoLoadIS);
            lstAluno = (ArrayList) objIS.readObject();
            objIS.close();
        }

    }

    private void serializaAluno() throws Exception {
        FileOutputStream oflAlunoSave = new FileOutputStream("alunos.dat");
        ObjectOutputStream objOS = new ObjectOutputStream(oflAlunoSave);
        objOS.writeObject(lstAluno);
        objOS.flush();
        objOS.close();
    }

    public void finalize() throws Exception {
        serializaAluno();
    }
}
