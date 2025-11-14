#include <stdio.h>

int main() {
    int tabuleiro[10][10] = {0}; // Inicializa todo o tabuleiro com 0 (água)
    int tamanhoNavio = 3;        // Tamanho fixo dos navios
    int i;

    // -----------------------------
    // Navio Horizontal
    // -----------------------------
    int h_linha = 1;   // Linha inicial
    int h_coluna = 2;  // Coluna inicial
    for(i = 0; i < tamanhoNavio; i++) {
        tabuleiro[h_linha][h_coluna + i] = 3;
    }

    // -----------------------------
    // Navio Vertical
    // -----------------------------
    int v_linha = 4;   // Linha inicial
    int v_coluna = 7;  // Coluna inicial
    for(i = 0; i < tamanhoNavio; i++) {
        tabuleiro[v_linha + i][v_coluna] = 3;
    }

    // -----------------------------
    // Navio Diagonal (top-left -> bottom-right)
    // -----------------------------
    int d1_linha = 0;
    int d1_coluna = 0;
    for(i = 0; i < tamanhoNavio; i++) {
        tabuleiro[d1_linha + i][d1_coluna + i] = 3;
    }

    // -----------------------------
    // Navio Diagonal (bottom-left -> top-right)
    // -----------------------------
    int d2_linha = 6;
    int d2_coluna = 0;
    for(i = 0; i < tamanhoNavio; i++) {
        tabuleiro[d2_linha - i][d2_coluna + i] = 3;
    }

    // -----------------------------
    // Exibição do Tabuleiro
    // -----------------------------
    printf("Tabuleiro da Batalha Naval - Nível Aventureiro:\n\n");
    for(int linha = 0; linha < 10; linha++) {
        for(int coluna = 0; coluna < 10; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}