#include <stdio.h>
#include <stdlib.h>
#include "entrada.h"
#include "operacoes.h"
#include "metodos.h"
#include "saida.h"


int main(int argc, char const *argv[])
{    
    double **A;
    double **l;
    double **u;
    double *B;
    double *X, *Y;
    int dimensao;
    double *resid;
    

    A = lerMatriz(&dimensao,&dimensao);
    B = lerVetor(&dimensao);
    u = criaMatriz(dimensao, dimensao);
    l = criaMatrizI(dimensao);
    X = criaVetor(dimensao);
    Y = criaVetor(dimensao);
    resid = criaVetor(dimensao);


    //verifica se é matriz triangular inferior
    if(determinanteI(A,dimensao) == 0){
        printf("A matriz é singular, não é possível aplicar o método\n");
        exit(1);
    }
    
    lu(A,l,u,dimensao);
    imprimeMatriz(l,dimensao,dimensao);
    imprimeMatriz(u,dimensao,dimensao);
    forwardSub(l,B,Y,dimensao);
    backSub(u,Y,X,dimensao);
    imprimeVetor(X,dimensao);
    residuo(A,X,B,resid,dimensao);
    printf("Residuo: %lf\n", normaDois(resid, dimensao));

    return 0;
}
