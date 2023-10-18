import java.util.Scanner;

public class  mmc{
    // Algoritmo de Euclides iterativo
    private static int mdc(int a, int b) {
        if (a != b) {
            if (b > a) {
                int aux = b;
                b = a;
                a = aux;
            }
            while (b != 0) {
                int r = a % b;
                a = b;
                b = r;
            }
        }
        return a;
    }

    // Algoritmo do MMC
    private static int mmc(int a, int b) {
        return a * (b / mdc(a, b));
    }

    public static void main(String[] args) {
        char sair = 's';
        Scanner dado = new Scanner(System.in);
        System.out.println(" \nO minimo multiplo comum (MMC) de dois numeros.");

        while (sair == 's') {
            System.out.print(" Entre com o primeiro Numero: ");
            int n1 = dado.nextInt();
            System.out.print(" Entre com o segundo Numero: ");
            int n2 = dado.nextInt();
            System.out.println(" O MMC (" + n1 + " ," + n2 + ") = " + mmc(n1, n2));
            System.out.print(" Se deseja continuar tecle s ou para sair qualquer tecla: ");
            sair = dado.next().charAt(0);
        }

        dado.close();
    }
}
