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

//--------pilha--------//
class Pilha
{
private:
    Node *raiz; // Atributo

public:
    Pilha() // Construtor
    {
        this->raiz = nullptr;
    }



    void inserirFim(int elemento)
    {
        Node *novo = new Node(elemento);

        if (this->raiz == nullptr)
        {
            this->raiz = novo; // Se a pilha estiver vazia, o novo elemento é a raiz
        }
        else
        {
            Node *atual = this->raiz;         // Ponteiro para percorrer a pilha
            while (atual->proximo != nullptr) // Percorre a pilha até o elemtento sem proximo
            {
                atual = atual->proximo;
            }
            atual->proximo = novo; // Adiciona o novo elemento
        }

        std::cout << "Elemento " << elemento << " inserido" << std::endl;
    }

   
    void removerFim()
    {
        // Verifica se a pilha está vazia
        if (this->raiz == nullptr)
        {
            std::cout << "pilha Vazia" << std::endl;
            return;
        }
        else if (this->raiz->proximo == nullptr)
        {
            // Se a pilha tem apenas um elemento
            int elemento = this->raiz->elemento;
            delete this->raiz;
            this->raiz = nullptr;
            std::cout << "Elemento " << elemento << " removido" << std::endl;
        }
        else
        {
            // Nos para percorrer a pilha
            Node *atual = this->raiz;
            Node *anterior = nullptr;

            // Percorre a pilha até o final
            while (atual->proximo != nullptr)
            {
                anterior = atual;
                atual = atual->proximo; // Atualiza o proximo elemento
            }

            int elemento = atual->elemento; // Salva o elemento
            anterior->proximo = nullptr;    // Tira o atual da pilha
            delete atual;

            std::cout << "Elemento " << elemento << " removido" << std::endl;
        }
    }



    void print()
    {
        if (this->raiz == nullptr)
        {
            std::cout << "pilha Vazia" << std::endl;
            return;
        }

        Node *atual = this->raiz; // Ponteiro para percorrer a pilha
        while (atual != nullptr)  // Percorre a pilha até o final
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
            std::cout << "pilha Vazia" << std::endl;
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
    // Inicializa a pilha E a opção
    int opcao;
    Pilha pilha;

    do
    {
        // Menu
        std::cout << std::endl;
        std::cout << "1) Inserir na Pilha" << std::endl;
        std::cout << "2) Remover da Pilha" << std::endl;
        std::cout << std::endl;
        std::cout << "3) Imprimir Pilha" << std::endl;
        std::cout << "4) Buscar na Pilha" << std::endl;
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
            pilha.inserirFim(elemento);
            break;
        }

        case 2:
        {
            // Remover
            pilha.removerFim();
            break;
        }
    
        case 3:
        {
            pilha.print();
            break;
        }
        case 4:
        {
            // Recebe o elemento
            int elemento;
            std::cout << "Digite o elemento: ";
            std::cin >> elemento;

            // Buscar
            bool encontrado = pilha.busca(elemento);
            if (encontrado)
            {
                std::cout << "Elemento " << elemento << " encontrado na pilha." << std::endl;
            }
            else
            {
                std::cout << "Elemento " << elemento << " não encontrado na pilha." << std::endl;
            }
            break;
        }
        }
    } while (opcao != 0);

    return 0;
}