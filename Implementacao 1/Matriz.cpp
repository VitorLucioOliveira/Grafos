#include <iostream>

//--------Node--------//
class Node {
public:
    int elemento;
    Node* dir;
    Node* esq;
    Node* cima;
    Node* baixo;

    // Construtor
    Node(int elemento) {
        this->elemento = elemento;
        this->dir = nullptr;
        this->esq = nullptr;
        this->cima = nullptr;
        this->baixo = nullptr;
    }
};

//--------Matriz--------//
class Matriz {
private:
    Node* raiz;

public:
    Matriz() {
        this->raiz = nullptr;
    }

    // Função para criar uma matriz de tamanho especificado
    void criarMatriz(int linhas, int colunas) {
        if (linhas <= 0 || colunas <= 0) {
            std::cout << "Tamanho inválido" << std::endl;
            return;
        }

        
        Node* linhaAnterior = nullptr;

        for (int i = 0; i < linhas; ++i) {
            Node* colunaAtual = nullptr;
            Node* colunaAnterior = nullptr;

            for (int j = 0; j < colunas; ++j) {
                Node* novo = new Node(0); // Inicializando com 0

                if (i == 0 && j == 0) {
                    this->raiz = novo;
                }

                if (colunaAnterior != nullptr) {
                    colunaAnterior->dir = novo;
                    novo->esq = colunaAnterior;
                }

                if (linhaAnterior != nullptr) {
                    Node* acima = linhaAnterior;
                    for (int k = 0; k < j; ++k) {
                        acima = acima->dir;
                    }
                    acima->baixo = novo;
                    novo->cima = acima;
                }

                if (colunaAtual == nullptr) {
                    colunaAtual = novo;
                }

                colunaAnterior = novo;
            }

            linhaAnterior = colunaAtual;
        }

        std::cout << "Matriz criada com " << linhas << " linhas e " << colunas << " colunas." << std::endl;
    }

    // Função para definir um elemento em uma posição específica
    void InserirMatriz(int linha, int coluna, int elemento) {
        Node* temp = this->raiz;
        for (int i = 0; i < linha; ++i) {
            if (temp == nullptr) {
                std::cout << "Linha fora do limite" << std::endl;
                return;
            }
            temp = temp->baixo;
        }
        for (int j = 0; j < coluna; ++j) {
            if (temp == nullptr) {
                std::cout << "Coluna fora do limite" << std::endl;
                return;
            }
            temp = temp->dir;
        }
        if (temp != nullptr) {
            temp->elemento = elemento;
            std::cout << "Elemento " << elemento << " definido na posição [" << linha << "][" << coluna << "]." << std::endl;
        } else {
            std::cout << "Posição fora do limite" << std::endl;
        }
    }

    // Função para buscar um elemento na matriz
    Node* buscarMatriz(int elemento) {
        Node* linhaAtual = this->raiz;
        while (linhaAtual != nullptr) {
            Node* colunaAtual = linhaAtual;
            while (colunaAtual != nullptr) {
                if (colunaAtual->elemento == elemento) {
                    return colunaAtual;
                }
                colunaAtual = colunaAtual->dir;
            }
            linhaAtual = linhaAtual->baixo;
        }
        return nullptr;
    }

    // Função para obter um elemento específico
    bool getElemento(int elemento) {
        Node* encontrado = buscarMatriz(elemento);
        if (encontrado != nullptr) {
            std::cout << "Elemento " << elemento << " encontrado." << std::endl;
            return true;
        } else {
            std::cout << "Elemento " << elemento << " não encontrado." << std::endl;
            return false;
        }
    }

    // Função para remover um elemento específico
    void remover(int elemento) {
        Node* temp = buscarMatriz(elemento);
        if (temp != nullptr) {
            if (temp->cima != nullptr) {
                temp->cima->baixo = temp->baixo;
            }
            if (temp->baixo != nullptr) {
                temp->baixo->cima = temp->cima;
            }
            if (temp->esq != nullptr) {
                temp->esq->dir = temp->dir;
            }
            if (temp->dir != nullptr) {
                temp->dir->esq = temp->esq;
            }
            delete temp;
            std::cout << "Elemento " << elemento << " removido." << std::endl;
        } else {
            std::cout << "Elemento " << elemento << " não encontrado." << std::endl;
        }
    }

    // Função para imprimir a matriz
    void print() {
        Node* linhaAtual = this->raiz;
        while (linhaAtual != nullptr) {
            Node* colunaAtual = linhaAtual;
            while (colunaAtual != nullptr) {
                std::cout << colunaAtual->elemento << " ";
                colunaAtual = colunaAtual->dir;
            }
            std::cout << std::endl;
            linhaAtual = linhaAtual->baixo;
        }
    }
};

int main() {
    Matriz matriz;
    int linhas = 3, colunas = 3;

    matriz.criarMatriz(linhas, colunas);
    matriz.InserirMatriz(0, 0, 1);
    matriz.InserirMatriz(0, 1, 2);
    matriz.InserirMatriz(0, 2, 3);
    matriz.InserirMatriz(1, 0, 4);
    matriz.InserirMatriz(1, 1, 5);
    matriz.InserirMatriz(1, 2, 6);
    matriz.InserirMatriz(2, 0, 7);
    matriz.InserirMatriz(2, 1, 8);
    matriz.InserirMatriz(2, 2, 9);

    std::cout << "Matriz:" << std::endl;
    matriz.print();

    matriz.remover(5);
    std::cout << "Matriz após remoção:" << std::endl;
    matriz.print();

    return 0;
}
