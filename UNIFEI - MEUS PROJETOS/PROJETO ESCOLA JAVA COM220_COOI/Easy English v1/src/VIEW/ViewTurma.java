/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package VIEW;

import CONTROL.ControlProfessor;
import CONTROL.ControlTurma;
import MODEL.ModelProfessor;
import MODEL.ModelTurma;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.DefaultListModel;
import javax.swing.JTextField;

/**
 *
 * @author Bruno
 */
public class ViewTurma extends javax.swing.JFrame {

    private ControlTurma controlTurma;
    private ControlProfessor controlProfessor;
    private ArrayList<ModelProfessor> lstProfessores = new ArrayList();
    private ArrayList<ModelTurma> lstTurmasView = new ArrayList();
    private int iteracoesNaoSalvas = 0;
private DefaultListModel<String> dlmTurmaView = new DefaultListModel<>();
    /**
     * Creates new form ViewTurma
     */
    public ViewTurma(ControlTurma cr) throws Exception {
        this.controlTurma = cr;
        controlProfessor = new ControlProfessor(false);
        lstProfessores = controlProfessor.getLstProfessor();
        System.out.println("Construtor " + lstProfessores.size());
        initComponents();
        populaProfResponsavel();
    }

        private void carregaTurmas() {
        lstTurmasView = controlTurma.getLstTurma();
        dlmTurmaView.clear();
        for (ModelTurma lstTurmaView1 : lstTurmasView) {
            dlmTurmaView.addElement(lstTurmaView1.getCodigo() + ", " + lstTurmaView1.getProfResponsavel().getNome());
        }
        if (lstTurmasView.size() > 0) {
            try {
                carregaLabels(0);
            } catch (Exception ex) {
                jlblStatusVisual.setText(ex.getMessage());
                Logger.getLogger(ViewProfessor.class.getName()).log(Level.SEVERE, null, ex);
            }
        } else {
            jbtnAnterior.setEnabled(false);
            jbtnProx.setEnabled(false);
            dlmTurmaView.addElement("Nenhum professor encontrado");
        }
    }
        
          private void carregaLabels(int index) throws Exception {
        if (index >= lstTurmasView.size() || (index < 0)) {
            throw new Exception("Index fora de limites. [" +index+ "]");
        } else {
            jlblCod.setText(lstTurmasView.get(index).getCodigo());
            jlblSemestre.setText(lstTurmasView.get(index).getSemeste());
            jlblAno.setText("" +lstTurmasView.get(index).getAno());
            jlblMax.setText("" + lstTurmasView.get(index).getMax());
            jlblHorarioView.setText(lstTurmasView.get(index).getHorario());
            jlblCurs.setText(lstTurmasView.get(index).getCurso());
            jlblPeriod.setText(lstTurmasView.get(index).getPeriodo());
            jlblRespons.setText(lstTurmasView.get(index).getProfResponsavel().getNome());
            jlblAtual.setText("" + (1 + index));
            jlblTotal.setText("" + lstTurmasView.size());
            defineProxAnteriorEnable(index);
        }
    }
    
            private void defineProxAnteriorEnable(int index) {
        if (index > 0) {
            jbtnAnterior.setEnabled(true);
        } else {
            jbtnAnterior.setEnabled(false);
        }
        if (index >= (lstTurmasView.size() - 1)) {
            jbtnProx.setEnabled(false);
        } else {
            jbtnProx.setEnabled(true);
        }
    }
    
    public String[] getDadosTurma() {
        String dadosTurma[] = new String[8];
        dadosTurma[0] = getCodigo();
        dadosTurma[1] = getSemestre();
        dadosTurma[2] = getJtxtAno();
        dadosTurma[3] = getJtxtMax();
        dadosTurma[4] = getHorario(0);
        dadosTurma[5] = getCurso();
        dadosTurma[6] = getPeriodo();
        dadosTurma[7] = getProfResponsavel();
        return dadosTurma;
    }
    
    

    public String getProfResponsavel() {
        return jcbbProfResponsavel.getSelectedItem().toString();
    }

    public String getPeriodo() {
        return jcbbPeriodo.getSelectedItem().toString();
    }

    public String getJtxtAno() {
        return jtxtAno.getText();
    }

    public String getJtxtMax() {
        return jtxtMax.getText();
    }

    public String getSemestre() {
        if (jrdbPrimeiro.isSelected()) {
            return "Primeiro";
        }
        return "Segundo";
    }

    private void populaProfResponsavel() {
        System.out.println("popula " + lstProfessores.size());
        jcbbProfResponsavel.removeAllItems();
        if (lstProfessores.size() <= 0) {
            jcbbProfResponsavel.addItem("Nenhum professor econtrado.");
            jlblStatus.setText("Impossivel cadastrar turma sem professor responsavel.");
            jbtnCadastrar.setEnabled(false);
        } else {
            for (int i = 0; i < lstProfessores.size(); i++) {
                if ((lstProfessores.get(i).getAtua().equals(getCurso())) || (lstProfessores.get(i).getAtua().equals("Ambos"))) {
                    jcbbProfResponsavel.addItem("" + lstProfessores.get(i).getNome() + "(" + lstProfessores.get(i).getCpf() + ")");
                }
            }
        }
    }
    
     public void statusArquivo(boolean estado, String message) {
        jbtnSalvar.setEnabled(estado);
        jbtnDescartar.setEnabled(estado);
        jlblStatus.setText(message);
    }

    //identifier serve para definir se o horario retornado é do tipo codigo ou do tipo dados para cadastro. 
    //0 é tipo dados, retornando os nomes completos. 1 é do tipo codigo, retornando apenas o primeiro valor de "DIA" e "PERIODO"
    public String getHorario(int identifier) {
        String horario = "";
        switch (identifier) {
            case 0:
                horario = jcbbDia.getSelectedItem().toString();
                horario += jcbbMatVesNot.getSelectedItem().toString();
                break;
            case 1:
                char dia = '2';
                switch (jcbbDia.getSelectedItem().toString()) {
                    case "Segunda":
                        dia = '2';
                        break;
                    case "Terça":
                        dia = '3';
                        break;
                    case "Quarta":
                        dia = '4';
                        break;
                    case "Quinta":
                        dia = '5';
                        break;
                    case "Sexta":
                        dia = '6';
                        break;
                    case "Sabado":
                        dia = '7';
                        break;
                }
                horario = "" + dia;
                horario += "" + jcbbMatVesNot.getSelectedItem().toString().charAt(0);
                break;
        }

        if (jcbx1.isSelected()) {
            horario = horario + "1";
        }
        if (jcbx2.isSelected()) {
            horario = horario + "2";
        }
        if (jcbx3.isSelected()) {
            horario = horario + "3";
        }
        if (jcbx4.isSelected()) {
            horario = horario + "4";
        }
        if (jcbx5.isSelected()) {
            horario = horario + "5";
        }
        return horario;
    }

    public String getCurso() {
        String curso;
        if (jrdbKids.isSelected()) {
            curso = jrdbKids.getText();
        } else {
            curso = jrdbRegular.getText();
        }
        return curso;
    }

    public String getCodigo() {
        String codigo = "";
        codigo = getHorario(1);
        codigo += getCurso().charAt(0);
        codigo += getPeriodo();
        return codigo;
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jbgpSemestre = new javax.swing.ButtonGroup();
        jbgpCurso = new javax.swing.ButtonGroup();
        buttonGroup1 = new javax.swing.ButtonGroup();
        jtbpTurmaView = new javax.swing.JTabbedPane();
        jpnlVisualizar = new javax.swing.JPanel();
        jpnlContainerTurmaView = new javax.swing.JPanel();
        jlblCodVisual = new javax.swing.JLabel();
        jlblSemestreVisual = new javax.swing.JLabel();
        jlblAnoVisual = new javax.swing.JLabel();
        jlblMaxVisual = new javax.swing.JLabel();
        jlblHorarioVisual = new javax.swing.JLabel();
        jlblCursoVisual = new javax.swing.JLabel();
        jlblPeriodoVisual = new javax.swing.JLabel();
        jlblResponsavelVisual = new javax.swing.JLabel();
        jlblCod = new javax.swing.JLabel();
        jlblSemestre = new javax.swing.JLabel();
        jlblAno = new javax.swing.JLabel();
        jlblMax = new javax.swing.JLabel();
        jlblHorarioView = new javax.swing.JLabel();
        jlblCurs = new javax.swing.JLabel();
        jlblPeriod = new javax.swing.JLabel();
        jlblRespons = new javax.swing.JLabel();
        jbtnAnterior = new javax.swing.JButton();
        jbtnProx = new javax.swing.JButton();
        jlblAtualView = new javax.swing.JLabel();
        jlblAtual = new javax.swing.JLabel();
        jlblTotalView = new javax.swing.JLabel();
        jlblTotal = new javax.swing.JLabel();
        jlblQuantidadeAtual = new javax.swing.JLabel();
        jlblQuantidade = new javax.swing.JLabel();
        jlblStatusVisual = new javax.swing.JLabel();
        jScrollPane1 = new javax.swing.JScrollPane();
        carregaTurmas();
        jlstTodasTurmas = new javax.swing.JList(dlmTurmaView);
        jlblTodasTurmas = new javax.swing.JLabel();
        jpnlContainerAdicionar = new javax.swing.JPanel();
        jpnlContainerDadosTurma = new javax.swing.JPanel();
        jlblCodigoView = new javax.swing.JLabel();
        jlblSemestreView = new javax.swing.JLabel();
        jlblAnoView = new javax.swing.JLabel();
        jlbMax = new javax.swing.JLabel();
        jlblDiaView = new javax.swing.JLabel();
        jlblCodigo = new javax.swing.JLabel();
        jrdbSegundo = new javax.swing.JRadioButton();
        jrdbPrimeiro = new javax.swing.JRadioButton();
        jtxtAno = new javax.swing.JTextField();
        jtxtMax = new javax.swing.JTextField();
        jcbbDia = new javax.swing.JComboBox();
        jcbbMatVesNot = new javax.swing.JComboBox();
        jcbx1 = new javax.swing.JCheckBox();
        jcbx2 = new javax.swing.JCheckBox();
        jcbx3 = new javax.swing.JCheckBox();
        jcbx4 = new javax.swing.JCheckBox();
        jcbx5 = new javax.swing.JCheckBox();
        jbtnCadastrar = new javax.swing.JButton();
        jlblCurso = new javax.swing.JLabel();
        jlblProfResp = new javax.swing.JLabel();
        jcbbProfResponsavel = new javax.swing.JComboBox();
        jrdbKids = new javax.swing.JRadioButton();
        jrdbRegular = new javax.swing.JRadioButton();
        jcbbPeriodo = new javax.swing.JComboBox();
        jlblPeriodoView = new javax.swing.JLabel();
        jlblHorario = new javax.swing.JLabel();
        jlblStatus = new javax.swing.JLabel();
        jbtnSalvar = new javax.swing.JButton();
        jbtnDescartar = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        jtbpTurmaView.setPreferredSize(new java.awt.Dimension(800, 600));

        jlblCodVisual.setText("CODIGO");

        jlblSemestreVisual.setText("SEMESTRE");

        jlblAnoVisual.setText("ANO");

        jlblMaxVisual.setText("CAPACIDADE");

        jlblHorarioVisual.setText("HORARIO");

        jlblCursoVisual.setText("CURSO");

        jlblPeriodoVisual.setText("PERIODO");

        jlblResponsavelVisual.setText("RESPONSAVEL");

        jlblCod.setText("CARREGAR...");

        jlblSemestre.setText("CARREGAR...");

        jlblAno.setText("CARREGAR...");

        jlblMax.setText("CARREGAR...");

        jlblHorarioView.setText("CARREGAR...");

        jlblCurs.setText("CARREGAR...");

        jlblPeriod.setText("CARREGAR...");

        jlblRespons.setText("CARREGAR...");

        jbtnAnterior.setText("ANT");
        jbtnAnterior.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jbtnAnteriorActionPerformed(evt);
            }
        });

        jbtnProx.setText("PROX");
        jbtnProx.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jbtnProxActionPerformed(evt);
            }
        });

        jlblAtualView.setText("ATUAL");

        jlblAtual.setText("0");

        jlblTotalView.setText("TOTAL");

        jlblTotal.setText("0");

        jlblQuantidadeAtual.setText("QUANTIDADE");

        jlblQuantidade.setText("CARREGAR...");

        javax.swing.GroupLayout jpnlContainerTurmaViewLayout = new javax.swing.GroupLayout(jpnlContainerTurmaView);
        jpnlContainerTurmaView.setLayout(jpnlContainerTurmaViewLayout);
        jpnlContainerTurmaViewLayout.setHorizontalGroup(
            jpnlContainerTurmaViewLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jpnlContainerTurmaViewLayout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jpnlContainerTurmaViewLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jpnlContainerTurmaViewLayout.createSequentialGroup()
                        .addComponent(jbtnAnterior)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(jbtnProx)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(jlblAtualView)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(jlblAtual)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jlblTotalView)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(jlblTotal)
                        .addGap(0, 0, Short.MAX_VALUE))
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jpnlContainerTurmaViewLayout.createSequentialGroup()
                        .addGroup(jpnlContainerTurmaViewLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jlblCodVisual)
                            .addComponent(jlblSemestreVisual)
                            .addComponent(jlblAnoVisual)
                            .addComponent(jlblMaxVisual)
                            .addComponent(jlblHorarioVisual)
                            .addComponent(jlblCursoVisual)
                            .addComponent(jlblPeriodoVisual)
                            .addComponent(jlblResponsavelVisual)
                            .addComponent(jlblQuantidadeAtual))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addGroup(jpnlContainerTurmaViewLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jlblQuantidade)
                            .addGroup(jpnlContainerTurmaViewLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                                .addComponent(jlblRespons, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                .addComponent(jlblPeriod, javax.swing.GroupLayout.DEFAULT_SIZE, 139, Short.MAX_VALUE)
                                .addComponent(jlblCurs, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                .addComponent(jlblHorarioView, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                .addComponent(jlblMax, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                .addComponent(jlblSemestre, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                .addComponent(jlblCod, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                .addComponent(jlblAno, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)))))
                .addContainerGap())
        );
        jpnlContainerTurmaViewLayout.setVerticalGroup(
            jpnlContainerTurmaViewLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jpnlContainerTurmaViewLayout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jpnlContainerTurmaViewLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jbtnAnterior)
                    .addComponent(jbtnProx)
                    .addComponent(jlblAtualView)
                    .addComponent(jlblAtual)
                    .addComponent(jlblTotalView)
                    .addComponent(jlblTotal))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addGroup(jpnlContainerTurmaViewLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jlblCodVisual)
                    .addComponent(jlblCod))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(jpnlContainerTurmaViewLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jlblSemestreVisual)
                    .addComponent(jlblSemestre))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(jpnlContainerTurmaViewLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jlblAnoVisual)
                    .addComponent(jlblAno))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(jpnlContainerTurmaViewLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jlblQuantidadeAtual)
                    .addComponent(jlblQuantidade))
                .addGap(7, 7, 7)
                .addGroup(jpnlContainerTurmaViewLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jlblMaxVisual)
                    .addComponent(jlblMax))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(jpnlContainerTurmaViewLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jlblHorarioVisual)
                    .addComponent(jlblHorarioView))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(jpnlContainerTurmaViewLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jlblCursoVisual)
                    .addComponent(jlblCurs))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(jpnlContainerTurmaViewLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jlblPeriodoVisual)
                    .addComponent(jlblPeriod))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(jpnlContainerTurmaViewLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jlblResponsavelVisual)
                    .addComponent(jlblRespons))
                .addGap(27, 27, 27))
        );

        jlblStatusVisual.setText("UTILZE ESSA TELA PARA VISUALIZAR TODAS AS TURMAS NO SISTEMA");

        jlstTodasTurmas.addListSelectionListener(new javax.swing.event.ListSelectionListener() {
            public void valueChanged(javax.swing.event.ListSelectionEvent evt) {
                jlstTodasTurmasValueChanged(evt);
            }
        });
        jScrollPane1.setViewportView(jlstTodasTurmas);
        jlstTodasTurmas.setSelectedIndex(0);

        jlblTodasTurmas.setText("TODAS AS TURMAS");

        javax.swing.GroupLayout jpnlVisualizarLayout = new javax.swing.GroupLayout(jpnlVisualizar);
        jpnlVisualizar.setLayout(jpnlVisualizarLayout);
        jpnlVisualizarLayout.setHorizontalGroup(
            jpnlVisualizarLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jpnlVisualizarLayout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jpnlVisualizarLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(jlblStatusVisual)
                    .addComponent(jpnlContainerTurmaView, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(jlblTodasTurmas)
                    .addComponent(jScrollPane1, javax.swing.GroupLayout.DEFAULT_SIZE, 386, Short.MAX_VALUE))
                .addContainerGap(399, Short.MAX_VALUE))
        );
        jpnlVisualizarLayout.setVerticalGroup(
            jpnlVisualizarLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jpnlVisualizarLayout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jpnlContainerTurmaView, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(10, 10, 10)
                .addComponent(jlblTodasTurmas)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 168, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 61, Short.MAX_VALUE)
                .addComponent(jlblStatusVisual)
                .addContainerGap())
        );

        jtbpTurmaView.addTab("VISUALIZAR", jpnlVisualizar);

        jlblCodigoView.setText("CODIGO");

        jlblSemestreView.setText("SEMESTRE");

        jlblAnoView.setText("ANO");

        jlbMax.setText("CAPACIDADE MAXIMA");

        jlblDiaView.setText("DIA");

        jlblCodigo.setText("CODIGO");

        jbgpSemestre.add(jrdbSegundo);
        jrdbSegundo.setText("SEGUNDO");

        jbgpSemestre.add(jrdbPrimeiro);
        jrdbPrimeiro.setSelected(true);
        jrdbPrimeiro.setText("PRIMEIRO");

        jtxtAno.setText("ANO");

        jtxtMax.setText("CAPACIDADE MAX");

        jcbbDia.setModel(new javax.swing.DefaultComboBoxModel(new String[] { "Segunda", "Terça", "Quarta", "Quinta", "Sexta", "Sabado" }));

        jcbbMatVesNot.setModel(new javax.swing.DefaultComboBoxModel(new String[] { "Matutino", "Vespetino", "Noturno" }));

        jcbx1.setText("1");

        jcbx2.setText("2");

        jcbx3.setText("3");

        jcbx4.setText("4");

        jcbx5.setText("5");

        jbtnCadastrar.setText("CADASTRAR");
        jbtnCadastrar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jbtnCadastrarActionPerformed(evt);
            }
        });

        jlblCurso.setText("CURSO");

        jlblProfResp.setText("RESPONSAVEL");

        jbgpCurso.add(jrdbKids);
        jrdbKids.setSelected(true);
        jrdbKids.setText("Kids");
        jrdbKids.addChangeListener(new javax.swing.event.ChangeListener() {
            public void stateChanged(javax.swing.event.ChangeEvent evt) {
                jrdbKidsStateChanged(evt);
            }
        });

        jbgpCurso.add(jrdbRegular);
        jrdbRegular.setText("Regular");

        jcbbPeriodo.setModel(new javax.swing.DefaultComboBoxModel(new String[] { "1", "2", "3", "4", "5", "6" }));

        jlblPeriodoView.setText("PERIODO");

        jlblHorario.setText("HORARIO");

        jlblStatus.setText("Preencha todos os dados.");

        jbtnSalvar.setText("SALVAR");
        jbtnSalvar.setEnabled(false);
        jbtnSalvar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jbtnSalvarActionPerformed(evt);
            }
        });

        jbtnDescartar.setText("DESCARTAR");
        jbtnDescartar.setEnabled(false);
        jbtnDescartar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jbtnDescartarActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout jpnlContainerDadosTurmaLayout = new javax.swing.GroupLayout(jpnlContainerDadosTurma);
        jpnlContainerDadosTurma.setLayout(jpnlContainerDadosTurmaLayout);
        jpnlContainerDadosTurmaLayout.setHorizontalGroup(
            jpnlContainerDadosTurmaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jpnlContainerDadosTurmaLayout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jpnlContainerDadosTurmaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jpnlContainerDadosTurmaLayout.createSequentialGroup()
                        .addComponent(jlblCodigoView)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(jlblCodigo))
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jpnlContainerDadosTurmaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                        .addGroup(jpnlContainerDadosTurmaLayout.createSequentialGroup()
                            .addGroup(jpnlContainerDadosTurmaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                .addComponent(jlblSemestreView)
                                .addComponent(jlblAnoView)
                                .addComponent(jlbMax)
                                .addComponent(jlblCurso)
                                .addGroup(jpnlContainerDadosTurmaLayout.createSequentialGroup()
                                    .addComponent(jlblDiaView)
                                    .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                    .addComponent(jcbbDia, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                    .addComponent(jcbbMatVesNot, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)))
                            .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                            .addGroup(jpnlContainerDadosTurmaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                                .addGroup(jpnlContainerDadosTurmaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jpnlContainerDadosTurmaLayout.createSequentialGroup()
                                        .addComponent(jrdbPrimeiro)
                                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                        .addComponent(jrdbSegundo))
                                    .addGroup(jpnlContainerDadosTurmaLayout.createSequentialGroup()
                                        .addGroup(jpnlContainerDadosTurmaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                                            .addGroup(jpnlContainerDadosTurmaLayout.createSequentialGroup()
                                                .addComponent(jlblHorario)
                                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                                .addComponent(jcbx1)
                                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                                .addComponent(jcbx2)
                                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                                .addComponent(jcbx3)
                                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                                .addComponent(jcbx4))
                                            .addGroup(jpnlContainerDadosTurmaLayout.createSequentialGroup()
                                                .addComponent(jrdbKids)
                                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                                .addComponent(jrdbRegular)
                                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                                .addComponent(jlblPeriodoView)))
                                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                        .addGroup(jpnlContainerDadosTurmaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                                            .addComponent(jcbbPeriodo, 0, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                            .addComponent(jcbx5, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))))
                                .addGroup(jpnlContainerDadosTurmaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(jtxtMax, javax.swing.GroupLayout.PREFERRED_SIZE, 87, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(jtxtAno, javax.swing.GroupLayout.PREFERRED_SIZE, 87, javax.swing.GroupLayout.PREFERRED_SIZE))))
                        .addGroup(jpnlContainerDadosTurmaLayout.createSequentialGroup()
                            .addComponent(jlblProfResp)
                            .addGap(65, 65, 65)
                            .addComponent(jcbbProfResponsavel, 0, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)))
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jpnlContainerDadosTurmaLayout.createSequentialGroup()
                        .addComponent(jlblStatus, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jbtnDescartar)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(jbtnSalvar)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(jbtnCadastrar)))
                .addContainerGap())
        );
        jpnlContainerDadosTurmaLayout.setVerticalGroup(
            jpnlContainerDadosTurmaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jpnlContainerDadosTurmaLayout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jpnlContainerDadosTurmaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jlblCodigoView)
                    .addComponent(jlblCodigo))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(jpnlContainerDadosTurmaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jlblSemestreView)
                    .addComponent(jrdbSegundo)
                    .addComponent(jrdbPrimeiro))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(jpnlContainerDadosTurmaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jlblAnoView)
                    .addComponent(jtxtAno, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(jpnlContainerDadosTurmaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jlbMax)
                    .addComponent(jtxtMax, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addGroup(jpnlContainerDadosTurmaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jlblDiaView)
                    .addComponent(jcbbDia, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jcbbMatVesNot, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jlblHorario)
                    .addComponent(jcbx1)
                    .addComponent(jcbx2)
                    .addComponent(jcbx3)
                    .addComponent(jcbx4)
                    .addComponent(jcbx5))
                .addGap(18, 18, 18)
                .addGroup(jpnlContainerDadosTurmaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jlblCurso)
                    .addComponent(jrdbKids)
                    .addComponent(jrdbRegular)
                    .addComponent(jcbbPeriodo, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jlblPeriodoView))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(jpnlContainerDadosTurmaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jlblProfResp)
                    .addComponent(jcbbProfResponsavel, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 77, Short.MAX_VALUE)
                .addGroup(jpnlContainerDadosTurmaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jbtnCadastrar)
                    .addComponent(jlblStatus)
                    .addComponent(jbtnSalvar)
                    .addComponent(jbtnDescartar))
                .addContainerGap())
        );

        javax.swing.GroupLayout jpnlContainerAdicionarLayout = new javax.swing.GroupLayout(jpnlContainerAdicionar);
        jpnlContainerAdicionar.setLayout(jpnlContainerAdicionarLayout);
        jpnlContainerAdicionarLayout.setHorizontalGroup(
            jpnlContainerAdicionarLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jpnlContainerAdicionarLayout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jpnlContainerDadosTurma, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(353, Short.MAX_VALUE))
        );
        jpnlContainerAdicionarLayout.setVerticalGroup(
            jpnlContainerAdicionarLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jpnlContainerAdicionarLayout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jpnlContainerDadosTurma, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(226, Short.MAX_VALUE))
        );

        jtbpTurmaView.addTab("CADASTRAR", jpnlContainerAdicionar);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addComponent(jtbpTurmaView, javax.swing.GroupLayout.PREFERRED_SIZE, 800, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(0, 0, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addComponent(jtbpTurmaView, javax.swing.GroupLayout.PREFERRED_SIZE, 600, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(0, 0, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents


    private void jbtnCadastrarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jbtnCadastrarActionPerformed
        try {
            controlTurma.cadTurma();
            iteracoesNaoSalvas++;
            statusArquivo(true, iteracoesNaoSalvas + " alterações NÃO salvas.");
            //set texts null
        } catch (Exception ex) {
            jlblStatus.setText(ex.getMessage());
            Logger.getLogger(ViewTurma.class.getName()).log(Level.SEVERE, null, ex);
        }
    }//GEN-LAST:event_jbtnCadastrarActionPerformed

    private void jrdbKidsStateChanged(javax.swing.event.ChangeEvent evt) {//GEN-FIRST:event_jrdbKidsStateChanged
        populaProfResponsavel();
        if (jrdbKids.isSelected()) {
            jcbbPeriodo.setModel(new javax.swing.DefaultComboBoxModel(new String[]{"1", "2", "3", "4", "5", "6"}));
        } else {
            jcbbPeriodo.setModel(new javax.swing.DefaultComboBoxModel(new String[]{"1", "2", "3", "4", "5", "6", "7", "8"}));
        }
    }//GEN-LAST:event_jrdbKidsStateChanged

    private void jbtnSalvarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jbtnSalvarActionPerformed
        try {
            controlTurma.finalize();
            carregaTurmas();
            statusArquivo(false, iteracoesNaoSalvas + " alterações salvas.");
            iteracoesNaoSalvas = 0;
            jlstTodasTurmas.setSelectedIndex(0);
        } catch (Throwable ex) {
            jlblStatus.setText(ex.getMessage());
            Logger.getLogger(ViewTurma.class.getName()).log(Level.SEVERE, null, ex);
        }
    }//GEN-LAST:event_jbtnSalvarActionPerformed

    private void jbtnDescartarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jbtnDescartarActionPerformed
        try {
            controlTurma.desserializaTurma();
            statusArquivo(false, iteracoesNaoSalvas + " alterações descartadas.");
            iteracoesNaoSalvas = 0;
        } catch (Exception ex) {
            jlblStatus.setText(ex.getMessage());
            Logger.getLogger(ViewTurma.class.getName()).log(Level.SEVERE, null, ex);
        }
    }//GEN-LAST:event_jbtnDescartarActionPerformed

    private void jbtnProxActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jbtnProxActionPerformed
        int index = jlstTodasTurmas.getSelectedIndex() + 1;
        jbtnProx.setEnabled(false);
        jbtnAnterior.setEnabled(false);
        try {
            carregaLabels(index);
            jlstTodasTurmas.setSelectedIndex(index);
        } catch (Exception ex) {
            jlblStatusVisual.setText(ex.getMessage());
            Logger.getLogger(ViewProfessor.class.getName()).log(Level.SEVERE, null, ex);
        }
    }//GEN-LAST:event_jbtnProxActionPerformed

    private void jbtnAnteriorActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jbtnAnteriorActionPerformed
        int index = jlstTodasTurmas.getSelectedIndex() - 1;
        jbtnProx.setEnabled(false);
        jbtnAnterior.setEnabled(false);
        try {
            carregaLabels(index);
            jlstTodasTurmas.setSelectedIndex(index);
        } catch (Exception ex) {
            jlblStatusVisual.setText(ex.getMessage());
            Logger.getLogger(ViewProfessor.class.getName()).log(Level.SEVERE, null, ex);
        }
    }//GEN-LAST:event_jbtnAnteriorActionPerformed

    private void jlstTodasTurmasValueChanged(javax.swing.event.ListSelectionEvent evt) {//GEN-FIRST:event_jlstTodasTurmasValueChanged
        try {
            carregaLabels(jlstTodasTurmas.getSelectedIndex());
            defineProxAnteriorEnable(jlstTodasTurmas.getSelectedIndex());
        } catch (Exception ex) {
            jlblStatusVisual.setText(ex.getMessage());
            Logger.getLogger(ViewTurma.class.getName()).log(Level.SEVERE, null, ex);
        }
    }//GEN-LAST:event_jlstTodasTurmasValueChanged

    /**
     * @param args the command line arguments
     */

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.ButtonGroup buttonGroup1;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.ButtonGroup jbgpCurso;
    private javax.swing.ButtonGroup jbgpSemestre;
    private javax.swing.JButton jbtnAnterior;
    private javax.swing.JButton jbtnCadastrar;
    private javax.swing.JButton jbtnDescartar;
    private javax.swing.JButton jbtnProx;
    private javax.swing.JButton jbtnSalvar;
    private javax.swing.JComboBox jcbbDia;
    private javax.swing.JComboBox jcbbMatVesNot;
    private javax.swing.JComboBox jcbbPeriodo;
    private javax.swing.JComboBox jcbbProfResponsavel;
    private javax.swing.JCheckBox jcbx1;
    private javax.swing.JCheckBox jcbx2;
    private javax.swing.JCheckBox jcbx3;
    private javax.swing.JCheckBox jcbx4;
    private javax.swing.JCheckBox jcbx5;
    private javax.swing.JLabel jlbMax;
    private javax.swing.JLabel jlblAno;
    private javax.swing.JLabel jlblAnoView;
    private javax.swing.JLabel jlblAnoVisual;
    private javax.swing.JLabel jlblAtual;
    private javax.swing.JLabel jlblAtualView;
    private javax.swing.JLabel jlblCod;
    private javax.swing.JLabel jlblCodVisual;
    private javax.swing.JLabel jlblCodigo;
    private javax.swing.JLabel jlblCodigoView;
    private javax.swing.JLabel jlblCurs;
    private javax.swing.JLabel jlblCurso;
    private javax.swing.JLabel jlblCursoVisual;
    private javax.swing.JLabel jlblDiaView;
    private javax.swing.JLabel jlblHorario;
    private javax.swing.JLabel jlblHorarioView;
    private javax.swing.JLabel jlblHorarioVisual;
    private javax.swing.JLabel jlblMax;
    private javax.swing.JLabel jlblMaxVisual;
    private javax.swing.JLabel jlblPeriod;
    private javax.swing.JLabel jlblPeriodoView;
    private javax.swing.JLabel jlblPeriodoVisual;
    private javax.swing.JLabel jlblProfResp;
    private javax.swing.JLabel jlblQuantidade;
    private javax.swing.JLabel jlblQuantidadeAtual;
    private javax.swing.JLabel jlblRespons;
    private javax.swing.JLabel jlblResponsavelVisual;
    private javax.swing.JLabel jlblSemestre;
    private javax.swing.JLabel jlblSemestreView;
    private javax.swing.JLabel jlblSemestreVisual;
    private javax.swing.JLabel jlblStatus;
    private javax.swing.JLabel jlblStatusVisual;
    private javax.swing.JLabel jlblTodasTurmas;
    private javax.swing.JLabel jlblTotal;
    private javax.swing.JLabel jlblTotalView;
    private javax.swing.JList jlstTodasTurmas;
    private javax.swing.JPanel jpnlContainerAdicionar;
    private javax.swing.JPanel jpnlContainerDadosTurma;
    private javax.swing.JPanel jpnlContainerTurmaView;
    private javax.swing.JPanel jpnlVisualizar;
    private javax.swing.JRadioButton jrdbKids;
    private javax.swing.JRadioButton jrdbPrimeiro;
    private javax.swing.JRadioButton jrdbRegular;
    private javax.swing.JRadioButton jrdbSegundo;
    private javax.swing.JTabbedPane jtbpTurmaView;
    private javax.swing.JTextField jtxtAno;
    private javax.swing.JTextField jtxtMax;
    // End of variables declaration//GEN-END:variables
}
