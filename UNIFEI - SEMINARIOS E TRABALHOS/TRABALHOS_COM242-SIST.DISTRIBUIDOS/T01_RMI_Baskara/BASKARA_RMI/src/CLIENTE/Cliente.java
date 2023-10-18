package CLIENTE;

/* COM242 - SISTEMAS DISTRIBUIDOS 
   RMI - Exercicio de implementação RMI
         Programa que calcular as coordenadas x e x e retorna os resultados para o cliente.
         Como teste considere a equa��o do 2� grau 2x2 16x 18 = 0.
    Data: 07/09/2020
    Aluno: Ivan Leoni Vilas Boas
*/

import face.InterfaceServidorMat;
import java.rmi.*;
import java.util.Scanner;

public class Cliente
{
	public Cliente()
	{
		System.out.println("Executando Cliente... \n");
		try
		{   // Acessa o servidor de nomes para localização das funções remotas
			msi = (InterfaceServidorMat) Naming.lookup("rmi://localhost/ServidorMat_1");
		}
		catch (Exception e)
		{
			System.out.println("Falhou a execucao do Cliente.\n"+e);				
			System.out.println("Certifique se a aplicacao no servidor esta em execucao.\n");				
			System.exit(0);
		}
	}
	
	public static void main (String[] argv)
	{
		Cliente cli = new Cliente();
		Scanner keyboard = new Scanner(System.in);
		System.out.println("Entre com valores de a e b e c separados por espaco:");
		double a = keyboard.nextDouble();
		double b = keyboard.nextDouble();
                double c = keyboard.nextDouble();                
		System.out.println("");
		
		try
		{   // Cada chamada de uma função remota é uma instância da classe Cliente
			System.out.println(" A Raiz x1= " + cli.rx1(a,b,c));
			System.out.println(" A Raiz x2= " + cli.rx2(a,b,c));

		}
		catch (Exception e)
		{
			System.out.println("Excepção durante chamadas remotas:" +e);
		}
	}

	private InterfaceServidorMat msi; // A interface para o objecto remoto	
	
	// Chamada as funções remotas para realização das operações matemáticas
	public double rx1(double a, double b, double c) throws RemoteException{
		 return msi.x1(a,b,c);	
	}

	public double rx2(double a, double b, double c) throws RemoteException{
		return msi.x2(a,b,c);
	}
}