import java.util.Scanner;

////O máximo divisor comum (MDC) corresponde ao produto dos divisores comuns entre dois ou mais números inteiros.
public class mdc {
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

    public static void main(String[] args) {
        char sair = 's';
        Scanner dado = new Scanner(System.in);
        System.out.println(" \n O Maximo Divisor Comum (MDC) de dois numeros.");

        while (sair == 's') {
            System.out.print(" Entre com o primeiro Numero: ");
            int n1 = dado.nextInt();
            System.out.print(" Entre com o segundo Numero: ");
            int n2 = dado.nextInt();
            System.out.println(" O MDC (" + n1 + " , " + n2 + ") = " + mdc(n1, n2));
            System.out.print(" Se deseja continuar tecle s ou para sair qualquer tecla: ");
            sair = dado.next().charAt(0);
        }
        dado.close();
    }
}
