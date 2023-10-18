/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package CONTROL;

import MODEL.ModelProfessor;
import MODEL.ModelTurma;
import VIEW.ViewTurma;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;

/**
 *
 * @author Bruno
 */
public class ControlTurma {

    private ArrayList<ModelTurma> lstTurma;
    private ViewTurma objViewTurma;
    private ModelTurma objModelTurma;
    private String[] aDadosForm;
    private ControlProfessor objControlProfessor;
    private ArrayList<ModelProfessor> lstProfessores = new ArrayList();

    public ControlTurma(boolean chamaView) throws Exception {
        lstTurma = new ArrayList<>();
        objControlProfessor = new ControlProfessor(false);
        desserializaTurma();
        if (chamaView) {
            objViewTurma = new ViewTurma(this);
            objViewTurma.setVisible(true);
        }

    }
    
    public ArrayList<ModelTurma> getLstTurma(){
        return lstTurma;
    }

    public void cadTurma() throws Exception {
        System.out.println("SIZE>" +lstTurma.size());
        aDadosForm = new String[8];
        aDadosForm = objViewTurma.getDadosTurma();
        lstProfessores = objControlProfessor.getLstProfessor();
        boolean profEncontrado = false;
        int indexProf = 0;
        boolean camposPreenchidos = true;
        
        for (int i = 0; i < 7; i++) {
            if (aDadosForm[i].length() <= 0) {
                camposPreenchidos = false;
                break;
            }
        }
        

        for (int i = 0; i < lstProfessores.size(); i++) {
            if (aDadosForm[7].equals(lstProfessores.get(i).getNome() + "(" + lstProfessores.get(i).getCpf() + ")")) {
                profEncontrado = true;
                indexProf = i;
                break;
            }
        }
        if (!profEncontrado) {
            throw new Exception("Professor não encontrado.");
        } else if ((aDadosForm[0].length() < 5) || !(camposPreenchidos)) {
            throw new Exception("Preencha todos os campos.");
        } else {
            objModelTurma = new ModelTurma();
            objModelTurma.setCodigo(aDadosForm[0]);
            objModelTurma.setSemeste(aDadosForm[1]);
            objModelTurma.setAno(Integer.parseInt(aDadosForm[2]));
            objModelTurma.setMax(Integer.parseInt(aDadosForm[3]));
            objModelTurma.setHorario(aDadosForm[4]);
            objModelTurma.setCurso(aDadosForm[5]);
            objModelTurma.setPeriodo(aDadosForm[6]);
            objModelTurma.setProfResponsavel(lstProfessores.get(indexProf));
            objModelTurma.setQnt(0);
            lstTurma.add(objModelTurma);
            for (int i = 0; i < lstTurma.size(); i++) {
                System.out.println("0000000000000000000000000");
                System.out.println("COD>" + lstTurma.get(i).getCodigo());
                System.out.println("SEMESTRE>" + lstTurma.get(i).getSemeste());
                System.out.println("ANO>" + lstTurma.get(i).getAno());
                System.out.println("MAX>" + lstTurma.get(i).getMax());
                System.out.println("HORARIO>" + lstTurma.get(i).getHorario());
                System.out.println("CURSO>" + lstTurma.get(i).getCurso());
                System.out.println("PERIODO>" + lstTurma.get(i).getPeriodo());
                System.out.println("RESPONSAVEL>" + lstTurma.get(i).getProfResponsavel().getNome());
                System.out.println("11111111111111111111111");
            }
        }
    }

    public void desserializaTurma() throws Exception {
        System.out.println("TENTANDO CARREGAR");
        File oflTurmaLoad = new File("turmas.dat");
        if (oflTurmaLoad.exists()) {
            FileInputStream oflTurmaLoadIS = new FileInputStream("turmas.dat");
            ObjectInputStream objIS = new ObjectInputStream(oflTurmaLoadIS);
            lstTurma = (ArrayList) objIS.readObject();
            objIS.close();
        }

    }

    private void serializaTurma() throws Exception {
        System.out.println("TENTANDO SALVAR!");
        FileOutputStream oflTurmaSave = new FileOutputStream("turmas.dat");
        ObjectOutputStream objOS = new ObjectOutputStream(oflTurmaSave);
        objOS.writeObject(lstTurma);
        objOS.flush();
        objOS.close();
    }

    public void finalize() throws Exception {
        serializaTurma();
    }
}
