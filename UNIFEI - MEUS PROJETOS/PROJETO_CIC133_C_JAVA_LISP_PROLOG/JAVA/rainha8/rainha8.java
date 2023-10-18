public class rainha8 {

    // Função para apresentar a solução ♕
    public static void apresentarTabuleiro(boolean tabuleiro[][]) {
        int i, j;
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                if (tabuleiro[i][j]) {
                    // Rainha
                    System.out.print("  R");
                } else {// demais posições vagas do tabuleiro
                    System.out.print("  X");
                }
            }
            System.out.print("\n\n");
        }
    }

    // Verificar se a peça esta sendo ameaçada
    public static boolean naoEstaAmeacada(boolean tabuleiro[][], int linha, int coluna) {
        int i, j;
        boolean posicaoBoa = true;

        i = linha - 1;
        while (i >= 0 && posicaoBoa) {
            posicaoBoa = !tabuleiro[i][coluna];
            i--;
        }

        i = linha - 1;
        j = coluna + 1;
        while (i >= 0 && j < 8 && posicaoBoa) {
            posicaoBoa = !tabuleiro[i][j];
            i--;
            j++;
        }

        i = linha - 1;
        j = coluna - 1;
        while (i >= 0 && j >= 0 && posicaoBoa) {
            posicaoBoa = !tabuleiro[i][j];
            i--;
            j--;
        }
        return posicaoBoa;
    }

    // Posicionar a rainha no tabuleiro 8X8 conforme as regras
    public static boolean colocarRainha(boolean tabuleiro[][], int linha) {
        int coluna = 0;
        boolean posicao = false;

        if (linha >= 8) { // parada da recursividade
            return true;
        } else {
            while (coluna < 8 && !posicao) {
                tabuleiro[linha][coluna] = true;// coloca rainha
                // Verificar se a peça não está sendo ameaçada
                if (naoEstaAmeacada(tabuleiro, linha, coluna)) {
                    posicao = colocarRainha(tabuleiro, linha + 1);
                }
                if (!posicao) {// se rainha ameaçada
                    tabuleiro[linha][coluna] = false;// retira rainha
                    coluna++; // passa para próxima coluna
                }
            }
            return posicao;
        }
    }

    public static void main(String[] args) {
        int i, j;
        boolean tabuleiro[][] = new boolean[8][8];

        System.out.print(" Criacao Tabuleiro 8X8\n\n");
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                tabuleiro[i][j] = false;
            }
        }
        apresentarTabuleiro(tabuleiro);

        // Se a 8 rainhas forem colocadas conforme as regras (problema) no tabuleiro 8x8
        if (colocarRainha(tabuleiro, 0)) {
            System.out.print("\n Distribuicao da Rainha no tabuleiro 8X8\n\n");
            apresentarTabuleiro(tabuleiro);
        } else {
            System.out.print("\n Rainha não rearranjada no tabuleiro 8x8.\n");
        }
    }
}
