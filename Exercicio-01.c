#include <stdio.h>

// Objetivo: Calcular o valor médio das peças em estoque e apresentar um relatório
// Entradas: Valor total em estoque e quantidade de peças de dois tipos
// Saída: Relatório com o valor médio de cada peça e o valor médio geral convertido para dólares

// Função para imprimir o cabeçalho do relatório

void cabecalho() {
    printf("Relatorio de Estoque\n");
    printf("====================\n");
    printf("Informacoes de pecas em estoque:\n\n");
}

// Função para calcular o valor médio de uma peça

float calcularValorMedio(float valor, int quantidade) {
    if (quantidade == 0) {
        return 0.0;
    }
    return valor / quantidade;
}

// Função para calcular o valor médio geral em dólares

float calcularValorMedioGeral(float valor1, float valor2, int qtde1, int qtde2, float dolar) {
    
    int totalQtde = qtde1 + qtde2;
    if (totalQtde == 0) {
        return 0.0; 
    }
    return (valor1 + valor2) / totalQtde / dolar;
}

// Função para apresentar a finalização do programa com os resultados

void apresentarFinalizacao(float valor1, int qtde1, float valorMedio1, float valor2, int qtde2, float valorMedio2, float valorMedioGeral) {
    printf("Peca Tipo 1:\n");
    printf("Valor em estoque = R$ %.2f\n", valor1);
    printf("Quantidade em estoque = %d\n", qtde1);
    printf("Valor Medio = R$ %.2f\n\n", valorMedio1);

    printf("Peca Tipo 2:\n");
    printf("Valor em estoque = R$ %.2f\n", valor2);
    printf("Qtde em estoque = %d\n", qtde2);
    printf("Valor Medio = R$ %.2f\n\n", valorMedio2);

    printf("Valor medio geral = $ %.2f\n", valorMedioGeral);
}

int main() {
    // VARIÁVEIS
    float valor1 = 0.0, valor2 = 0.0;
    int qtde1 = 0, qtde2 = 0;
    float valorMedio1 = 0.0, valorMedio2 = 0.0, valorMedioGeral = 0.0;
    const float dolar = 5.70;

    // INÍCIO DO PROGRAMA

    // BLOCO 1: Leitura dos valores e quantidades da peça tipo 1
    printf("Digite o valor total em estoque da peca tipo 1: R$ ");
    scanf("%f", &valor1);
    printf("Digite a quantidade da peca tipo 1: ");
    scanf("%d", &qtde1);

    // BLOCO 2: Leitura dos valores e quantidades da peça tipo 2
    printf("Digite o valor total em estoque da peca tipo 2: R$ ");
    scanf("%f", &valor2);
    printf("Digite a quantidade da peca tipo 2: ");
    scanf("%d", &qtde2);

    // Cálculo do valor médio de cada peça
    valorMedio1 = calcularValorMedio(valor1, qtde1);
    valorMedio2 = calcularValorMedio(valor2, qtde2);

    // Cálculo do valor médio geral
    valorMedioGeral = calcularValorMedioGeral(valor1, valor2, qtde1, qtde2, dolar);

    // Exibe o relatório
    
    cabecalho();
    apresentarFinalizacao(valor1, qtde1, valorMedio1, valor2, qtde2, valorMedio2, valorMedioGeral);

    return 0;
}
