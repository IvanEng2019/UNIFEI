/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package CONTROL;

import MODEL.ModelProfessor;
import VIEW.ViewProfessor;
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
public class ControlProfessor {

    private ArrayList<ModelProfessor> lstProfessor;
    private ViewProfessor objViewDisciplina;
    private ModelProfessor objModelProfessor;
    private String[] aDadosForm;

    private final String arqProfessores = "arqProf.dat";

    public ControlProfessor(boolean chamaView) throws Exception {
        lstProfessor = new ArrayList<>();
        desserializaProfessor();
        if(chamaView){
            objViewDisciplina = new ViewProfessor(this);
        objViewDisciplina.setVisible(true);
        }
        
    }

    public ArrayList<ModelProfessor> getLstProfessor() {
        return lstProfessor;
    }
    
    public void eraseLst(){
        lstProfessor.clear();
    }

    public void cadProfessor() throws Exception {
        aDadosForm = objViewDisciplina.getDadosProf();

        if ((aDadosForm[0].length() <= 0) || (aDadosForm[1].length() <= 0)) {
            throw new Exception("Campos obrigatorios não preenchidos.");
        } else {
            objModelProfessor = new ModelProfessor();
            objModelProfessor.setNome(aDadosForm[0]);
            objModelProfessor.setCpf(aDadosForm[1]);
            objModelProfessor.setAtua(aDadosForm[2]);
            lstProfessor.add(objModelProfessor);
        }
    }

    public void desserializaProfessor() throws Exception {
        File oflProfLoad = new File("professores.dat");
        if (oflProfLoad.exists()) {
            FileInputStream oflProfLoadIS = new FileInputStream("professores.dat");
            ObjectInputStream objIS = new ObjectInputStream(oflProfLoadIS);
            lstProfessor = (ArrayList) objIS.readObject();
            objIS.close();
        }
            //serializaProfessor();

    }

    private void serializaProfessor() throws Exception {
        FileOutputStream oflProfSave = new FileOutputStream("professores.dat");
        ObjectOutputStream objOS = new ObjectOutputStream(oflProfSave);
        objOS.writeObject(lstProfessor);
        objOS.flush();
        objOS.close();
    }

    public void finalize() throws Exception {
        serializaProfessor();
    }
}
