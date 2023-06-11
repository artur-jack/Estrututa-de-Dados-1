## Algoritmos de Ordenação a ser estudados

- Bubble Sort
- Selection Sort
- Insertion Sort
- Shell Sort
- Quick Sort
- Merge Sort

## Algoritmos de Ordenação Estáveis

    São Algoritmos que garantem que itens com mesmo valor/chave permanaçam na mesma posição relativa no vetor.

## Selection Sort

        0   1   2   3   4   5
    | 30 | 45 | 60 | 10 | 5 | 92 |

    Ele vai no vetor procurando o menor elemento, quando ele encontra ele joga pro início, vai pra segunda posição e procura o menor elemento do subvetor e joga nessa posição assim sucessivamente.

<p align="center">
    <img width="80" src="https://upload.wikimedia.org/wikipedia/commons/9/94/Selection-Sort-Animation.gif"> 
</p>

## Bubble Sort

    A ideia é percorrer o vetor diversas vezes e comparando em pares. Se o j+1 < j, troca e implementa 1 no j, se não j++. A cada passagem fazer flutuar para o topo o maior elemento da sequência. Essa movimentação lembra a forma como as bolhas em um tanque de água procuram seu próprio nível, e disso vem o nome do algoritmo.

    No melhor caso, o algoritmo executa n operações relevantes, onde n representa o número de elementos do vetor. No pior caso, são feitas n^2 operações. A complexidade desse algoritmo é de ordem quadrática. Por isso, ele não é recomendado para programas que precisem de velocidade e operem com quantidade elevada de dados.

<p align="center">
    <img width="250" src="https://i.stack.imgur.com/XNbE0.gif"> 
</p>
