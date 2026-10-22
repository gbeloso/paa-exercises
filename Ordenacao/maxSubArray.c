#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct {
    double soma;
    int inicio;
    int fim;
} Subarranjo;

typedef struct {
    Subarranjo maximo;
    Subarranjo sufixo;
} solucao;

solucao maxSubArray(double S[], int n){
    solucao retorno;
    if(n == 1){
        if(S[n-1] > 0){
            retorno.maximo.soma = S[n-1];
            retorno.sufixo.soma = S[n-1];
            retorno.maximo.inicio = n-1;
            retorno.sufixo.inicio = n-1;
            retorno.maximo.fim = n-1;
            retorno.sufixo.fim = n-1;
        }
        else{
            retorno.maximo.soma = 0;
            retorno.sufixo.soma = 0;
            retorno.maximo.inicio = -1;
            retorno.sufixo.inicio = -1;
            retorno.maximo.fim = -1;
            retorno.sufixo.fim = -1;
        }
    }
    else{
        retorno =  maxSubArray(S, n-1);
        if(retorno.sufixo.soma == 0){//vazio
            retorno.sufixo.inicio = n-1;
        }
        retorno.sufixo.soma = S[n-1] + retorno.sufixo.soma;
        retorno.sufixo.fim = n-1;
        if(retorno.sufixo.soma > retorno.maximo.soma){
             retorno.maximo.soma = retorno.sufixo.soma;
             retorno.maximo.inicio = retorno.sufixo.inicio;
             retorno.maximo.fim = retorno.sufixo.fim;
        }
        else{
            if(retorno.sufixo.soma < 0){
                retorno.sufixo.soma = 0;
                retorno.sufixo.inicio = -1;
                retorno.sufixo.fim = -1;
            }
        }
    }
    return retorno;
}

int main()
{
 
    int n, i;
    scanf("%d", &n);
 
    double a[n];
 
    for(i = 0; i < n; i++){
        scanf("%lf", &a[i]);
    }

    solucao S_linha = maxSubArray(a, n);
    printf("Soma do subarranjo maximo: %.2f\n", S_linha.maximo.soma);
    printf("S' = [");
    for(i  = S_linha.maximo.inicio; i <= S_linha.maximo.fim; i++){
        printf(" %lf ", a[i]);
    }
    printf("]\n");
    printf("Soma do sufixo maximo: %.2f\n", S_linha.sufixo.soma);
    printf("Sx = [");
    for(i  = S_linha.sufixo.inicio; i <= S_linha.sufixo.fim; i++){
        printf(" %lf ", a[i]);
    }
    printf("]\n");

    return 0;
}