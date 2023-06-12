# Algoritmos de Ordenação

- Bubble Sort
- Selection Sort
- Insertion Sort
- Shell Sort
- Quick Sort
- Merge Sort

## Complexidade Assintótica

* o(n²)
    - Adequado para arquivos pequenos
    - Muitas comparações, porém simples
* o(n log n)
    - Adequado para arquivos grandes
    - Menos comparações, porém comparações complexas

## Algoritmos de Ordenação Estáveis

São Algoritmos que garantem que itens com mesmo valor/chave permanaçam na mesma posição relativa no vetor. É importante quando se tem muitas chaves e para manter a prévia ordenação das mesmas.

## Adaptatividade

É adaptativo quando a ordenação existente é aproveitada.

## Memória Extra

A quantidade de memória extra usada na
ordenação é um fator que afeta o tempo de
execução

**In-place:** utiliza a própia estrutura sem usar memória extra, (exceto por uma pequena pilha de execução ou algumas variáveis auxiliares).

**Quando não é In-place:** quando utiliza uma estrutura extra ou copia o conteúdo para outro array.

## Selection Sort 

Ele vai no vetor procurando o menor elemento, quando ele encontra ele joga pro início, vai pra segunda posição e procura o menor elemento do subvetor e joga nessa posição assim sucessivamente.

Sua complexidade assintótica é **o(n²)**. O que significa que ele não é eficiente para grandes conjuntos de dados.

<p align="center">
    <img width="80" src="https://upload.wikimedia.org/wikipedia/commons/9/94/Selection-Sort-Animation.gif"> 
</p>

No quesito adaptatividade ele **não é adaptativo**, pois não leva em consideração o estado inicial dos elementos a serem ordenados.

Quanto à característica de ser "in-place", o selection sort é considerado **in-place**, pois a ordenação ocorre diretamente no array de entrada, sem a necessidade de utilizar uma estrutura de dados adicional. Isso significa que o algoritmo não requer espaço adicional proporcional ao tamanho do conjunto de dados.

## Bubble Sort

A ideia é percorrer o vetor diversas vezes e comparando em pares. Se o j+1 < j, troca e implementa 1 no j, se não j++. A cada passagem fazer flutuar para o topo o maior elemento da sequência. Essa movimentação lembra a forma como as bolhas em um tanque de água procuram seu próprio nível, e disso vem o nome do algoritmo.

No melhor caso, o algoritmo executa o(n) operações relevantes, onde n representa o número de elementos do vetor. No pior caso, são feitas o(n²) operações. A complexidade desse algoritmo é de ordem quadrática **o(n²)**. Por isso, ele não é recomendado para programas que precisem de velocidade e operem com quantidade elevada de dados.

<p align="center">
    <img width="250" src="https://i.stack.imgur.com/XNbE0.gif"> 
</p>

Ele **não é adaptativo**, pois não leva em consideração o estado inicial dos elementos a serem ordenados.

Além de também ser **in-place**, pois a ordenação ocorre diretamente no array de entrada, sem a necessidade de utilizar espaço adicional. Assim como o selection sort, o bubble sort não é considerado eficiente para conjuntos de dados grandes.

## Insertion Sort

Esse é o que tem o melhor resultado comparado com os dois já mostrados. Apesar de ser um algoritmo elementar, ele é importante para implementação de algoritmos mais complexos.

Ele pega um valor do vetor (começando pelo segundo elemento, pois o primeiro já é ordenado) e coloca numa variavel auxiliar(tmp, i=1), vê se esse valor(tmp) é menor que seus antecessores e se for, os valores maiores sobem e j--. Esse valor(tmp) é recolocado em v[j] se seu antecessor for <= que tmp.

Sua complexidade assintótica no pior caso e no caso médio é de **O(n²)**, onde "n" é o tamanho do conjunto de dados a ser ordenado. No entanto, no melhor caso, quando o conjunto de dados já está quase ordenado, o insertion sort tem uma complexidade de tempo de O(n), o que o torna eficiente para conjuntos de dados pequenos ou quase ordenados.

<p align="center">
    <img width="200" src="https://upload.wikimedia.org/wikipedia/commons/0/0f/Insertion-sort-example-300px.gif"> 
</p>

O insertion sort é considerado um algoritmo **adaptativo**. Isso significa que, se o conjunto de dados já estiver parcialmente ordenado, o insertion sort realizará menos comparações e trocas, aproveitando a ordem parcial existente.

Além disso **é estável**, o que significa que elementos iguais não são reordenados durante a classificação. E **in-place**, pois a ordenação ocorre diretamente no array de entrada, sem a necessidade de utilizar espaço adicional.

## Shell Sort

Tem como ideia a ordenação parcial a cada passagem utilizando um insertion sort(um pouco modificado) onde adiciona um parametro h nesse insert sort que diz o número de saltos a serem feitos.Quando h=1, corresponde ao insertion sort padrão. 

- Diminui o número de movimentações
- Troca de itens que estão distantes um do outro
- Separados a h distância
- São rearranjados, resultando uma sequencia ordenada para a distância h (h-ordenada)
- Quando h=1, corresponde ao Insertion Sort
- A dificuldade é determinar o valor de h

A escolha dos saltos é importante para o desempenho do algoritmo.

- sequencias múltiplas de 2 não performam
bem:
- 1 2 4 8 16 32 64 128 256...
- itens em posições pares não confrontam itens em posições ímpares até o fim do processo e, vice e versa
- Implementação é similar ao algoritmo de inserção

![Shell Sort](https://j.gifs.com/vQDGWb.gif)

![Assistir animação completa](https://www.youtube.com/embed/qzXAVXddcPU)
