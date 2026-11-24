# Problema 4 — Power2coin

Solução em C para o problema de minimizar a quantidade de moedas transferidas
em uma transação da moeda digital fictícia **Power2coin (PW2C)**.

## O problema

Para pagar um valor `N` em PW2C, são criadas moedas cujos valores são sempre
**potências de 2** e **distintos** em cada direção. O pagamento pode usar moedas
nos dois sentidos: a origem envia valores e o destino pode devolver "troco".
O objetivo é encontrar a **menor quantidade total de moedas** transferidas
(somando as duas direções) para que o balanço líquido seja exatamente `N`.

Em termos matemáticos, isso equivale a escrever `N` como uma soma de potências de
2 com coeficientes `+1` e `-1` (cada potência usada no máximo uma vez), com o
menor número possível de termos não-nulos. Essa é a representação binária com
sinal de peso mínimo, conhecida como **NAF (Non-Adjacent Form)**, que é única e
comprovadamente ótima.

> Exemplo: `30 = 32 − 2`, ou seja, duas moedas (uma de 32 enviada pela origem e
> uma de 2 devolvida como troco), em vez de `30 = 2 + 4 + 8 + 16`, que usaria
> quatro.

## Abordagem

Algoritmo guloso sobre os bits de `N`, do menos ao mais significativo:

- Bit `0`: não usa moeda.
- Bit `1` com próximo bit `0`: usa uma moeda `+2^i`.
- Bit `1` com próximo bit `1` (corrida de 1s): usa uma moeda `−2^i` e propaga o
  "vai-um" para cima, trocando a corrida de 1s por um único bit mais alto.

A propagação do vai-um é feita somando `1` ao valor restante antes de dividir por
2, o que faz o carry subir naturalmente sem precisar de um vetor de bits. A
resposta é a quantidade de moedas (termos não-nulos) contados ao longo do
processo. Complexidade `O(log N)`.

## Formato de entrada e saída

**Entrada**
- Uma única linha com o inteiro `N` (`1 ≤ N ≤ 10.000`), o valor a ser pago.

**Saída**
- Uma linha com a quantidade mínima de moedas a serem transacionadas.

### Exemplos

| Entrada | Saída |
|:-------:|:-----:|
| 8       | 1     |
| 30      | 2     |
| 100     | 3     |
| 999     | 4     |

## Compilar e executar

O projeto inclui um `Makefile`.

```bash
# compila p4.c -> executável p4
make

# roda os exemplos do enunciado (8, 30, 100, 999)
make run

# remove o executável
make clean
```

Execução manual com uma entrada própria:

```bash
echo 30 | ./p4
```

## Estrutura do projeto

```
.
├── Makefile                 # alvos build / run / clean
├── p4.c                     # solução (guloso / NAF)
├── README.md
└── Lab20261110_Prob4.pdf    # enunciado original
```
