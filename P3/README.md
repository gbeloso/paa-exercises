# Problema 3 — Vigilância

Solução em C para o problema de posicionamento de guaritas de vigilância em uma
região de Manhattan modelada como uma grade `N x N` de ruas.

## O problema

Cada guarita colocada em uma interseção cobre a linha e a coluna inteiras daquela
interseção. Dado um conjunto de `M` interseções que **obrigatoriamente** recebem
uma guarita, o objetivo é listar todas as formas de posicionar o número **mínimo**
de guaritas que garanta a cobertura total das `N` linhas e `N` colunas.

Como cada guarita cobre uma linha e uma coluna completas, cobrir toda a região
exige exatamente `N` guaritas: uma por coluna, cada uma em uma linha distinta.
Isso equivale a uma **permutação** das linhas, onde a posição `c` da permutação
indica a linha da guarita da coluna `c`. Os `M` pontos obrigatórios apenas fixam
algumas dessas posições; qualquer permutação que respeite esses pontos fixos é
uma solução válida.

> Observação: diferente do problema das N-rainhas, aqui **não** há restrição de
> diagonal — uma guarita cobre apenas linha e coluna. Por isso permutações como
> `1 2 3` são válidas.

## Abordagem

Backtracking com poda:

- `a[coluna] = linha` representa a permutação em construção (`-1` = coluna livre).
- Os pontos obrigatórios são fixados em `a` antes da busca.
- As linhas que sobram são distribuídas nas colunas livres, recursivamente.
- A busca percorre as linhas disponíveis em ordem crescente e preenche a primeira
  coluna livre da esquerda para a direita, o que faz a saída sair diretamente em
  **ordem lexicográfica**.

## Formato de entrada e saída

**Entrada**

- Primeira linha: inteiros `N` (`1 < N ≤ 10`) e `M` (`1 ≤ M ≤ N`).
- Próximas `M` linhas: coordenadas `x y` (linha e coluna) de cada ponto obrigatório.

**Saída**

- Uma linha por combinação válida, com `N` números: a linha da guarita de cada
  coluna, da coluna 1 à coluna `N`.
- As combinações são impressas em ordem lexicográfica.

### Exemplo

Entrada:

```
3 1
2 2
```

Saída:

```
1 2 3
3 2 1
```

## Compilar e executar

O projeto inclui um `Makefile`.

```bash
# compila p3.c -> p3.o -> executável p3
make

# roda os quatro casos de teste em tests/ e compara com a saída esperada
make run

# remove os artefatos de compilação
make clean
```

Execução manual com uma entrada própria:

```bash
./p3 < tests/1.in
```

## Estrutura do projeto

```
.
├── Makefile      # alvos all / run / clean
├── p3.c          # solução (backtracking)
├── README.md
└── tests/        # casos de teste (entrada .in e saída esperada .out)
    ├── 1.in  1.out
    ├── 2.in  2.out
    ├── 3.in  3.out
    └── 4.in  4.out
```
