#include <stdio.h>
#include <stdlib.h>
#include "entrada.h"
#include "operacoes.h"
#include "metodos.h"
#include "saida.h"


int main(int argc, char const *argv[])
{    
    double **A;
    double *B;
    double *X;
    int dimensao = 20;
    double tol = 0.0001;
    int particulas = 800;

    double *resid;
    double normaPSO;
    

    A = lerMatriz(dimensao,dimensao);
    B = lerVetor(dimensao);
    X = criaVetor(dimensao);
    resid = criaVetor(dimensao);

    // PSO(dimensao, A, B, X);
    PSO(A,dimensao,B,X,tol,particulas);

    printf("\nSolucao com PSO\n");

    imprimeVetor(X, dimensao);
    
    residuo(A, X, B, resid, dimensao);
    normaPSO = normaDois(resid, dimensao);
    printf("\n norma do residuo %f",normaPSO);

    printf("\n");


    return 0;
}
