#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    FILE *info;
    char ch;
    info = fopen("alc_compactada/matriz_benford.txt", "r");
    int valores[10] = {0,0,0,0,0,0,0,0,0,0};
    float result[10] = {0,0,0,0,0,0,0,0,0,0};
    float comparacoes[10] = {0,0.301,0.176,0.125,0.097,0.079,0.067,0.058,0.051,0.046};
    int total = 0;
    int i, erro = 0;
    
    if (info == NULL){
        printf("Erro na leitura do arquivo\n");
        exit(0);
    }
    
    while((fscanf(info, "%c", &ch))!=EOF ){
        if((int)ch>47 && (int)ch<58){
            i = (int)ch -48;
            printf("%c, %d \n",ch, i);
            valores[i] = valores[i] + 1;
            total++ ;
        }
    }

    for(i=1;i<10;i++)
        result[i] = (log10(1 + 1.0/(float)i));
    
    printf("Resultados\n");
    for(i = 0; i<10; i++){
        if(abs(result[i] - comparacoes[i]) > 0.001 ){
            erro = 1;
        }
        printf("valor: %d contagem: %d porcentagem: %f erro: %lf\n",i,valores[i],result[i],fabs(result[i] - comparacoes[i]));
    }
    if (erro == 1)
        printf("Não satisfaz\n");
    fclose(info);
    
}