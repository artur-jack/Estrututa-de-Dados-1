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

Sua complexidade assintótica é **o(n²)**. O que significa que ele não é eficiente para grandes conjuntos de dados. Além de **não ser estável**.

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

Ele **não é adaptativo**, pois não leva em consideração o estado inicial dos elementos a serem ordenados.E também **é estável**, pois preserva a ordem relativa dos elementos iguais em sua ordenação. 

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

É um algoritmoque tem melhor desempenho comparado aos algoritmos elementares, mas ainda não é tão eficiente quanto algoritmos mais avançados como o QuickSort e o MergeSort.

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


<p align="center">
    <img width="400" src="https://j.gifs.com/vQDGWb.gif"> 
</p>

https://www.youtube.com/embed/qzXAVXddcPU

É um algoritmo **adaptativo e não estável**, que no pior caso, shellsort não é
necessariamente quadrático (Sedgewick)
- As comparações são proporcionais a **O(n^(3/2)) CASO MÉDIO**
- Pior caso com pior sequencia de intervalos h: **O(n²) PIOR CASO**
- Melhor caso com pior sequencia de intervalos h: **O(n log2 n) MELHOR CASO**
- Pratt, Vaughan Ronald (1979). Shellsort and Sorting Networks (Outstanding Dissertations in the Computer Sciences)
- Melhor caso com uma boa sequencia de
intervalos h: O(n log n)

Quanto à sua operação in-place, o Shell Sort **pode ser implementado de forma in-place**, o que significa que não requer espaço adicional além do array original que está sendo ordenado. No entanto, algumas variantes do algoritmo podem exigir espaço adicional para armazenar variáveis auxiliares.

## Merge Sort

Algoritmo baseado na operação: merge (combinar, juntar,
fundir)

Utiliza do método dividir e conquistar. Divide em pequenas partes e ordena essas partes, depois combina essas pequenas partes já ordenadas até formar uma única sequência ordenada. Geralmente é utilizada uma abordagem recursiva que cria arrays auxiliares para a mesclagem dos subconjuntos. 

<p align="center">
    <img width="300" src="https://upload.wikimedia.org/wikipedia/commons/c/cc/Merge-sort-example-300px.gif"> 
</p>

### **Abordagem Top-Down** (abordagem recursiva)

- A cada chamada, divide a entrada em sub-vetores para serem ordenados
- merge_sort(int *v, int l, int r)
- Quando chegar em um tamanho unitário, ou seja, ordenado em 1
- Volta fazendo o merge ordenado
- merge(int *v, int l, int meio, int r)
- Utiliza um vetor auxiliar

### Sobre suas características: 

- Sua complexidade é **O(n log n)** para todos os casos.
- **Não é adaptativo**.
- É um algoritmo **estável**.
- **Não é in-place**, pois requer espaço adicional para realizar as operações de divisão e mesclagem dos subconjuntos. 

## Quick Sort

Assim como o merge sort ele também usa o método dividir e conquistar, particionando o vetor em sub-vetores e ordenando cada sub-vetor independentemente.

### Merge X Quick

#### Merge:
    - Divide 
    - Ordena separadamente
    - Combina reordenando, conquistando um vetor mais ordenado
    - Repete

#### Quick:

    - Rearranja
    - Conquista um elemento ordenado e dois subvetores pseudo-ordenados
    - Divide
    - Repete

<p align="center">
    <img width="280" src="https://upload.wikimedia.org/wikipedia/commons/9/9c/Quicksort-example.gif"> 
</p>

Ideia:
- Particionar (separar) - processo crucial no quick
- Escolhar um elemento de referência: pivot
- Rearranjar todos elementos posteriores ao pivot
- Reposicionar o pivot
- Dividir o vetor em dois
- Repetir o processo até ordenar todos os elementos

Em resumo, a função quickSort divide o vetor em subvetores menores em torno de um pivô e, em seguida, recursivamente, ordena os subvetores à esquerda e à direita do pivô até que todo o vetor esteja ordenado.

O algoritmo Quicksort é conhecido por sua eficiência média e é amplamente utilizado para ordenar vetores em diversas aplicações.

### Características:

- **Não estável.**
- **Não é adaptativo**.  cada elemento na sua posição correta, não contribui para a ordenação do restante uma vez que a próxima divisão ocorrerá somente uma posição à frente do particiona atual.

A complexidade assintótica do QuickSort depende da implementação e da escolha do pivô. Em média, seu desempenho é muito bom, com complexidade de tempo esperada de O(n log n).

- Sua complexidade em **média é O(n log n)**.
- **Pior caso**: n²/2 comparações. **(O(n²))**
    - Muito itens repetidos, (quase) ordenados, reverso caem nos piores casos

Para fugir do pior caso, estratégias como a escolha do **pivô mediano ou a seleção aleatória do pivô** são frequentemente utilizadas. Além disso, técnicas como o QuickSort de três vias ou o QuickSort com inserção podem ser aplicadas para melhorar o desempenho em certas situações, tornando o algoritmo mais eficiente em casos reais.

### Exemplo de uso:

Suponha que temos o seguinte vetor: [5, 2, 8, 9, 3, 1].
Chamada da função quickSort(vetor, 0, 5):

Primeira chamada recursiva:

Chama a função partition e retorna o índice p (nesse exemplo, suponha que seja 2).

Chama quickSort(vetor, 0, 1), que ordena o subvetor [5, 2].

Chama quickSort(vetor, 3, 5), que ordena o subvetor [9, 3, 1].

Chamada recursiva de quickSort(vetor, 0, 1):

Chama a função partition e retorna o índice p (nesse exemplo, suponha que seja 1).
Chama quickSort(vetor, 0, 0), que ordena o subvetor [5].

Chama quickSort(vetor, 2, 1) (não faz nada, pois r <= l).

Chamada recursiva de quickSort(vetor, 3, 5):

Chama a função partition e retorna o índice p (nesse exemplo, suponha que seja 4).

Chama quickSort(vetor, 3, 3) (não faz nada, pois r <= l).

Chama quickSort(vetor, 5, 5) (não faz nada, pois r <= l).

Ao final das chamadas recursivas, o vetor resultante será [1, 2, 3, 5, 8, 9], que está ordenado de forma crescente.