#include <stdio.h>

int main() {
    int tabuleiro[10][10] = {0}; // Tabuleiro 10x10 inicializado com 0 (água)
    int tamanhoNavio = 3;        // Tamanho fixo dos navios
    int i;

    // -----------------------------
    // Posicionamento dos Navios
    // -----------------------------
    // Navio Horizontal
    int h_linha = 1, h_coluna = 2;
    for(i = 0; i < tamanhoNavio; i++) {
        tabuleiro[h_linha][h_coluna + i] = 3;
    }

    // Navio Vertical
    int v_linha = 4, v_coluna = 7;
    for(i = 0; i < tamanhoNavio; i++) {
        tabuleiro[v_linha + i][v_coluna] = 3;
    }

    // Navio Diagonal (top-left -> bottom-right)
    int d1_linha = 0, d1_coluna = 0;
    for(i = 0; i < tamanhoNavio; i++) {
        tabuleiro[d1_linha + i][d1_coluna + i] = 3;
    }

    // Navio Diagonal (bottom-left -> top-right)
    int d2_linha = 6, d2_coluna = 0;
    for(i = 0; i < tamanhoNavio; i++) {
        tabuleiro[d2_linha - i][d2_coluna + i] = 3;
    }

    // -----------------------------
    // Habilidades Especiais
    // -----------------------------
    int cone[3][5];    // Matriz 3x5 para cone
    int cruz[3][5];    // Matriz 3x5 para cruz
    int octaedro[3][5];// Matriz 3x5 para octaedro
    int linha, coluna;

    // Construindo Habilidade Cone (1 = afetado, 0 = não afetado)
    for(linha = 0; linha < 3; linha++) {
        for(coluna = 0; coluna < 5; coluna++) {
            // Cone: linhas superiores com menos valores, inferiores com mais
            if(coluna >= 2 - linha && coluna <= 2 + linha)
                cone[linha][coluna] = 1;
            else
                cone[linha][coluna] = 0;
        }
    }

    // Construindo Habilidade Cruz
    for(linha = 0; linha < 3; linha++) {
        for(coluna = 0; coluna < 5; coluna++) {
            if(linha == 1 || coluna == 2)
                cruz[linha][coluna] = 1;
            else
                cruz[linha][coluna] = 0;
        }
    }

    // Construindo Habilidade Octaedro
    for(linha = 0; linha < 3; linha++) {
        for(coluna = 0; coluna < 5; coluna++) {
            if(linha == 1 || (linha != 1 && coluna == 2))
                octaedro[linha][coluna] = 1;
            else
                octaedro[linha][coluna] = 0;
        }
    }

    // -----------------------------
    // Aplicando Habilidades no Tabuleiro
    // -----------------------------
    int origemLinha, origemColuna;
    int linhaHabilidade, colunaHabilidade;
    int tabLinha, tabColuna;

    // Função para sobrepor habilidade (5 = área afetada)
    // Cone: origem na linha 0, coluna 5
    origemLinha = 0; origemColuna = 5;
    for(linhaHabilidade = 0; linhaHabilidade < 3; linhaHabilidade++) {
        for(colunaHabilidade = 0; colunaHabilidade < 5; colunaHabilidade++) {
            if(cone[linhaHabilidade][colunaHabilidade] == 1) {
                tabLinha = origemLinha + linhaHabilidade;
                tabColuna = origemColuna + colunaHabilidade - 2; // centralizando
                if(tabLinha >=0 && tabLinha <10 && tabColuna >=0 && tabColuna <10) {
                    // Não sobrescreve navios
                    if(tabuleiro[tabLinha][tabColuna] == 0)
                        tabuleiro[tabLinha][tabColuna] = 5;
                }
            }
        }
    }

    // Cruz: origem na linha 5, coluna 2
    origemLinha = 5; origemColuna = 2;
    for(linhaHabilidade = 0; linhaHabilidade < 3; linhaHabilidade++) {
        for(colunaHabilidade = 0; colunaHabilidade < 5; colunaHabilidade++) {
            if(cruz[linhaHabilidade][colunaHabilidade] == 1) {
                tabLinha = origemLinha + linhaHabilidade - 1;
                tabColuna = origemColuna + colunaHabilidade - 2;
                if(tabLinha >=0 && tabLinha <10 && tabColuna >=0 && tabColuna <10) {
                    if(tabuleiro[tabLinha][tabColuna] == 0)
                        tabuleiro[tabLinha][tabColuna] = 5;
                }
            }
        }
    }

    // Octaedro: origem na linha 7, coluna 7
    origemLinha = 7; origemColuna = 7;
    for(linhaHabilidade = 0; linhaHabilidade < 3; linhaHabilidade++) {
        for(colunaHabilidade = 0; colunaHabilidade < 5; colunaHabilidade++) {
            if(octaedro[linhaHabilidade][colunaHabilidade] == 1) {
                tabLinha = origemLinha + linhaHabilidade - 1;
                tabColuna = origemColuna + colunaHabilidade - 2;
                if(tabLinha >=0 && tabLinha <10 && tabColuna >=0 && tabColuna <10) {
                    if(tabuleiro[tabLinha][tabColuna] == 0)
                        tabuleiro[tabLinha][tabColuna] = 5;
                }
            }
        }
    }

    // -----------------------------
    // Exibindo Tabuleiro Final
    // -----------------------------
    printf("Tabuleiro Batalha Naval - Nível Mestre:\n\n");
    for(linha = 0; linha < 10; linha++) {
        for(coluna = 0; coluna < 10; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}