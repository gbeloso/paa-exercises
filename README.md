# PAA — Exercícios

Coleção de exercícios de **Projeto e Análise de Algoritmos (PAA)** da Unifesp,
implementados em C. Cada pasta é independente e traz seu próprio `Makefile`.

## Conteúdo

| Pasta | Tema | Descrição |
|-------|------|-----------|
| [`Ordenacao/`](Ordenacao) | Ordenação e divisão e conquista | Algoritmos clássicos de ordenação e o problema do subarranjo máximo. |
| [`P2/`](P2) | Grafos | Maior subgrafo induzido com grau mínimo `K` (k-core). |
| [`P3/`](P3) | Backtracking | Posicionamento de guaritas de vigilância (permutações). |

## Detalhe de cada exercício

### Ordenacao

Dois programas:

- **`sort.c`** — reúne várias ordenações implementadas do zero: bubble sort,
  selection sort, heap sort, merge sort (com contagem de inversões) e quicksort.
  O `main` lê `n` e `n` inteiros e ordena o vetor; o algoritmo usado é escolhido
  descomentando a chamada correspondente.
- **`maxSubArray.c`** — resolve o problema do subarranjo de soma máxima usando
  uma recursão que combina o máximo global com o melhor sufixo, em tempo linear.

Detalhes em [`Ordenacao/README.md`](Ordenacao/README.md).

### P2 — Subgrafo máximo induzido

Dado um grafo de relações, encontra a maior "equipe" (subgrafo induzido) em que
todo vértice tem grau `>= K`. A estratégia é o algoritmo do **k-core**: remover
repetidamente os vértices com grau abaixo de `K` até o grafo estabilizar.

Entrada: `N P K` (vértices, arestas, grau mínimo) seguidos das `P` arestas.
Saída: o número de membros do maior subgrafo válido. Detalhes em
[`P2/README.md`](P2/README.md).

### P3 — Vigilância

Lista todas as formas de posicionar o número mínimo de guaritas que cobrem uma
grade `N x N`, respeitando `M` pontos obrigatórios. Como cada guarita cobre uma
linha e uma coluna inteiras, o problema equivale a gerar **permutações** das
linhas, resolvido por **backtracking com poda**. Detalhes e casos de teste em
[`P3/README.md`](P3/README.md).

## Compilar e executar

Cada pasta tem um `Makefile`. O padrão geral:

```bash
cd P3        # ou P2, Ordenacao
make         # compila
```

No P3 há também testes automatizados:

```bash
cd P3
make run     # roda os casos de teste e compara com a saída esperada
make clean   # remove artefatos de compilação
```

## Observações

- Código em C (padrão C11), compilado com `gcc`.
- Os artefatos de compilação (`.o`, executáveis, etc.) são ignorados pelo
  [`.gitignore`](.gitignore) e não devem ser versionados.
