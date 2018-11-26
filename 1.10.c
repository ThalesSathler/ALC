#include <stdio.h>
#include "operacoes.h"
#include "metodos.h"
#include "saida.h"
#include "entrada.h"

int main()
{   
    //declarando as variaveis a serem usadas
    double **A, *b, *x, *xAux, cLinha, cColuna, cNorma;
    int n;
    unsigned long int iMax = 1000;

    //lendo as informacoes necessarias
    n = 4;

    //Alocando espaço para os vetores e matrizes
    x = criaVetor(n);

    xAux = criaVetor(n);

    A = lerMatriz(&n, &n);
    
    b = lerVetor(&n);
    
    //executando os criterios
    cLinha = criterioLinhas(A, n);
    cColuna = criterioColunas(A, n);
    cNorma = criterioNorma(A, n);

    //prints para verem se os criterios foram atendidos
    printf("\nCriterio das Linhas: ");
    if(cLinha)
        printf("Criterio das linhas satisfeito");
    else
        printf("Criterio das linhas nao satisfeito");
    printf(" %lf\n", cLinha);


    printf("Criterio das Colunas: ");
    if(cColuna)
        printf("Criterio das colunas satisfeito");
    else
        printf("Criterio das colunas nao satisfeito");
    printf(" %lf\n", cColuna);


    printf("Criterio das Normas: ");
    if(cNorma)
        printf("Criterio das normas satisfeito");
    else
        printf("Criterio das normas nao satisfeito");
    printf(" %lf\n", cNorma);


    //Verificando se os metodos podem ser usados
    //a partir da garantia de convergencia
    //dos criterios

    if(cNorma || cColuna || cLinha)
    {
        printf("O sistema pode ser resolvido usando o metodo de Jacobi.\n");
        jacobi(A, b, x, 0, iMax, n);
        printf("A solucao do sistema pelo metodo de Jacobi e: \n");
        imprimeVetor(x, n);
    }
    else {
        printf("Nenhum dos criterios satisfeitos");        
    }
    
    //liberando espaço alocado
    liberaVetor(x);
    liberaVetor(xAux);
    liberaVetor(b);
    liberaMatriz(A, n);

    return 0;
}