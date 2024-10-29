#include <stdio.h>
#include <string.h>
#include <ctype.h>


/*
Objetivo: Desenvolver um programa para o Instituto Nacional de Meteorologia que coleta dados de chuva de várias 
cidades em fevereiro e permite buscar dias em que uma quantidade específica de chuva ocorreu.
Entradas: Ano do levantamento, Número de cidades e dias coletados, Nome da cidade, Quantidade de chuva
Saídas: Número de dias em fevereiro (28 ou 29), Nome da cidade e dias que tiveram uma quantidade específica de chuva
*/

#define TAM_NOME 50  // Tamanho máximo do nome da cidade
#define MAX_CIDADES 100  // Número máximo de cidades que podem participar da pesquisa
#define MAX_DIAS 29  // Número máximo de dias de coleta em fevereiro

// Estrutura para armazenar os dados das cidades
typedef struct {
    char nome[TAM_NOME];
    float chuvas[MAX_DIAS];  // Quantidade de chuva para cada dia
} Cidade;

// Funções auxiliares
int validaQtdeDias(int ano);
float validaQtdeChuvas(float chuva);
void toLowerCase(char str[]);  // Converte uma string para minúsculas
void buscarChuva(Cidade cidades[], int numCidades, int qtdeDias, float chuvaBuscada);

int main() {
    int ano, qtdeDias, numCidades;
    Cidade cidades[MAX_CIDADES];
    float chuvaBuscada;
    char continuar;

    // Leitura do ano
    printf("Digite o ano do levantamento: ");
    scanf("%d", &ano);

    // Validação da quantidade de dias em fevereiro
    qtdeDias = validaQtdeDias(ano);
    printf("Quantidade de dias em fevereiro: %d\n", qtdeDias);

    // Leitura da quantidade de cidades
    printf("Digite a quantidade de cidades que participarao da pesquisa: ");
    scanf("%d", &numCidades);

    // Leitura dos dados de cada cidade
    for (int i = 0; i < numCidades; i++) {
        printf("\nCidade %d:\n", i + 1);

        // Leitura e validação do nome da cidade
        do {
            printf("Nome da cidade: ");
            scanf(" %[^\n]", cidades[i].nome);
            if (strlen(cidades[i].nome) == 0 || strlen(cidades[i].nome) >= TAM_NOME) {
                printf("Nome invalido! O nome deve ter entre 1 e %d caracteres.\n", TAM_NOME - 1);
            }
        } while (strlen(cidades[i].nome) == 0 || strlen(cidades[i].nome) >= TAM_NOME);

        // Leitura e validação da quantidade de chuvas para cada dia
        for (int j = 0; j < qtdeDias; j++) {
            do {
                printf("Quantidade de chuva no dia %d (em mm): ", j + 1);
                scanf("%f", &cidades[i].chuvas[j]);
            } while (validaQtdeChuvas(cidades[i].chuvas[j]) == -1);
        }
    }

    // Busca por uma quantidade específica de chuva
    do {
        printf("\nDigite a quantidade de chuva a ser buscada (em mm): ");
        scanf("%f", &chuvaBuscada);

        buscarChuva(cidades, numCidades, qtdeDias, chuvaBuscada);

        printf("\nDeseja realizar outra busca? (S/N): ");
        scanf(" %c", &continuar);
    } while (tolower(continuar) == 's');

    return 0;
}

// Função que valida a quantidade de dias de fevereiro
int validaQtdeDias(int ano) {
    if ((ano % 400 == 0) || (ano % 100 != 0 && ano % 4 == 0)) {
        return 29;  // Ano bissexto
    } else {
        return 28;  // Ano comum
    }
}

// Função que valida a quantidade de chuvas
float validaQtdeChuvas(float chuva) {
    if (chuva < 0 || chuva > 200) {
        printf("Quantidade de chuva invalida! O valor deve ser entre 0 e 200mm.\n");
        return -1;
    }
    return chuva;
}

// Função que converte uma string para minúsculas
void toLowerCase(char str[]) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Função que busca e exibe os dias em que a quantidade de chuva ocorreu em cada cidade
void buscarChuva(Cidade cidades[], int numCidades, int qtdeDias, float chuvaBuscada) {
    int encontrou = 0;

    for (int i = 0; i < numCidades; i++) {
        int diasEncontrados = 0;
        printf("\nCidade: %s\n", cidades[i].nome);

        for (int j = 0; j < qtdeDias; j++) {
            if (cidades[i].chuvas[j] == chuvaBuscada) {
                printf("Dia %d\n", j + 1);
                diasEncontrados = 1;
            }
        }

        if (!diasEncontrados) {
            printf("Nenhum dia com essa quantidade de chuva.\n");
        }
        encontrou = 1;
    }

    if (!encontrou) {
        printf("Nenhuma cidade encontrada.\n");
    }
}
