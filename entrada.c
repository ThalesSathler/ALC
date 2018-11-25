#include <stdio.h>
#include <stdlib.h>
#include "operacoes.h"

double** lerMatriz(int m, int n)
{
    FILE *fMatriz;
    fMatriz = fopen("alc_compactada/matrizA_22_22.txt", "r");
    if (fMatriz == NULL)
    {
        printf("Erro na leitura do arquivo\n");
        exit(0);
    }

    double **matriz;
    int i, j;

    matriz = criaMatriz(m, n);

    

    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
            fscanf(fMatriz, "%lf", &matriz[i][j]);

    fclose(fMatriz);

    return matriz;
}

double* lerVetor(int n)
{
    FILE *fVetor;
    fVetor = fopen("alc_compactada/vetorb_22x1.txt", "r");

    double *vetor;
    int i;

    vetor = criaVetor(n);

    if (fVetor == NULL)
    {
        printf("Erro na leitura do arquivo\n");
        exit(0);
    }

    for(i = 0; i < n; i++)
        fscanf(fVetor, "%lf", &vetor[i]);

    fclose(fVetor);

    return vetor;
}

double* lerVetorSolucao(int n)
{
    FILE *fVetor;
    fVetor = fopen("vetorSolucao.txt", "r");

    double *vetor;
    int i;

    vetor = criaVetor(n);

    if (fVetor == NULL)
    {
        printf("Erro na leitura do arquivo\n");
        exit(0);
    }

    for(i = 0; i < n; i++)
        fscanf(fVetor, "%lf", &vetor[i]);

    fclose(fVetor);

    return vetor;
}