# Documentação
- Todos os arquivos de codigo possuem a classe Node, a classe da sua respectiva estrutura e uma função Main para testes;

## Lista Encadeada

### Classe Node
- Possui 2 atributos:
    - "Elemento" do tipo inteiro para armazenar os dados;
    - Um ponteiro "Proximo" para apontar para o proximo nó;

### Classe Lista
- Possui o atributo Raiz, que é um ponteiro de Node;

- Possui 3 metodos para Inscerção:
    - Inserir -> Inserir o elemento em ordem crescente;
    - InserirInicio -> Inserir o elemento no inicio;
    - InserirFim -> Percorre a Lista até achar o ultimo nó sem apontamento e aponta ele para um nó com o elemento criado ;

- Possui 3 metodos para Remoção:
    - Remover -> Percorre a Lista até achar o nó anterior ao nó do elemento escolhido, reapontando ele para o nó proximo ao nó do elemento escolhido   ;
    - RemoverInicio -> Muda o  elemento da raiz para o nó "proximo" que esta apontando  ;
    - RemoverFim -> Percorre a Lista até achar o anterior ao ultimo nó sem apontamento e desaponta o ultimo nó dele ;

- Possui funções para imprimir todos os elementos da lista e para buscar um elemento específico.

## Pilha

### Classe Node
- Possui 2 atributos:
    - "Elemento" do tipo inteiro para armazenar os dados;
    - Um ponteiro "Proximo" para apontar para o proximo nó;

### Classe Pilha
- Possui o atributo Raiz, que é um ponteiro de Node;

- Possui  metodos para Inscerção e Remoção:
    - InserirFim -> Percorre a Pilha até achar o ultimo nó sem apontamento e aponta ele para um nó com o elemento criado ;
    - RemoverFim -> Percorre a Pilha até achar o anterior ao ultimo nó sem apontamento e desaponta o ultimo nó dele ;

- Possui funções para imprimir todos os elementos e para buscar um elemento específico.


## Fila
### Classe Node
- Possui 2 atributos:
    - "Elemento" do tipo inteiro para armazenar os dados;
    - Um ponteiro "Proximo" para apontar para o proximo nó;

### Classe Fila
- Possui o atributo Raiz, que é um ponteiro de Node;

- Possui metodos para Inscerção e Remoção:
   
    - InserirFim -> Percorre a Fila até achar o ultimo nó sem apontamento e aponta ele para um nó com o elemento criado ;
    - RemoverInicio -> Muda o elemento da raiz para o nó "proximo" que esta apontando  ;

- Possui funções para imprimir todos os elementos e para buscar um elemento específico.


## Matriz
### Classe Node
- Possui 5 atributos:
    - "Elemento" do tipo inteiro para armazenar os dados;
    - Um ponteiro "esq";
    - Um ponteiro "dir";
    - Um ponteiro "cima";
    - Um ponteiro "baixo";

### Classe Matriz
- Possui o atributo Raiz, que é um ponteiro de Node;

- Precisa ser dado parametros para o tamanho da matriz para inicializa-la;

- Possui os sequintes metodos :
    - InserirMatriz -> Percorre a matriz a partir da raiz até encontrar o nó na posição desejada e atualiza o seu  elemento ;
   
    - BuscarMatriz -> Percorre a matriz a partir da raiz em busca de um nó com o  elemento. Retorna um ponteiro para o nó se o  elemento for encontrado, ou null caso contrário.
    
    - RemoverMatriz -> Usa a função buscarMatriz para encontrar o nó com o elemento. Se o nó for encontrado, ajusta os ponteiros dos nós adjacentes para remover o nó da matriz;
  
    - getElemento -> sa a função buscarMatriz para verificar se o valor existe na matriz. Imprime uma mensagem indicando se o valor foi encontrado ou não.

    - print -> Percorre toda a matriz a partir da raiz e imprime os valores dos nós em formato de matriz. Usa dois laços while aninhados para percorrer a matriz por linhas e colunas.
