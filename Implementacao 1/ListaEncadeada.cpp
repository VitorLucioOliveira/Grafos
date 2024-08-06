#include <iostream>

//--------Node--------//
class Node
{
public:
    // Atributos
    int elemento;
    Node *proximo;

    // Construtor
    Node(int elemento)
    {
        this->elemento = elemento;
        this->proximo = nullptr;
    }
};

//--------ListaEncadeada--------//
class Lista
{
private:
    Node *raiz; // Atributo

public:
    Lista() // Construtor
    {
        this->raiz = nullptr;
    }

    void inserir(int elemento)
    {
        Node *novo = new Node(elemento);

        // Se a lista estiver vazia, o novo elemento é a raiz
        if (this->raiz == nullptr)
        {
            this->raiz = novo;
        }
        // Se o novo elemento deve ser inserido no início da lista
        else if (elemento <= this->raiz->elemento)
        {
            novo->proximo = this->raiz;
            this->raiz = novo;
        }
        else
        {
            Node *atual = this->raiz;

            while (atual->proximo != nullptr && elemento > atual->proximo->elemento) // Percorre a lista até encontrar a posição correta
            {
                atual = atual->proximo;
            }

            // Insere o node em ordem crescente
            novo->proximo = atual->proximo;
            atual->proximo = novo;
        }

        std::cout << "Elemento " << elemento << " inserido" << std::endl;
    }

    void inserirFim(int elemento)
    {
        Node *novo = new Node(elemento);

        if (this->raiz == nullptr)
        {
            this->raiz = novo; // Se a lista estiver vazia, o novo elemento é a raiz
        }
        else
        {
            Node *atual = this->raiz;         // Ponteiro para percorrer a lista
            while (atual->proximo != nullptr) // Percorre a lista até o elemtento sem proximo
            {
                atual = atual->proximo;
            }
            atual->proximo = novo; // Adiciona o novo elemento
        }

        std::cout << "Elemento " << elemento << " inserido" << std::endl;
    }

    void inserirInicio(int elemento)
    {
        Node *novo = new Node(elemento);

        if (this->raiz == nullptr)
        {
            this->raiz = novo; // Se a lista estiver vazia, o novo elemento é a raiz
        }
        else
        {
            novo->proximo = this->raiz;
            this->raiz = novo;
        }

        std::cout << "Elemento " << elemento << " inserido" << std::endl;
    }

    void remover(int elemento)
    {
        // Verifica se a lista está vazia
        if (this->raiz == nullptr)
        {
            std::cout << "Lista Vazia" << std::endl;
            return;
        }
        else
        {
            // Nos para percorrer a lista
            Node *atual = this->raiz;
            Node *anterior = nullptr;

            // Percorre a lista até encontrar o elemento ou o final da lista
            while (atual != nullptr && atual->elemento != elemento)
            {
                anterior = atual;       // Guarda o elemento anterior
                atual = atual->proximo; // Atualiza o proximo elemento
            }

            // Elemento não encontrado
            if (atual == nullptr)
            {
                std::cout << "Elemento não encontrado" << std::endl;
                return;
            }
            // Elemente encontrado na Raiz
            else if (raiz->elemento == elemento)
            {
                this->raiz = atual->proximo;
                delete atual;
            }
            // Elemento encontrado
            else
            {
                anterior->proximo = atual->proximo;
                delete atual;
            }

            std::cout << "Elemento " << elemento << " removido" << std::endl;
        }
    }

    void removerInicio()
    {
        // Verifica se a lista está vazia
        if (this->raiz == nullptr)
        {
            std::cout << "Lista Vazia" << std::endl;
            return;
        }
        else
        {
            int elemento = raiz->elemento; // salva o elemento
            Node *temp = raiz;             // Salva a raiz atual
            raiz = raiz->proximo;          // Remove a Raiz
            delete temp;                   // Libera a memória

            std::cout << "Elemento " << elemento << " removido" << std::endl;
        }
    }

    int removerFim()
    {
        // Verifica se a lista está vazia
        if (this->raiz == nullptr)
        {
            std::cout << "Lista Vazia" << std::endl;
            return;
        }
        else if (this->raiz->proximo == nullptr)
        {
            // Se a lista tem apenas um elemento
            int elemento = this->raiz->elemento;
            delete this->raiz;
            this->raiz = nullptr;
            std::cout << "Elemento " << elemento << " removido" << std::endl;
        }
        else
        {
            // Nos para percorrer a lista
            Node *atual = this->raiz;
            Node *anterior = nullptr;

            // Percorre a lista até o final
            while (atual->proximo != nullptr)
            {
                anterior = atual;
                atual = atual->proximo; // Atualiza o proximo elemento
            }

            int elemento = atual->elemento; // Salva o elemento
            anterior->proximo = nullptr;    // Tira o atual da lista
            delete atual;

            std::cout << "Elemento " << elemento << " removido" << std::endl;
        }
    }

    void print()
    {
        if (this->raiz == nullptr)
        {
            std::cout << "Lista Vazia" << std::endl;
            return;
        }

        Node *atual = this->raiz; // Ponteiro para percorrer a lista
        while (atual != nullptr)  // Percorre a lista até o final
        {
            std::cout << atual->elemento << " "; // printa o elemento
            atual = atual->proximo;              // Atualiza o proximo elemento
        }
        std::cout << std::endl; // Pula linha pra finalizar
    }

    bool busca(int elemento)
    {
        if (this->raiz == nullptr)
        {
            std::cout << "Lista Vazia" << std::endl;
            return false;
        }

        Node *atual = this->raiz;
        while (atual != nullptr)
        {
            if (atual->elemento == elemento)
            {
                return true;
            }

            atual = atual->proximo;
        }

        return false;
    }
};

int main()
{
    // Inicializa a lista E a opção
    int opcao;
    Lista lista;

    do
    {
        // Menu
        std::cout << std::endl;
        std::cout << "1) Inserir Elemento na Lista" << std::endl;
        std::cout << "2) Inserir no Final da Lista" << std::endl;
        std::cout << "3) Inserir no Inicio da Lista" << std::endl;
        std::cout << std::endl;
        std::cout << "4) Remover Elemento da Lista" << std::endl;
        std::cout << "5) Remover do Inicio da Lista" << std::endl;
        std::cout << "6) Remover do Final da Lista" << std::endl;
        std::cout << std::endl;
        std::cout << "7) Imprimir Lista" << std::endl;
        std::cout << "8) Buscar na Lista" << std::endl;
        std::cout << "0) Sair" << std::endl;

        // Le a opção
        std::cout << "\nOpção: ";
        std::cin >> opcao;
        std::cout << std::endl;

        switch (opcao)
        {
        case 1:
        {
            // Recebe o elemento
            int elemento;
            std::cout << "Digite o elemento: ";
            std::cin >> elemento;

            // Inserir
            lista.inserir(elemento);
            break;
        }
        case 2:
        {
            // Recebe o elemento
            int elemento;
            std::cout << "Digite o elemento: ";
            std::cin >> elemento;

            // Inserir
            lista.inserirFim(elemento);
            break;
        }
        case 3:
        {
            // Recebe o elemento
            int elemento;
            std::cout << "Digite o elemento: ";
            std::cin >> elemento;

            // Inserir
            lista.inserirInicio(elemento);
            break;
        }
        case 4:
        {
            // Recebe o elemento
            int elemento;
            std::cout << "Digite o elemento: ";
            std::cin >> elemento;

            // Remover
            lista.remover(elemento);
            break;
        }
        case 5:
        {
            // Remover
            lista.removerInicio();
            break;
        }
        case 6:
        {
            // Remover
            lista.removerFim();
            break;
        }
        case 7:
        {
            lista.print();
            break;
        }
        case 8:
        {
            // Recebe o elemento
            int elemento;
            std::cout << "Digite o elemento: ";
            std::cin >> elemento;

            // Buscar
            bool encontrado = lista.busca(elemento);
            if (encontrado)
            {
                std::cout << "Elemento " << elemento << " encontrado na lista." << std::endl;
            }
            else
            {
                std::cout << "Elemento " << elemento << " não encontrado na lista." << std::endl;
            }
            break;
        }
        }
    } while (opcao != 0);

    return 0;
}