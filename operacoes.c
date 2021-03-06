#include <stdlib.h>
#include <math.h>
#include <float.h>
#include "metodos.h"
#include "entrada.h"
#include "saida.h"

double** criaMatriz(int m, int n)
{
    double **matriz;
    int i;

    matriz = (double**) malloc(sizeof(double*) * m);

    for(i = 0; i < m; i++)
        matriz[i] = (double*) malloc(sizeof(double) * n);

    return matriz;
}

double** criaMatrizI(int n)
{
    double **matriz;
    int i, j;

    matriz = criaMatriz(n, n);

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
        {
            if(i == j)
            {
                matriz[i][j] = 1;
            }
            else
            {
                matriz[i][j] = 0;
            }
        }

    return matriz;
}

double* criaVetor(int n)
{
    double *v;

    v = (double*) malloc(sizeof(double) * n);

    return v;
}

void transposta(double** matriz, double** t, int m, int n)
{
    int i, j;

    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
            t[j][i] = matriz[i][j];
}

void backSub(double** matriz, double* b, double* x, int n)
{
    int i, j;

    for(i = n - 1; i >= 0; i--)
    {
        x[i] = b[i];
        for(j = n - 1; j >= i + 1; j--)
            x[i] -= matriz[i][j] * x[j];
        x[i] /= matriz[i][i];
    }
}

void forwardSub(double** matriz, double* b, double* x, int n)
{
    int i, j;

    for(i = 0; i < n; i++)
    {
        x[i] = b[i];
        for(j = 0; j < i; j++)
            x[i] -= matriz[i][j] * x[j];
        x[i] /= matriz[i][i];
    }
}

void multiplica(double** a, int m, int n, double** b, int p, int q, double** result)
{
    int i, j, k;

    for(i = 0; i < m; i++)
        for(j = 0; j < q; j++)
        {
            result[i][j] = 0;
            for(k = 0; k < n; k++)
                result[i][j] += a[i][k] * b[k][j];
        }
}

void multiplicaVetor(double** a, int m, int n, double* v, double* result, int s)
{
    int i, j;

    for(i = 0; i < m; i++)
    {
        result[i] = 0;
        for(j = 0; j < n; j++)
            result[i] += a[i][j] * v[j];
    }

}

double produtoEscalar(double* a, double* b, int n)
{
    int i;
    double produto = 0;

    for(i = 0; i < n; i++)
        produto += a[i] * b[i];

    return produto;
}

void subtraiVetores(double* a, double* b, double* result, int n)
{
    int i;

    for(i = 0; i < n; i++)
        result[i] = a[i] - b[i];
}

void somaVetores(double* a, double* b, double* result, int n)
{
    int i;

    for(i = 0; i < n; i++)
        result[i] = a[i] + b[i];
}

void somaMatrizes(double** a, double** b, double** result, int n)
{
    int i, j;

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            result[i][j] = a[i][j] + b[i][j];
}

void subtraiMatrizes(double** a, double** b, double** result, int n)
{
    int i, j;

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            result[i][j] = a[i][j] - b[i][j];
}

double normaF(double** matriz, int n)
{
    int i, j;
    double norma = 0;

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            norma += matriz[i][j] * matriz[i][j];

    norma = sqrt(norma);

    return norma;
}

double normaLinha(double** matriz, int n)
{
    int i, j;
    double norma = -1, soma = 0;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            soma += fabs(matriz[i][j]);

        if(soma > norma)
            norma = soma;

        soma = 0;
    }

    return norma;
}

double normaColuna(double** matriz, int n)
{
    int i, j;
    double norma = -1, soma = 0;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            soma += fabs(matriz[j][i]);

        if(soma > norma)
            norma = soma;

        soma = 0;
    }

    return norma;
}

double normaDois(double* vetor, int n)
{
    int i;
    double norma = 0;

    for(i = 0; i < n; i++)
        norma += vetor[i] * vetor[i];

    norma = sqrt(norma);

    return norma;
}

double angulo(double* v1, double* v2, int n)
{
    double t;
    
    /* Para determinar o ângulo entre dois vetores v1 e v2, os seguintes cálculos são realizados:
     * cos(x) = <v1, v2> / |v1|*|v2|
     * angulo = acos(<v1, v2> / |v1|*|v2|)
     */
    
    t = acos(produtoEscalar(v1, v2, n) / (normaDois(v1, n) * normaDois(v2, n)));

    return t;
}

int isVandermonde(double** a, int n)
{
    int i, j;

    /*
     * Os loops abaixo verificam a condição necessária para que uma matriz seja de Vandermonde:
     * a[i][1]^j == a[i][j]
     * Se o segundo elemento de cada linha elevado à j-ésima potência for diferente do elemento da
     * coluna j dessa mesma linha, a condição não será satisfeita e a função retornará zero.
     */
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            if(pow(a[i][1], j) != a[i][j])
                return 0;

    return 1;
}

double detVandermonde(double** a, int n)
{
    int i, j;
    double d = 1;
    
    /*
     * O determinante de uma matriz de Vandermonde é o produtório de (a[j][1] - a[i][1]), tal que 0 <= j < i < n
     */
    
    for(j = 0; j < n-1; j++)
        for(i = j+1; i < n; i++)
            d *= (a[j][1] - a[i][1]);

    return d;
}

void getColuna(double** matriz, double* vColuna, int coluna, int n)
{
    int i;

    for(i = 0; i < n; i++)
        vColuna[i] = matriz[i][coluna];
}

double normaInfinito(double* vetor, int n)
{
    int i;
    double maior = fabs(vetor[0]), elemento;

    for(i = 1; i < n; i++)
    {
        elemento = fabs(vetor[i]);
        if(elemento > maior)
            maior = elemento;
    }

    return maior;
}

double erroRelativo(double x1, double x0)
{
    double erro;

    erro = fabs(x1 - x0) / fabs(x1);

    return erro;
}

void liberaMatriz(double** a, int nLinhas)
{
    int i;
    
    for(i = 0; i < nLinhas; i++)
	free(a[i]);
    
    free(a);
}

void liberaVetor(double* a)
{
    free(a);
}

void derivada(double* y, double* d, int n)
{
    int i;
    
    for(i = 0; i < n; i++)
	d[i] = y[i] * (n-i);
}

double ordenada(double* polinomio, double abscissa, int n)
{
    int i;
    double y = 0;
    
    for(i = 0; i < n; i++)
	y += polinomio[i] * pow(abscissa, n-i);
    
    y += polinomio[n];
    
    return y;
}

void encontraGraus(double **matrizA, int n, int m, double **matrizD)
{
    int i, j;

    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            if(matrizA[i][j] != 0)
                matrizD[i][i]++;
}

void matrizNula(double **matriz, int n, int m)
{
    int i, j;
    
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            matriz[i][j] = 0;
}

double** calculaInversa(double **matrizA, int lin, int col)
{
    double ** inversa;
    double ** matrizI;
    double *v1;
    double *v2;
    double tol = 0.000001;
    unsigned long int iMax = 10000;

    matrizI = criaMatrizI(lin);
    inversa = criaMatriz(lin, col);
    v1 = criaVetor(lin);
    v2 = criaVetor(lin);

    

    for(int i = 0; i < col; i++)
    {
        for(int j = 0; j < col; j++)
        {
            v1[j] = matrizI[i][j];
        }
        imprimeVetor(v1, lin);

        gaussSeidel(matrizA, v1, v2, tol, iMax, lin);

        imprimeVetor(v2, lin);

        for(int k = 0; k < col; k++)
        {
            inversa[i][k] = v2[k];
        }
        if(i == col-1)
            break;
    }
    return inversa;
}

double determinanteI(double **matrizI, int n)
{
    double resultado = 1;
    int i, j;

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            if(i == j)
                resultado *= matrizI[i][j];

    return resultado;
}

void multiplicaPorEscalar(double* vetor, double* resultado, double escalar, int n)
{
    int i;
    
    for(i = 0; i < n; i++)
	resultado[i] = vetor[i] * escalar;
}

void projecaoOrtogonal(double* w, double* v, double* proj, int n)
{
    double alpha;
    
    alpha = produtoEscalar(w, v, n) / produtoEscalar(v, v, n);
    
    multiplicaPorEscalar(v, proj, alpha, n);
}

void atribui(double* y, double* x, int n)
{
    int i;
    
    if(x == y)
	return;
    
    for(i = 0; i < n; i++)
	y[i] = x[i];
}

int isOrtonormal(double** vetores, int dimensao)
{
    int i, j;
    double norma, produtoI, tolerancia = DBL_EPSILON * 100;
    
    for(i = 0; i < dimensao; i++)
    {
	    norma = normaDois(vetores[i], dimensao);
	
	    if(fabs(norma - 1) > tolerancia)
	        return 0;
    }
    
    for(i = 0; i < dimensao; i++)
        for(j = i + 1; j < dimensao; j++)
	    {
	    produtoI = produtoEscalar(vetores[i], vetores[j], dimensao);
	    
	    if(fabs(produtoI) > tolerancia)
		    return 0;
	    }
    
    return 1;
}

int isBanda(double** matriz, int n)
{
    if(matriz[0][n-1] == 0 && matriz[n-1][0] == 0)
	return 1;
    else
	return 0;
}

void divideVetorPorEscalar(double *v, int n, double escalar)
{  
    int i;
    for ( i = 0; i < n; i++)
    {
        v[i] = v[i]/escalar;
    }
}

void preencheColuna(double **matriz, int coluna, int n, double *vetor){

    int i, j;

    for(i=0;i<n;i++)
    {
        matriz[i][coluna] = vetor[i];
    }
}

void atualizaVel(double A1, double A2, double A3, double c1, double c2, int n, double *melhorPos, double *vetVel, double *vetPos, double *vetMB, double *vetResul){

    int i;
    for(i=0; i<n; i++)
    {
        vetVel[i] = A1 * vetVel[i]; ///A1*Vi
    }
    double resulMPSI[n], resulMBSI[n];

    subtraiVetores(melhorPos, vetPos, resulMPSI, n); /// MP - Si
    for(i=0; i<n; i++)
    {
        resulMPSI[i] = resulMPSI[i] * A2 * c1; ///A2*C1*(MP-Si)
    }

    subtraiVetores(vetMB, vetPos, resulMBSI, n); /// MB - Si
    for(i=0; i<n; i++)
    {
        resulMBSI[i] = resulMBSI[i] * A3 * c2; ///A3*C2*(MB-Si)
    }
    double vetResul1[n];

    somaVetores(vetVel, resulMPSI, vetResul1, n);
    somaVetores(vetResul1, resulMBSI, vetResul,n);

}

void atualizaPos(double *Satual, double *velAtual, int n){

    int i;

    for(i=0; i<n; i++)
    {
        Satual[i] = Satual[i] + velAtual[i];
    }
}

void vetorNulo(double *vetor, int n)
{
    int i;
    for(i = 0; i < n; i++)
        vetor[i] = 0;
}


int isTriangularInferior(double **matriz, int n){
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if( j > i && matriz[i][j] != 0){
                return 0;
            }
        }
    }
    return 1;
}

