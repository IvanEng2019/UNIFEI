package SERVIDOR;

/* COM242 - SISTEMAS DISTRIBUIDOS 
   RMI - Exercicio de implementação RMI
         Programa que calcular as coordenadas x e x e retorna os resultados para o cliente.
         Como teste considere a equa��o do 2� grau 2x2 16x 18 = 0.
    Data: 07/09/2020
    Aluno: Ivan Leoni Vilas Boas
*/

import face.InterfaceServidorMat;
import java.rmi.*;
import java.rmi.server.*;

// Classe no servidor que implementa os métodos remotos
public class ServidorMat extends UnicastRemoteObject implements InterfaceServidorMat
{
    public ServidorMat() throws RemoteException
    {
        System.out.println("Novo Servidor instanciado...");
    }
	
    public double x1(double a, double b, double c) throws RemoteException
    {
        System.out.println("Valores recebidos do cliente: a = " + a + ", b = " + b + " e c = " + c);
	return  ((-b + Math.sqrt(delta(a,b,c)))/(2*a));
    }
	
     public double x2(double a, double b, double c) throws RemoteException
    {
        return ((-b - Math.sqrt(delta(a,b,c)))/(2*a));
		
    }
	
    public double delta(double a, double b, double c) throws RemoteException
    {
        return ((b*b) - (4*a*c));
    }	
} 