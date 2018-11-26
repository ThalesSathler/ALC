#include <stdio.h>
#include <stdlib.h>
#include "operacoes.h"
#include "metodos.h"
#include "saida.h"
#include "entrada.h"


int main() {
    double dx = 6;
    double tol = 0.0001;
    double gamma = 0.01;
    unsigned int max_iters = 10000;
    printf("The local minimum is: %f\n", gradienteDescente(dx, tol, gamma, max_iters));
    return 0;
}