#include <stdio.h>
#include <string.h>

/*
Objetivo: O programa cadastra até 200 carros antigos e permite listar carros de um fabricante específico.
Entradas: Fabricante do carro, Valor de aquisição do carro
Saídas: Mensagem de confirmação de cadastro, Listagem dos carros de um fabricante específico, ou mensagem caso o fabricante não tenha carros cadastrados
*/

// Diretiva de substituição para o limite máximo de carros
#define MAX_CARROS 200  

// Estrutura para armazenar os dados dos carros
typedef struct {
    char fabricante[50];
    float valorAquisicao;
} Carro;

// Funções auxiliares
void cadastrarCarro(Carro carros[], int *numCarros);
void listarCarrosPorFabricante(Carro carros[], int numCarros);

// Função principal que apresenta o menu e aciona as funções
int main() {
    Carro carros[MAX_CARROS];
    int numCarros = 0;
    char opcao;

    do {
        // Menu de opções
        printf("\nMenu de Opcoes:\n");
        printf("C - Cadastrar um novo carro\n");
        printf("L - Listar carros de um fabricante especifico\n");
        printf("E - Encerrar o programa\n");
        printf("Escolha uma opcao: ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case 'C':
            case 'c':
                cadastrarCarro(carros, &numCarros);
                break;
            case 'L':
            case 'l':
                listarCarrosPorFabricante(carros, numCarros);
                break;
            case 'E':
            case 'e':
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 'E' && opcao != 'e');

    return 0;
}

// Função para cadastrar um novo carro
void cadastrarCarro(Carro carros[], int *numCarros) {
    if (*numCarros >= MAX_CARROS) {
        printf("Cadastro Cheio! Nao e possivel cadastrar mais carros.\n");
        return;
    }

    printf("Digite o fabricante do carro: ");
    scanf(" %[^\n]", carros[*numCarros].fabricante);
    printf("Digite o valor de aquisicao do carro: R$ ");
    scanf("%f", &carros[*numCarros].valorAquisicao);

    (*numCarros)++;
    printf("Carro cadastrado com sucesso!\n");
}

// Função para listar carros de um fabricante específico
void listarCarrosPorFabricante(Carro carros[], int numCarros) {
    char fabricante[50];
    int encontrado = 0;

    if (numCarros == 0) {
        printf("Nenhum carro cadastrado.\n");
        return;
    }

    printf("Digite o fabricante que deseja listar: ");
    scanf(" %[^\n]", fabricante);

    printf("\nCarros do fabricante '%s':\n", fabricante);
    for (int i = 0; i < numCarros; i++) {
        if (strcmp(carros[i].fabricante, fabricante) == 0) {
            printf("Fabricante: %s, Valor de Aquisicao: R$ %.2f\n", 
                   carros[i].fabricante, carros[i].valorAquisicao);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("Nenhum carro encontrado desse fabricante.\n");
    }
}
