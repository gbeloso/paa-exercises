# P2 — Maior Subgrafo Induzido (k-core)

Solução em C para encontrar a maior "equipe" dentro de um grafo de relações:
o maior subgrafo induzido em que **todo vértice tem grau `>= K`**.

## O problema

Modelamos as pessoas como vértices e as relações entre elas como arestas de um
grafo não direcionado. Queremos a maior equipe possível em que cada membro se
relacione com pelo menos `K` outros membros **da própria equipe**.

Isso é exatamente o conceito de **k-core** de um grafo: o maior subgrafo induzido
em que o grau mínimo é `K`.

## Abordagem

Remoção iterativa (peeling):

1. Enquanto existir algum vértice com grau menor que `K`, remova-o.
2. Remover um vértice reduz o grau dos seus vizinhos, o que pode fazer novos
   vértices violarem o grau mínimo.
3. Repita em rodadas até que nenhuma remoção seja necessária. O que sobra é o
   maior subgrafo induzido com grau `>= K`.

A implementação usa uma matriz de adjacência e um vetor de graus; vértices
removidos são marcados com grau `-1`. As rodadas são feitas por recursão até
estabilizar.

## Formato de entrada e saída

**Entrada**

- Primeira linha: `N P K` — número de vértices, número de arestas e grau mínimo.
- Próximas `P` linhas: dois inteiros `u v` indicando uma aresta entre `u` e `v`.

**Saída**

- Um único inteiro: o número de membros do maior subgrafo válido (0 se não
  existir equipe possível).

## Compilar e executar

```bash
make                 # compila p2.c -> p2
./p2 < entrada.txt   # executa lendo de um arquivo de entrada
```

## Arquivos

```
.
├── Makefile
├── p2.c        # solução (k-core por remoção iterativa)
└── README.md
```
