#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
#include <stdio.h>

// ======= NÍVEL NOVATO =======
// Tabuleiro 5x5, 2 navios (1 vertical e 1 horizontal)

#define TAB_NOVATO 5

void nivelNovato() {
    printf("=== Nível Novato ===\n");

    // Navio vertical de tamanho 3, posicionado na coluna 1, linhas 1 a 3
    int navioVertical[3][2] = {{1,1},{2,1},{3,1}};

    // Navio horizontal de tamanho 3, posicionado na linha 4, colunas 2 a 4
    int navioHorizontal[3][2] = {{4,2},{4,3},{4,4}};

    printf("Navio Vertical (tamanho 3):\n");
    for (int i = 0; i < 3; i++) {
        printf("Parte %d -> Linha: %d, Coluna: %d\n", i+1, navioVertical[i][0], navioVertical[i][1]);
    }

    printf("\nNavio Horizontal (tamanho 3):\n");
    for (int i = 0; i < 3; i++) {
        printf("Parte %d -> Linha: %d, Coluna: %d\n", i+1, navioHorizontal[i][0], navioHorizontal[i][1]);
    }

    printf("\n");
}

// ======= NÍVEL AVENTUREIRO =======
// Tabuleiro 10x10 com 4 navios, incluindo diagonal

#define TAB_AVENTUREIRO 10

void nivelAventureiro() {
    printf("=== Nível Aventureiro ===\n");

    int tabuleiro[TAB_AVENTUREIRO][TAB_AVENTUREIRO] = {0};

    // Navio 1: vertical tamanho 3, linha 0 a 2, coluna 0
    for (int i = 0; i < 3; i++)
        tabuleiro[i][0] = 3;

    // Navio 2: horizontal tamanho 4, linha 5, colunas 2 a 5
    for (int j = 2; j <= 5; j++)
        tabuleiro[5][j] = 3;

    // Navio 3: diagonal tamanho 3, linha 7 a 9, coluna 7 a 9
    for (int i = 0; i < 3; i++)
        tabuleiro[7 + i][7 + i] = 3;

    // Navio 4: diagonal tamanho 2, linha 3 a 4, coluna 8 a 9
    for (int i = 0; i < 2; i++)
        tabuleiro[3 + i][8 + i] = 3;

    // Exibir tabuleiro completo
    printf("Tabuleiro 10x10 (0 = livre, 3 = navio):\n");
    for (int i = 0; i < TAB_AVENTUREIRO; i++) {
        for (int j = 0; j < TAB_AVENTUREIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

// ======= NÍVEL MESTRE =======
// Habilidades especiais: cone, cruz e octaedro

#define HABILIDADE_SIZE 5

void imprimirMatriz(int mat[HABILIDADE_SIZE][HABILIDADE_SIZE]) {
    for (int i = 0; i < HABILIDADE_SIZE; i++) {
        for (int j = 0; j < HABILIDADE_SIZE; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void nivelMestre() {
    printf("=== Nível Mestre ===\n");

    int cone[HABILIDADE_SIZE][HABILIDADE_SIZE] = {0};
    int cruz[HABILIDADE_SIZE][HABILIDADE_SIZE] = {0};
    int octaedro[HABILIDADE_SIZE][HABILIDADE_SIZE] = {0};

    // Construindo padrão CONE (como no exemplo)
    // Forma um triângulo invertido
    for (int i = 0; i < HABILIDADE_SIZE; i++) {
        for (int j = 0; j < HABILIDADE_SIZE; j++) {
            if ((i == 2) || // linha central cheia
                (i == 1 && (j >= 1 && j <= 3)) ||
                (i == 0 && j == 2) ||
                (i == 3 && (j >= 1 && j <= 3)) ||
                (i == 4))
                cone[i][j] = 1;
        }
    }
    // Ajuste para formato correto do cone (base maior e centro mais cheio)
    // Vamos usar o padrão do enunciado:  
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1

    // Para simplificar, redefinimos o cone para 3 linhas como exemplo:
    for (int i = 0; i < HABILIDADE_SIZE; i++)
        for (int j = 0; j < HABILIDADE_SIZE; j++)
            cone[i][j] = 0;

    cone[0][2] = 1;
    cone[1][1] = 1; cone[1][2] = 1; cone[1][3] = 1;
    for (int j = 0; j < 5; j++) cone[2][j] = 1;

    // Construindo padrão CRUZ
    for (int i = 0; i < HABILIDADE_SIZE; i++) {
        for (int j = 0; j < HABILIDADE_SIZE; j++) {
            if (i == 2 || j == 2)
                cruz[i][j] = 1;
        }
    }

    // Construindo padrão OCTAEDRO (exemplo menor)
    // Conforme exemplo:  
    // 0 0 1 0 0  
    // 0 1 1 1 0  
    // 0 0 1 0 0  

    for (int i = 0; i < HABILIDADE_SIZE; i++)
        for (int j = 0; j < HABILIDADE_SIZE; j++)
            octaedro[i][j] = 0;

    octaedro[0][2] = 1;
    octaedro[1][1] = 1; octaedro[1][2] = 1; octaedro[1][3] = 1;
    octaedro[2][2] = 1;

    printf("Habilidade CONE:\n");
    imprimirMatriz(cone);

    printf("Habilidade CRUZ:\n");
    imprimirMatriz(cruz);

    printf("Habilidade OCTAEDRO:\n");
    imprimirMatriz(octaedro);
}

int main() {
    nivelNovato();
    nivelAventureiro();
    nivelMestre();

    return 0;
}
