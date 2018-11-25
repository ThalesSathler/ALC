#include <stdio.h>
#include "operacoes.h"
#include "metodos.h"
#include "saida.h"
#include "entrada.h"

int main()
{
    double **a, *b, *x, *r1;
    int n = 22;
    double tol = 0.0001;
    unsigned long int max = 1000;
    //tem que ser  matrizes simetricas positivas semidefinidas
    
    a = lerMatriz(n, n);
    b = lerVetor(n);
    
    x = criaVetor(n);
    
    gradienteConjugado(a, b, x, tol, max, n);
    
    printf("Solucao obtida com o metodo do Gradiente Conjudado:\n");
    imprimeVetor(x, n);
    
    r1 = criaVetor(n);
    
    residuo(a, x, b, r1, n);
    
    printf("Norma do residuo com a solucao obtida pelo gradiente conjugado: %lf\n", normaDois(r1, n));
    
    return 0;
}