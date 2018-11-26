#include <stdio.h>
#include "operacoes.h"
#include "metodos.h"
#include "saida.h"
#include "entrada.h"

int main()
{
    double **a, *b, *x1, *r1, tol = 0.0001;
    int n;
    unsigned long int erro = 1000000;

    a = lerMatriz(&n, &n);
    b = lerVetor(&n);

    x1 = criaVetor(n);
    // imprimeMatriz(a,n,n);
    // imprimeVetor(b,n);

    while(!gaussSeidel(a, b, x1, tol, erro, n))
    {
	if(tol != 1)
	    tol *= 10;
	else
	    tol += 0.1;
    }
    
    printf("Solucao obtida com o metodo de Gauss-Seidel.\nCom tolerancia %lf e condicao de parada %lu:\n", tol, erro);
    
    imprimeVetor(x1, n);
    
    
    r1 = criaVetor(n);
    residuo(a, x1, b, r1, n);
    
    
    printf("Norma do residuo da solocao de Gauss-Seidel: %lf\n", normaDois(r1, n));

    getchar();
    
    liberaMatriz(a, n);
    liberaVetor(b);
    liberaVetor(x1);
    liberaVetor(r1);

    return 0;
}