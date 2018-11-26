#include <stdio.h>
#include <stdlib.h>
#include "operacoes.h"
#include "saida.h" 

double** lerMatriz(int *m, int *n)
{
    char a;
    FILE *fMatriz;
    fMatriz = fopen("alc_compactada/matrizA_22_22.txt", "r");
    if (fMatriz == NULL)
    {
        printf("Erro na leitura do arquivo\n");
        exit(0);
    }
    
    double **matriz;
    int i, j;
    
    fscanf(fMatriz, "%d", m);
    fscanf(fMatriz, "%c", &a);
    fscanf(fMatriz, "%d", n);
    fscanf(fMatriz, "%c", &a);
    
    matriz = criaMatriz(*m, *n);

    for(i = 0; i < *m; i++)
        for(j = 0; j < *n; j++)
            fscanf(fMatriz, "%lf", &matriz[i][j]); 

    fclose(fMatriz);

    return matriz;
}

double** lerMatrizSVD(int m, int *n)
{
    char a;
    FILE *fMatriz;
    fMatriz = fopen("alc_compactada/matrizA_22_22.txt", "r");
    if (fMatriz == NULL)
    {
        printf("Erro na leitura do arquivo\n");
        exit(0);
    }
    
    double **matriz;
    int i, j;
    
    fscanf(fMatriz, "%d", &a);
    fscanf(fMatriz, "%c", &a);
    fscanf(fMatriz, "%d", n);
    fscanf(fMatriz, "%c", &a);
    
    matriz = criaMatriz(m, *n);

    for(i = 0; i < m; i++)
        for(j = 0; j < *n; j++)
            fscanf(fMatriz, "%lf", &matriz[i][j]); 

    fclose(fMatriz);

    return matriz;
}

double* lerVetor(int *n)
{
    char a;
    FILE *fVetor;
    fVetor = fopen("alc_compactada/vetorb_22x1.txt", "r");
    if (fVetor == NULL)
    {
        printf("Erro na leitura do arquivo\n");
        exit(0);
    }

    double *vetor;
    int i;

    fscanf(fVetor, "%d", n);
    fscanf(fVetor, "%d", &a);
    fscanf(fVetor, "%c", &a);
    fscanf(fVetor, "%c", &a);
    
    printf("%c\n", *n);

    vetor = criaVetor(*n);

    for(i = 0; i < *n; i++)
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