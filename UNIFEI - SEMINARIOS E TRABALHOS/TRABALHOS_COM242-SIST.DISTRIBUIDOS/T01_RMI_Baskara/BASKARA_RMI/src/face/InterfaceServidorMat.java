package face;

/* COM242 - SISTEMAS DISTRIBUIDOS 
   RMI - Exercicio de implementação RMI
         Programa que calcular as coordenadas x e x e retorna os resultados para o cliente.
         Como teste considere a equa��o do 2� grau 2x2 16x 18 = 0.
    Data: 07/09/2020
    Aluno: Ivan Leoni Vilas Boas
*/

import java.rmi.*;

// Definição da interface que descreve os objetos remotos que poderao ser acessados pelo cliente
public interface InterfaceServidorMat extends Remote
{
    public double x1(double a, double b, double c) throws RemoteException;
    public double x2(double a, double b, double c) throws RemoteException;
}