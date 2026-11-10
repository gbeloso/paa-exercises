# Ordenação e Divisão e Conquista

Dois programas em C com algoritmos clássicos de ordenação e o problema do
subarranjo de soma máxima.

## `sort.c` — Algoritmos de ordenação

Reúne várias ordenações implementadas do zero. O `main` lê `n` e depois `n`
inteiros, ordena o vetor e imprime o resultado. O algoritmo usado é escolhido
descomentando a chamada correspondente dentro do `main`.

Algoritmos disponíveis:

| Função | Algoritmo | Observação |
|--------|-----------|------------|
| `bubble` / `bubbleMin` | Bubble sort | Duas variações de varredura. |
| `selection` / `selectionMax` | Selection sort | Seleção do mínimo e do máximo. |
| `heapSort` | Heap sort | Usa `buildMaxHeap` + `maxHeapify`. |
| `mergeSort` | Merge sort | Também **conta o número de inversões** do vetor. |
| `quickSort` | Quicksort | Particionamento de Lomuto. |

Há ainda `printHeap`, que imprime a estrutura do heap de forma hierárquica para
depuração.

## `maxSubArray.c` — Subarranjo de soma máxima

Encontra o subarranjo contíguo de maior soma. A recursão resolve o problema para
os `n-1` primeiros elementos e combina esse resultado com o melhor **sufixo**
terminando na posição atual, atualizando o máximo global. Além da soma, o
programa também reporta os índices de início e fim do subarranjo máximo e do
sufixo máximo.

- Entrada: `n` seguido de `n` números reais.
- Saída: a soma e o intervalo do subarranjo máximo e do sufixo máximo.

## Compilar e executar

```bash
make                       # compila os fontes

./sort < entrada.txt       # ordenação
./maxSubArray < entrada.txt # subarranjo máximo
```

## Arquivos

```
.
├── Makefile
├── sort.c          # algoritmos de ordenação
├── maxSubArray.c   # subarranjo de soma máxima
└── README.md
```
