#include <stdio.h>

int main() {
    int tabuleiro[10][10] = {0}; // Inicializa todo o tabuleiro com 0 (água)
    int tamanhoNavio = 3;

    // --- Navio Horizontal ---
    int h_linha = 1;
    int h_coluna = 2;
    for(int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[h_linha][h_coluna + i] = 3;
    }

    // --- Navio Vertical ---
    int v_linha = 4;
    int v_coluna = 7;
    for(int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[v_linha + i][v_coluna] = 3;
    }

    // --- Navio Diagonal (top-left -> bottom-right) ---
    int d1_linha = 0;
    int d1_coluna = 0;
    for(int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[d1_linha + i][d1_coluna + i] = 3;
    }

    // --- Navio Diagonal (bottom-left -> top-right) ---
    int d2_linha = 6;
    int d2_coluna = 0;
    for(int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[d2_linha - i][d2_coluna + i] = 3;
    }

    // Exibe o tabuleiro
    printf("Tabuleiro da Batalha Naval - Nível Aventureiro:\n\n");
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}