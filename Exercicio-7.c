#include <stdio.h>
#include <string.h>

/*
Objetivo: Desenvolver um programa para coletar e analisar dados de clientes de uma empresa que vende produtos pela Internet.
Entradas: Nível de escolaridade (primário, secundário ou pós-graduado), Valor gasto mensalmente (em R$),Meses desde a primeira compra (inteiro)
Saídas: Exibição dos dados cadastrados de todos os clientes, Cálculo e exibição do valor médio mensal gasto pelos clientes, Contagem de clientes com nível pós-graduado que gastam mais de R$ 1.000,00 e estão cadastrados há mais de 3 meses
*/

#define MAX_CLIENTES 530

// Estrutura para armazenar os dados dos clientes
typedef struct {
    char nivelEscolaridade[15];
    float valorGastoMensal;
    int mesesDesdePrimeiraCompra;
} Cliente;

// Funções auxiliares
void validaNivelEscolaridade(char *nivelEscolaridade);
int classificaCliente(Cliente c);
void exibirDadosClientes(Cliente clientes[], int qtdeClientes);
float calcularValorMedioMensal(Cliente clientes[], int qtdeClientes);
int contarClientesUniversitarios(Cliente clientes[], int qtdeClientes);

int main() {
    Cliente clientes[MAX_CLIENTES];
    int qtdeClientes = 0;
    char continuar;
    
    // Leitura dos dados dos clientes
    do {
        printf("\nCliente %d:\n", qtdeClientes + 1);

        // Validação do nível de escolaridade
        validaNivelEscolaridade(clientes[qtdeClientes].nivelEscolaridade);

        // Leitura do valor gasto mensalmente
        printf("Valor gasto mensalmente: R$ ");
        scanf("%f", &clientes[qtdeClientes].valorGastoMensal);

        // Leitura da quantidade de meses desde a primeira compra
        printf("Meses desde a primeira compra: ");
        scanf("%d", &clientes[qtdeClientes].mesesDesdePrimeiraCompra);

        qtdeClientes++;

        // Verificar se deseja cadastrar outro cliente
        if (qtdeClientes < MAX_CLIENTES) {
            printf("Deseja cadastrar outro cliente? (S/N): ");
            scanf(" %c", &continuar);
        } else {
            printf("Cadastro cheio. Não é possível adicionar mais clientes.\n");
            break;
        }
    } while (tolower(continuar) == 's' && qtdeClientes < MAX_CLIENTES);

    // Menu de opções
    int opcao;
    do {
        printf("\nMENU DE OPÇÕES:\n");
        printf("1. Apresentar todos os dados cadastrados\n");
        printf("2. Calcular valor médio mensal gasto pelos clientes\n");
        printf("3. Contar clientes com nível universitário que gastam acima de R$1.000,00 e estão cadastrados há mais de 3 meses\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                exibirDadosClientes(clientes, qtdeClientes);
                break;
            case 2: {
                float valorMedio = calcularValorMedioMensal(clientes, qtdeClientes);
                printf("Valor médio mensal gasto pelos clientes: R$ %.2f\n", valorMedio);
                break;
            }
            case 3: {
                int qtde = contarClientesUniversitarios(clientes, qtdeClientes);
                printf("Quantidade de clientes com nível universitário que gastam acima de R$ 1.000,00 e estão cadastrados há mais de 3 meses: %d\n", qtde);
                break;
            }
            case 4:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}

// Função que valida o nível de escolaridade
void validaNivelEscolaridade(char *nivelEscolaridade) {
    do {
        printf("Nivel de escolaridade (primario, secundario, posgraduado): ");
        scanf("%s", nivelEscolaridade);
        if (strcmp(nivelEscolaridade, "primario") != 0 &&
            strcmp(nivelEscolaridade, "secundario") != 0 &&
            strcmp(nivelEscolaridade, "posgraduado") != 0) {
            printf("Nível de escolaridade inválido. Por favor, tente novamente.\n");
        }
    } while (strcmp(nivelEscolaridade, "primario") != 0 &&
             strcmp(nivelEscolaridade, "secundario") != 0 &&
             strcmp(nivelEscolaridade, "posgraduado") != 0);
}

// Função que classifica se o cliente é universitário, gasta mais de R$ 1.000,00 e está cadastrado há mais de 3 meses
int classificaCliente(Cliente c) {
    return (strcmp(c.nivelEscolaridade, "posgraduado") == 0 &&
            c.valorGastoMensal > 1000.0 &&
            c.mesesDesdePrimeiraCompra > 3);
}

// Função para exibir os dados de todos os clientes cadastrados
void exibirDadosClientes(Cliente clientes[], int qtdeClientes) {
    printf("\nDados dos clientes cadastrados:\n");
    for (int i = 0; i < qtdeClientes; i++) {
        printf("Cliente %d:\n", i + 1);
        printf("Nivel de Escolaridade: %s\n", clientes[i].nivelEscolaridade);
        printf("Valor Gasto Mensal: R$ %.2f\n", clientes[i].valorGastoMensal);
        printf("Meses Desde Primeira Compra: %d\n", clientes[i].mesesDesdePrimeiraCompra);
        printf("\n");
    }
}

// Função que calcula o valor médio mensal gasto pelos clientes
float calcularValorMedioMensal(Cliente clientes[], int qtdeClientes) {
    float somaValores = 0.0;
    for (int i = 0; i < qtdeClientes; i++) {
        somaValores += clientes[i].valorGastoMensal;
    }
    return somaValores / qtdeClientes;
}

// Função que conta quantos clientes com nível universitário gastam mais de R$ 1.000,00 e estão cadastrados há mais de 3 meses
int contarClientesUniversitarios(Cliente clientes[], int qtdeClientes) {
    int contador = 0;
    for (int i = 0; i < qtdeClientes; i++) {
        if (classificaCliente(clientes[i])) {
            contador++;
        }
    }
    return contador;
}