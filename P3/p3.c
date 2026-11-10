#include <stdio.h>
#include <stdlib.h>

/*
 * Problema 3 - Vigilancia
 *
 * Modelagem: cada guarita cobre uma linha e uma coluna inteiras. Para cobrir
 * todas as N linhas e N colunas com o numero minimo de guaritas, precisamos de
 * exatamente N guaritas, uma por coluna, cada uma numa linha distinta. Isso
 * equivale a uma permutacao: a[c] = linha onde fica a guarita da coluna c.
 *
 * Os M pontos obrigatorios ja fixam algumas dessas posicoes. O trabalho do
 * backtracking e distribuir as linhas que sobraram nas colunas que sobraram,
 * gerando todas as permutacoes validas em ordem lexicografica.
 */

/* Variaveis globais com as dimensoes do caso de teste.
 * N = tamanho da regiao (N x N); M = numero de pontos obrigatorios. */
int N, M;

/* Numero de guaritas ainda nao fixadas = linhas/colunas livres a distribuir. */
#define MAX_CANDIDATES (N-M)

/* Criterio de parada do backtracking.
 * k conta quantas das (N-M) guaritas livres ja foram posicionadas.
 * Quando k == N-M, todas as livres foram colocadas: temos uma solucao. */
int is_solution(int k){
    if(k == N-M){
        return 1;
    }
    else{
        return 0;
    }
}

/* Imprime uma solucao completa: a linha da guarita de cada coluna 1..N.
 * O ultimo elemento recebe '\n' em vez de espaco para evitar espaco no fim
 * da linha. */
void print_a(int a[]){
    int i;
    for(i = 1; i < N+1; i++){
        if(a[i] == -1){
            printf("_ ");           /* nunca deve ocorrer numa solucao completa */
        }
        else{
            if(i != N){
                printf("%d ", a[i]); /* separador entre numeros */
            }
            else{
                printf("%d\n", a[i]);/* ultimo numero: quebra de linha */
            }
        }
    }
}

/*
 * Backtracking que gera todas as permutacoes validas.
 *
 * a[]     : estado atual. a[coluna] = linha fixada, ou -1 se a coluna esta livre.
 * k       : quantas guaritas livres ja foram posicionadas nesta ramo.
 * input[] : linhas ainda disponiveis para posicionar (-1 marca "ja usada").
 */
void backtrack(int a[], int k, int input []){
    /* Caso base: todas as livres posicionadas -> imprime a permutacao. */
    if(is_solution(k)){
        print_a(a);
        return;
    }
    else{
        int i, j, new_pos;

        k = k + 1; /* vamos posicionar mais uma guarita neste nivel */

        /* Percorre as linhas disponiveis em input[] em ordem crescente.
         * Como input[] foi preenchido em ordem e a primeira coluna livre e
         * sempre escolhida da esquerda para a direita, a saida sai ordenada
         * lexicograficamente. */
        for(i = 0; i < MAX_CANDIDATES; i++){
            if(input[i] != -1){
                /* Acha a primeira coluna ainda livre (a[j] == -1). */
                for(j = 1; j < N+1; j++){
                    if (a[j] == -1){
                        new_pos = j;
                        j = N+2; /* "break": para o loop ao achar a coluna */
                    }
                }

                /* Escolhe: coloca a linha input[i] nessa coluna e marca a
                 * linha como usada. Funciona como o make_move. */
                a[new_pos] = input[i];
                input[i] = -1;

                /* Recorre para preencher as colunas restantes. */
                backtrack(a, k, input);

                /* Desfaz a escolha (backtrack): devolve a linha ao pool e
                 * libera a coluna para a proxima tentativa. Funciona como o unmake_move. */
                input[i] = a[new_pos];
                a[new_pos] = -1;
            }
        }
        return;
    }
}

int main(){
    int u, v, i, j, k;

    /* Le N e M. */
    j = scanf("%d %d", &N, &M);

    /* a[1..N]: linha da guarita de cada coluna (indice 0 nao usado). */
    int a[N+1];
    /* input[]: linhas que ainda precisam ser distribuidas (as nao fixas). */
    int input[MAX_CANDIDATES];

    /* Inicializa todas as colunas como livres. */
    for(i = 1; i < N+1; i++){
        a[i] = -1;
    }

    /* Le os M pontos obrigatorios (linha u, coluna v) e fixa a[v] = u. */
    for(i = 0; i < M; i++){
        j = scanf("%d %d", &u, &v);
        a[v] = u;
    }

    /* Monta input[] com as linhas que NAO foram usadas pelos pontos fixos.
     * Para cada linha i de 1..N, verifica se ela ja aparece em a[]; se nao,
     * entra na lista de linhas disponiveis. A iteracao em ordem crescente de i
     * garante que input[] fique ordenado -> saida lexicografica. */
    j = 0;
    k = 0;
    for (i = 1; i < N+1; i++){
        int tmp = -1;
        for(j = 1; j < N+1; j++){
            if(a[j] == i){
                tmp = a[j]; /* linha i ja usada por um ponto fixo */
            }
        }
        if(tmp == -1){
            input[k] = i;
            k++;
        }
    }

    /* Inicia o backtracking com 0 guaritas livres posicionadas. */
    backtrack(a, 0, input);

    return 0;
}
