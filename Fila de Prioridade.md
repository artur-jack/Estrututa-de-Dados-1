# Fila de Prioridades

É uma estrutura de dados com duas operações básicas, inserir novo elemento e remover o com maior prioridade.

### Caracteristicas:

- É um tipo abstrato de dados
- Operações envolvem um grande volume de informações, que precisam de alguma ordenação, mas não precisam necessárimente estar totalmente ordenadas.

### Operações:

- Remover o máximo valor de chave (prioridade).
    - em caso de chaves duplicadas, máximo é qualquer chave com maior valor.
- Inserir chaves.

### **Propriedades PQ** (Priority Queue)

Um item K é máximo se nenhum item é extritamente maior que K e mínimo se nenhum item for estritamente menor que K. Podemos ter mais de um item máximo ou mínimo. Ou seja podem ter vários itens com a mesma prioridade

- Uma fila de prioridade ***Decrescente*** é ***PQ máximo*** 
- Uma fila de prioridade ***Crescente*** é ***PQ mínimo***

### **Implementações:**

**Usando listas encadeadas:**

- Se a inserção for ordenada, o custo é O(N).
    - A remoção é rápida, O(1).
- Se a inserção não for ordenada, o custo é barato, O(1).
    - A remoção fica cara, O(N).

**Usando Vetor:**

- O mesmo caso que as listas encadeadas.
- O vetor não ordenado corresponde a um Selction Sort
- Ordenado coresponde a um Insertion Sort

**Heap:**

- Inserção: **lg(n)**
- Remover Máx: **lg(n)**
- Remover X: **lg(n)**
- Encontrar Máx: **1**
- Mudar prioridade de X: **lg(n)**

### **HEAP:**

É um tipo de árvore binária(mas usamos um vetor) para implementar fila de prioridade eficiente. Dois tipos de Heaps, Decrescente(onde o máximo fica no topo) e Crescente(o mínimo fica no topo).

**Ideia:**

Organizar as chaves como em uma árvore binária
completa:
- Todos os níveis exceto o último estão cheios
- Os nós do último nível estão o mais a esquerda
possível
- Cada nó possui filhos com valores menores ou
iguais ao seu
- Raiz: a maior chave da heap
- Não ordena por completo, só garante-se que:
- Quanto mais próximo à raiz, maior a
prioridade
### Propiedade da Heap decrescente:

- O item de qualquer nó é menor ou igual que o item do par.

exemplo:

### Propiedade da Heap crescente:

- O item de qualquer nó é maior ou igual que o item do par.

### Implementações da árvore:

Com listas encadeadas:
- Necessário 3 ponteiros: para os filhos e pai

Com vetor:
- Representação sequencial da árvore
- Níveis da árvore acessada pelos seus índices
- Raiz: posição 1
- Filhos: 2 e 3
- Netos: 4, 5, 6 e 7
- E assim por diante.
- São estruturas mais rígidas, limitadas
- Porém, para heaps, há flexibilidade suficente
para a implementação das operações em tempo
logarítmico
- Remover o valor máximo (ou mínimo)
- Inserir
- Vantagem: acesso direto aos nós sem necessidade
de atualização dos apontadores
git 
### Operações
Prioridade aumentada ou chave inserida
- Inserção nas folhas da heap
- Restauração: subindo na heap

Prioridade diminuída ou chave removida
- Raiz da heap é substituída por uma folha
- Restauração: descendo na heap

Inicialmente violam as condições da heap
- pai com maior valor que seus filhos

Posteriormente, as chaves são reorganizadas para
atender tais requisitos: restauração/conserto da heap

### **Bottom-up** (swim - fixUp):
- Sobe um nó com uma chave maior que seu pai
    - Troca de chave com seu
pai
- Recursivamente, sobe o nó
até um pai maior ou a
raiz

### **Top-down** (sink - fixDown)
- Desce um nó com uma chave menor que um ou ambos os
filhos
    - Troca de chave com o
filho maior
- Recursivamente, desce o
nó até que ambos os
filhos sejam menores (ou
iguais) ou atingir a base

## Heap Sort

### Caracteristicas:

- Sua complexidade é cerca de ***2NlogN + 2N*** comparações
    - 2N na construção da heap
    - 2NlogN no conserto da heap (segunda fase)
- ***In-place***
- ***Não estável***
- Sobre ser adaptativo, Há uma redução das chamadas iterativas na construção
da heap (2N)

**Porém**, na ordenação final (segunda fase) não
contribui no fixDown dos elementos folhas (2N log N)
Complexidade: O(nlogn)

<p align="center">
    <img width="400" src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcRDWkGb1r8vmtfIAne749H2pIu4AR-hH_bPrze88nlclrUTp8VjawhdqFqqSrysw9gyKhQ&usqp=CAU"> 
</p>

<p align="center">
    <img width="400" src="https://saulo.arisa.com.br/wiki/images/0/05/Heap.png"> 
</p>