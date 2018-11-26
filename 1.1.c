#include <stdio.h>
#include <stdlib.h>
#include "entrada.h"
#include "operacoes.h"
#include "metodos.h"
#include "saida.h"


int main(int argc, char const *argv[])
{   
    
    double **A;
    double *b;
    
    double *x;
    
    int dimensao;
    
    double *resid;
    printf("00\n"); 
    printf("01\n");
    A = lerMatriz(&dimensao,&dimensao);
    b = lerVetor(&dimensao);
    x = criaVetor(dimensao);
    resid = criaVetor(dimensao);


    //verifica se é matriz triangular inferior
    if(isTriangularInferior(A,dimensao) == 0){
        printf("Não é triangular inferior\n");
        exit(1);
    }
    
    forwardSub(A,b,x,dimensao);
    imprimeVetor(x,dimensao);
    residuo(A,x,b,resid,dimensao);
    printf("Residuo: %lf\n", normaDois(resid, dimensao));

    return 0;
}
