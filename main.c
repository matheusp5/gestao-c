#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <memory.h>
#include "cs50.h"

typedef char* string;

int main();

typedef struct {
    int id;
    string uf;
    string cidade;
    string cep;
    string bairro;
    string rua;
    string numero;
} Endereco;

typedef struct {
    int id;
    string nome;
    string email;
    int idade;
    Endereco endereco;
} Cliente;

typedef struct {
    int id;
    string nome;
    string descricao;
    double preco;
} Produto;


typedef struct {
    int id;
    Cliente cliente;
    Produto produto;
    double total;
} Pedido;

Produto produtos[30];
Cliente clientes[30];
Pedido  pedidos[30];

int addressSize = 0;
int clientsSize = 0;
int productsSize = 0;
int ordersSize = 0;

int inserirProduto(string nome, string descricao, double preco) {
    Produto produto = {
            productsSize + 1,
            nome,
            descricao, preco
    };

    produtos[productsSize] = produto;
    productsSize++;
    return productsSize;
}

int inserirPedido(int produtoId, int clienteId, int quantidade) {
    Produto produto;
    for (int i = 0; i < productsSize; ++i) {
        if(produtos[i].id == produtoId) {
            produto = produtos[i];
        }
    }

    Cliente cliente;
    for (int i = 0; i < clientsSize; ++i) {
        if(clientes[i].id == clienteId) {
            cliente = clientes[i];
        }
    }

    Pedido pedido = {
            ordersSize + 1,
            cliente,
            produto,
            produto.preco * quantidade
    };

    pedidos[ordersSize] = pedido;
    ordersSize++;
    return ordersSize;
}


int inserirCliente(string nome, string email, int idade, string uf, string cidade, string cep, string bairro, string rua, string numero) {

    Endereco endereco = {
        addressSize + 1,
        uf,
        cidade,
        cep,
        bairro,
        rua,
        numero
    };
    addressSize++;

    Cliente cliente = {
            clientsSize + 1,
            nome,
            email,
            idade,
            endereco
    };

    clientes[clientsSize] = cliente;
    clientsSize++;
    return clientsSize;
}

void criarCliente() {

    system("cls");
    printf("-----------------------------------------------\n");
    printf("              ADICIONAR UM CLIENTE             \n");
    printf("-----------------------------------------------\n\n");
    printf("    Dados Pessoais\n");
    string nome = get_string("    Nome: ");
    string email = get_string("    E-mail: ");
    int idade = get_int("    Idade: ");
    printf("\n    Endereco\n");
    string uf = get_string("    Estado: ");
    string cidade = get_string("    Cidade: ");
    string cep = get_string("    CEP: ");
    string bairro = get_string("    Bairro: ");
    string rua = get_string("    Rua: ");
    string numero = get_string("    Numero: ");
    int id = inserirCliente(nome, email, idade, uf, cidade, cep, bairro, rua, numero);
    printf("\n");
    printf("    Cliente inserido com sucesso!\n");
    printf("    ID: %d\n    Nome: %s\n    E-mail: %s\n    Idade: %d\n\n", id, nome, email, idade);
    printf("    Estado: %s\n    Cidade: %s\n    CEP: %s\n    Bairro: %s\n    Rua: %s\n    Numero: %s\n", uf, cidade, cep, bairro, rua, numero);
    printf("\n    Pressione qualquer botao para continuar. ");
    getchar();
}

void criarPedido() {

    system("cls");
    printf("-----------------------------------------------\n");
    printf("              ADICIONAR UM PEDIDO             \n");
    printf("-----------------------------------------------\n\n");

    int clienteId = get_int("    ID do cliente: ");
    int produtoId = get_int("    ID do produto: ");
    int quantidade = get_int("    Quantidade do produto: ");

    int pedidoId = inserirPedido(produtoId, clienteId, quantidade);

    printf("\n");
    printf("    Pedido inserido com sucesso!\n");
    printf("    ID: %d\n", pedidoId);
    printf("    ID do cliente: %d\n", clienteId);
    printf("    ID do produto: %d\n", produtoId);
    printf("    Quantidade do produto: %d\n", quantidade);

    printf("\n    Pressione qualquer botao para continuar. ");
    getchar();
}

void criarProduto() {
    system("cls");
    printf("-----------------------------------------------\n");
    printf("              ADICIONAR UM PRODUTO             \n");
    printf("-----------------------------------------------\n\n");
    string nome = get_string("    Nome: ");
    string descricao = get_string("    Descricao: ");
    double preco = get_double("    Preco: ");
    int id = inserirProduto(nome, descricao, preco);
    printf("\n");
    printf("    Produto inserido com sucesso!\n");
    printf("    ID: %d\n    Nome: %s\n    Descricao: %s\n    Preco: %.2f\n", id, nome, descricao, preco);
    printf("\n    Pressione qualquer botao para continuar. ");
    getchar();
}

void listarProdutos() {
    system("cls");
    printf("-----------------------------------------------\n");
    printf("                LISTAR PRODUTOS                \n");
    printf("-----------------------------------------------\n\n");
    for (int i = 0; i < productsSize; ++i) {
        printf("#%d; Nome: %s. Descricao: %s. Preco: %.2f\n\n", produtos[i].id, produtos[i].nome, produtos[i].descricao ,produtos[i].preco);
    }
    printf("\n    Pressione qualquer botao para continuar. ");
    getchar();
}

void listarPedidos() {
    system("cls");
    printf("-----------------------------------------------\n");
    printf("                 LISTAR PEDIDOS                \n");
    printf("-----------------------------------------------\n\n");
    for (int i = 0; i < ordersSize; ++i) {
        printf("#%d; Cliente: %s. Produto: %s. Total: %.2f\n\n", pedidos[i].id, pedidos[i].cliente.nome, pedidos[i].produto.nome ,pedidos[i].total);
    }
    printf("\n    Pressione qualquer botao para continuar. ");
    getchar();
}

void listarClientes() {
    system("cls");
    printf("-----------------------------------------------\n");
    printf("                LISTAR CLIENTES                \n");
    printf("-----------------------------------------------\n\n");
    for (int i = 0; i < clientsSize; i++) {
        printf("#%d; Nome: %s. E-mail: %s. Idade: %d.\n", clientes[i].id, clientes[i].nome, clientes[i].email, clientes[i].idade);
        printf("  Estado: %s\n", clientes[i].endereco.uf);
        printf("  Cidade: %s\n", clientes[i].endereco.cidade);
        printf("  CEP: %s\n", clientes[i].endereco.cep);
        printf("  Bairro: %s\n", clientes[i].endereco.bairro);
        printf("  Rua: %s\n", clientes[i].endereco.rua);
        printf("  Numero: %s\n", clientes[i].endereco.numero);
        printf("\n\n");
    }
    printf("\n    Pressione qualquer botao para continuar. ");
    getchar();
}

void deletarCliente() {
    system("cls");
    printf("-----------------------------------------------\n");
    printf("                DELETAR CLIENTE                \n");
    printf("-----------------------------------------------\n\n");

    int id = get_int("    Qual e o ID do cliente? ");
    Cliente cliente;
    Cliente clientesFiltrados[30];
    int clientesFiltradosSize = 0;

    for (int i = 0; i < clientsSize; ++i) {
        if (clientes[i].id == id) {
            cliente = clientes[i];
        } else {
            clientesFiltrados[clientesFiltradosSize] = clientes[i];
            clientesFiltradosSize++;
        }
    }

    printf("\n");
    printf("    Cliente encontrado:\n");
    printf("    Nome: %s\n", cliente.nome);
    printf("    E-mail: %s\n", cliente.email);
    printf("    Idade: %d\n", cliente.idade);
    printf("\n");
    char escolha = get_char("    Deseja confirmar? (S/N) ");

    if (tolower(escolha) == 's') {
        memcpy(clientes, clientesFiltrados, sizeof(clientes));
        clientsSize = clientesFiltradosSize;
    }

    printf("\n    Pressione qualquer botao para continuar. ");
    getchar();
}

void deletarProduto() {
    system("cls");
    printf("-----------------------------------------------\n");
    printf("                DELETAR PRODUTO                \n");
    printf("-----------------------------------------------\n\n");

    int id = get_int("    Qual e o ID do produto? ");
    Produto produto;
    Produto produtosFiltrados[30];
    int produtosFiltradosSize = 0;

    for (int i = 0; i < productsSize; ++i) {
        if (produtos[i].id == id) {
            produto = produtos[i];
        } else {
            produtosFiltrados[produtosFiltradosSize] = produtos[i];
            produtosFiltradosSize++;
        }
    }

    printf("\n");
    printf("    Produto encontrado:\n");
    printf("    Nome: %s\n", produto.nome);
    printf("    Descricao: %s\n", produto.descricao);
    printf("    Preco: %.2f\n", produto.preco);
    printf("\n");
    char escolha = get_char("    Deseja confirmar? (S/N) ");

    if (tolower(escolha) == 's') {
        memcpy(produtos, produtosFiltrados, sizeof(produtos));
        productsSize = produtosFiltradosSize;
    }

    printf("\n    Pressione qualquer botao para continuar. ");
    getchar();
}

void deletarPedido() {
    system("cls");
    printf("-----------------------------------------------\n");
    printf("                DELETAR PEDIDO                 \n");
    printf("-----------------------------------------------\n\n");

    int id = get_int("    Qual e o ID do pedido? ");
    Pedido pedido;
    Pedido pedidosFiltrados[30];
    int pedidosFiltradosSize = 0;

    for (int i = 0; i < ordersSize; ++i) {
        if (pedidos[i].id == id) {
            pedido = pedidos[i];
        } else {
            pedidosFiltrados[pedidosFiltradosSize] = pedidos[i];
            pedidosFiltradosSize++;
        }
    }

    printf("\n");
    printf("    Pedido encontrado:\n");
    printf("    Cliente: %s\n", pedido.cliente.nome);
    printf("    Produto: %s\n", pedido.produto.nome);
    printf("    Total: %.2f\n", pedido.total);
    printf("\n");
    char escolha = get_char("    Deseja confirmar? (S/N) ");

    if (tolower(escolha) == 's') {
        memcpy(pedidos, pedidosFiltrados, sizeof(pedidos));
        ordersSize = pedidosFiltradosSize;
    }

    printf("\n    Pressione qualquer botao para continuar. ");
    getchar();
}


void gerenciarClientes() {
    while(true) {
        system("cls");
        printf("-----------------------------------------------\n");
        printf("               GESTAO DE CLIENTES              \n");
        printf("-----------------------------------------------\n\n");
        printf("    A - Adicionar um cliente\n");
        printf("    L - Listar todos os clientes\n");
        printf("    D - Deletar um cliente\n");
        printf("    V - Voltar\n\n");
        char escolha = get_char("   -> ");


        switch (tolower(escolha)) {
            case 'a':
                criarCliente();
                break;
            case 'l':
                listarClientes();
                break;
            case 'd':
                deletarCliente();
                break;
            case 'v':
                main();
                break;
        }
    }
}

void gerenciarProdutos() {
    while(true) {
        system("cls");
        printf("-----------------------------------------------\n");
        printf("               GESTAO DE PRODUTOS              \n");
        printf("-----------------------------------------------\n\n");
        printf("    A - Adicionar um produto\n");
        printf("    L - Listar todos os produtos\n");
        printf("    D - Deletar um produto\n");
        printf("    V - Voltar\n\n");
        char escolha = get_char("   -> ");


        switch (tolower(escolha)) {
            case 'a':
                criarProduto();
                break;
            case 'l':
                listarProdutos();
                break;
            case 'd':
                deletarProduto();
                break;
            case 'v':
                main();
        }
    }
}

void gerenciarPedidos() {
    while (true) {
        system("cls");
        printf("-----------------------------------------------\n");
        printf("                GESTAO DE PEDIDOS              \n");
        printf("-----------------------------------------------\n\n");
        printf("    A - Adicionar um pedido\n");
        printf("    L - Listar todos os pedidos\n");
        printf("    D - Deletar um pedido\n");
        printf("    V - Voltar\n\n");
        char escolha = get_char("   -> ");

        switch (tolower(escolha)) {
            case 'a':
                criarPedido();
                break;
            case 'l':
                listarPedidos();
                break;
            case 'd':
                deletarPedido();
                break;
            case 'v':
                main();
        }
    }
}

int main() {
    system("cls");
    printf("-----------------------------------------------\n");
    printf("               SISTEMA DE GESTAO               \n");
    printf("-----------------------------------------------\n\n");
    printf("    C - Gerencie os clientes\n");
    printf("    P - Gerencie os produtos\n");
    printf("    E - Gerencie os pedidos\n\n");
    char escolha = get_char("   -> ");

    switch (tolower(escolha)) {
        case 'c':
            gerenciarClientes();
            break;
        case 'p':
            gerenciarProdutos();
            break;
        case 'e':
            gerenciarPedidos();
            break;
    }
    return 0;
}
