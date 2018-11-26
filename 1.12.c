#include <stdio.h>
#include "operacoes.h"
#include "metodos.h"
#include "saida.h"
#include "entrada.h"

int main()
{
    double **A, *b, **R, *x1, *r1, w;
    double tol = 0.0001;
    int n, teste;
    unsigned long int iMax = 1000;

    A = lerMatriz(&n, &n);

    b = lerVetor(&n);

    R = criaMatriz(n, n);




    printf("Resolucao do sistema com o metodo SOR:\n");

    printf("Digite um valor para w entre 0 e 2: ");
    scanf("%lf%*c", &w);

    x1 = criaVetor(n);

    if(teste = SOR(A, b, x1, tol, w, iMax, n))
    {
        printf("\nSolucao do sistema com o metodo SOR:\n");
        imprimeVetor(x1, n);
    }
    else
    {
        printf("\nNao foi possivel resolver o sistema pelo metodo SOR.\n");
    }
    
    //Calcula norma do resíduo
    if(teste)
    {
	r1 = criaVetor(n);
        residuo(A, x1, b, r1, n);

        printf("Norma do residuo do SOR:\n");
        printf("SOR: %lf\n", normaDois(r1, n));
    }

    return 0;
}