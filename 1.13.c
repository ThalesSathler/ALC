#include <stdio.h>
#include <stdlib.h>
#include "entrada.h"
#include "operacoes.h"
#include "metodos.h"
#include "saida.h"


int main(int argc, char const *argv[])
{    
    double **A;
    double **L;
    double **LT;
    double *B;
    double *X;
    int dimensao;
    double *resid;
    

    A = lerMatriz(&dimensao,&dimensao);
    L = criaMatriz(dimensao, dimensao);
    LT = criaMatriz(dimensao, dimensao);
    B = criaVetor(dimensao);
    X = criaVetor(dimensao);

    cholesky(A,L,dimensao);
    imprimeMatriz(L,dimensao,dimensao);

    return 0;
}