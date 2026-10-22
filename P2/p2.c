#include <stdio.h>
#include <stdlib.h>

/*
 * Problema: encontrar o maior subgrafo induzido onde todo vértice (pessoa)
 * tenha grau >= K, ou seja, uma "equipe" em que cada membro se relacione
 * com pelo menos K outros membros da própria equipe.
 *
 * Estratégia: representar as relações como um grafo (matriz de adjacência) e,
 * repetidamente, remover todos os vértices com grau menor que K. Cada remoção
 * pode reduzir o grau dos vizinhos, exigindo novas rodadas até que nenhum
 * vértice precise ser removido (algoritmo do k-core).
 */

/* Matriz de adjacência: relacoes[u][v] == 1 indica aresta entre u e v.
 * Dimensionada para suportar vértices de 1 até 1000. */
int relacoes[1001][1001];
/* grau[u] = número de arestas do vértice u. O valor -1 marca um vértice removido. */
int grau[1001];
/* Quantidade atual de vértices que ainda pertencem à equipe. */
int equipe;
/* N = número de vértices, P = número de arestas (pares), K = grau mínimo exigido. */
int N, P, K;

/* Cria uma aresta não direcionada entre u e v e atualiza o grau de ambos. */
int adiciona_aresta(int u, int v){
    relacoes[u][v] = 1;
    relacoes[v][u] = 1;
    grau[u]++;
    grau[v]++;
    return 0;
}

/* Remove o vértice u do grafo: zera suas arestas, decrementa o grau de cada
 * vizinho afetado, marca u como removido (grau = -1) e reduz o tamanho da equipe. */
int remove_no(int u, int N){
    int i;
    for(i = 1; i < N+1; i++){
        if(i != u){
            if(relacoes[i][u] == 1){        // existe aresta entre i e u?
                relacoes[i][u] = 0;         // remove a aresta nos dois sentidos
                relacoes[u][i] = 0;
                grau[i]--;                  // o vizinho i perde uma conexão
            }
        }
    }
    grau[u] = -1;   // -1 sinaliza que u não faz mais parte do grafo
    equipe--;       // um membro a menos na equipe
    return 0;
}

/* Calcula iterativamente (via recursão) o maior subgrafo induzido em que todos
 * os vértices têm grau >= K. O parâmetro r conta as rodadas de remoção. */
int subgrafoMaximoInduzido(int r){
    // Se a equipe não tem vértices suficientes para que todos tenham grau >= K,
    // não existe solução válida.
    if(equipe < K+1) return 0;
    else{
        int vertices_removidos = 0, i;
        // Percorre todos os vértices ativos e remove os que violam o grau mínimo.
        for(i = 1; i < N+1; i++){
            if(grau[i] != -1){      //-1 indica que o nó i foi removido
                if(grau[i] < K){    // grau abaixo do exigido: vértice deve sair
                    remove_no(i, N);
                    vertices_removidos++;
                }
            }
        }
        if(vertices_removidos == 0){
            // Nenhuma remoção nesta rodada: o grafo estabilizou (todos têm grau >= K).
            return equipe;
        }
        else{
            // Houve remoções que alteraram graus; refaz a verificação numa nova rodada.
            return subgrafoMaximoInduzido(r+1);
        }
    }
}

int main(){
    int i, j;
    int u, v;

    // Lê N (vértices), P (arestas) e K (grau mínimo).
    j = scanf("%d %d %d", &N, &P, &K);
    equipe = N;     // inicialmente todos os vértices fazem parte da equipe

    // Lê as P arestas e as insere no grafo.
    for(i = 0; i < P; i++){
        j = scanf("%d %d", &u, &v);
        adiciona_aresta(u, v);
    }

    // Executa o algoritmo a partir da rodada 0 e guarda o tamanho final da equipe.
    j = 0;
    equipe = subgrafoMaximoInduzido(j);

    // Imprime o número de membros do maior subgrafo válido encontrado.
    printf("%d", equipe);

    return 0;
}
