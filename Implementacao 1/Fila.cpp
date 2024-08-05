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

//--------Fila--------//
class Fila
{
private:
    Node *raiz; // Atributo

public:
    Fila() // Construtor
    {
        this->raiz = nullptr;
    }



    void inserirFim(int elemento)
    {
        Node *novo = new Node(elemento);

        if (this->raiz == nullptr)
        {
            this->raiz = novo; // Se a Fila estiver vazia, o novo elemento é a raiz
        }
        else
        {
            Node *atual = this->raiz;         // Ponteiro para percorrer a Fila
            while (atual->proximo != nullptr) // Percorre a Fila até o elemtento sem proximo
            {
                atual = atual->proximo;
            }
            atual->proximo = novo; // Adiciona o novo elemento
        }

        std::cout << "Elemento " << elemento << " inserido" << std::endl;
    }

   
    void removerInicio()
    {
        // Verifica se a Fila está vazia
        if (this->raiz == nullptr)
        {
            std::cout << "Fila Vazia" << std::endl;
            return;
        }
        else
        {
            int elemento = raiz->elemento; // salva o elemento
            Node *tmp = raiz;             // Salva a raiz atual
            raiz = raiz->proximo;          // Remove a Raiz
            delete tmp;                   // Libera a memória

            std::cout << "Elemento " << elemento << " removido" << std::endl;
        }
    }



    void print()
    {
        if (this->raiz == nullptr)
        {
            std::cout << "Fila Vazia" << std::endl;
            return;
        }

        Node *atual = this->raiz; // Ponteiro para percorrer a Fila
        while (atual != nullptr)  // Percorre a Fila até o final
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
            std::cout << "Fila Vazia" << std::endl;
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
    // Inicializa a Fila E a opção
    int opcao;
    Fila fila;

    do
    {
        // Menu
        std::cout << std::endl;
        std::cout << "1) Inserir na Fila" << std::endl;
        std::cout << "2) Remover da Fila" << std::endl;
        std::cout << std::endl;
        std::cout << "3) Imprimir Fila" << std::endl;
        std::cout << "4) Buscar na Fila" << std::endl;
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
            fila.inserirFim(elemento);
            break;
        }

        case 2:
        {
            // Remover
            fila.removerInicio();
            break;
        }
    
        case 3:
        {
            fila.print();
            break;
        }
        case 4:
        {
            // Recebe o elemento
            int elemento;
            std::cout << "Digite o elemento: ";
            std::cin >> elemento;

            // Buscar
            bool encontrado = fila.busca(elemento);
            if (encontrado)
            {
                std::cout << "Elemento " << elemento << " encontrado na fila." << std::endl;
            }
            else
            {
                std::cout << "Elemento " << elemento << " não encontrado na fila." << std::endl;
            }
            break;
        }
        }
    } while (opcao != 0);

    return 0;
}