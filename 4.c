#include <stdio.h>
#include "operacoes.h"
#include "metodos.h"
#include "saida.h"
#include "entrada.h"

int main()
{
    double **A, *b, *x1, *r1, w;
    double tol = 0.0001;
    int n, teste;
    unsigned long int iMax = 1000;

    n = 3;

    A = lerMatriz(n, n);

    b = lerVetor(n);


    


    //Calcular numero condicao
    A = calculaInversa(A, n, n);

    imprimeMatriz(A, n , n);



   

   

    return 0;
}