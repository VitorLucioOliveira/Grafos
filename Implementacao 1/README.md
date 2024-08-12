
\documentclass{article}
\usepackage[utf8]{inputenc}

\title{Documentação}
\date{}

\begin{document}

\maketitle

\section*{Introdução}
Todos os arquivos de código possuem a classe \texttt{Node}, a classe da sua respectiva estrutura e uma função \texttt{Main} para testes.

\section*{Lista Encadeada}

\subsection*{Classe Node}
\begin{itemize}
    \item Possui 2 atributos:
    \begin{itemize}
        \item \texttt{Elemento}: do tipo inteiro para armazenar os dados;
        \item Um ponteiro \texttt{Proximo} para apontar para o próximo nó.
    \end{itemize}
\end{itemize}

\subsection*{Classe Lista}
\begin{itemize}
    \item Possui o atributo \texttt{Raiz}, que é um ponteiro de \texttt{Node}.
    \item Possui 3 métodos para inserção:
    \begin{itemize}
        \item \texttt{Inserir}: Insere o elemento em ordem crescente;
        \item \texttt{InserirInicio}: Insere o elemento no início;
        \item \texttt{InserirFim}: Percorre a lista até achar o último nó sem apontamento e aponta ele para um nó com o elemento criado.
    \end{itemize}
    \item Possui 3 métodos para remoção:
    \begin{itemize}
        \item \texttt{Remover}: Percorre a lista até achar o nó anterior ao nó do elemento escolhido, reapontando-o para o nó próximo ao nó do elemento escolhido;
        \item \texttt{RemoverInicio}: Muda o elemento da raiz para o nó \texttt{Proximo} que está apontando;
        \item \texttt{RemoverFim}: Percorre a lista até achar o anterior ao último nó sem apontamento e desaponta o último nó dele.
    \end{itemize}
    \item Possui funções para imprimir todos os elementos da lista e para buscar um elemento específico.
\end{itemize}

\section*{Pilha}

\subsection*{Classe Node}
\begin{itemize}
    \item Possui 2 atributos:
    \begin{itemize}
        \item \texttt{Elemento}: do tipo inteiro para armazenar os dados;
        \item Um ponteiro \texttt{Proximo} para apontar para o próximo nó.
    \end{itemize}
\end{itemize}

\subsection*{Classe Pilha}
\begin{itemize}
    \item Possui o atributo \texttt{Raiz}, que é um ponteiro de \texttt{Node}.
    \item Possui métodos para inserção e remoção:
    \begin{itemize}
        \item \texttt{InserirFim}: Percorre a pilha até achar o último nó sem apontamento e aponta ele para um nó com o elemento criado;
        \item \texttt{RemoverFim}: Percorre a pilha até achar o anterior ao último nó sem apontamento e desaponta o último nó dele.
    \end{itemize}
    \item Possui funções para imprimir todos os elementos e para buscar um elemento específico.
\end{itemize}

\section*{Fila}

\subsection*{Classe Node}
\begin{itemize}
    \item Possui 2 atributos:
    \begin{itemize}
        \item \texttt{Elemento}: do tipo inteiro para armazenar os dados;
        \item Um ponteiro \texttt{Proximo} para apontar para o próximo nó.
    \end{itemize}
\end{itemize}

\subsection*{Classe Fila}
\begin{itemize}
    \item Possui o atributo \texttt{Raiz}, que é um ponteiro de \texttt{Node}.
    \item Possui métodos para inserção e remoção:
    \begin{itemize}
        \item \texttt{InserirFim}: Percorre a fila até achar o último nó sem apontamento e aponta ele para um nó com o elemento criado;
        \item \texttt{RemoverInicio}: Muda o elemento da raiz para o nó \texttt{Proximo} que está apontando.
    \end{itemize}
    \item Possui funções para imprimir todos os elementos e para buscar um elemento específico.
\end{itemize}

\section*{Matriz}

\subsection*{Classe Node}
\begin{itemize}
    \item Possui 5 atributos:
    \begin{itemize}
        \item \texttt{Elemento}: do tipo inteiro para armazenar os dados;
        \item Um ponteiro \texttt{esq};
        \item Um ponteiro \texttt{dir};
        \item Um ponteiro \texttt{cima};
        \item Um ponteiro \texttt{baixo}.
    \end{itemize}
\end{itemize}

\subsection*{Classe Matriz}
\begin{itemize}
    \item Possui o atributo \texttt{Raiz}, que é um ponteiro de \texttt{Node}.
    \item Precisa ser dado parâmetros para o tamanho da matriz para inicializá-la.
    \item Possui os seguintes métodos:
    \begin{itemize}
        \item \texttt{InserirMatriz}: Percorre a matriz a partir da raiz até encontrar o nó na posição desejada e atualiza o seu elemento;
        \item \texttt{BuscarMatriz}: Percorre a matriz a partir da raiz em busca de um nó com o elemento. Retorna um ponteiro para o nó se o elemento for encontrado, ou \texttt{null} caso contrário;
        \item \texttt{RemoverMatriz}: Usa a função \texttt{BuscarMatriz} para encontrar o nó com o elemento. Se o nó for encontrado, ajusta os ponteiros dos nós adjacentes para remover o nó da matriz;
        \item \texttt{getElemento}: Usa a função \texttt{BuscarMatriz} para verificar se o valor existe na matriz. Imprime uma mensagem indicando se o valor foi encontrado ou não;
        \item \texttt{print}: Percorre toda a matriz a partir da raiz e imprime os valores dos nós em formato de matriz. Usa dois laços \texttt{while} aninhados para percorrer a matriz por linhas e colunas.
    \end{itemize}
\end{itemize}

\end{document}
```