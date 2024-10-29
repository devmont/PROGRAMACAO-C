#include <stdio.h>

// Objetivo: Coletar dados de idade e índice de satisfação de uma pesquisa e calcular médias e percentuais.
// Entradas: Idade e índice de satisfação (entre 5 e 10), sendo 999 o valor para encerrar a entrada.
// Saída: Exibe as médias de idade e satisfação, além dos percentuais de satisfação 5, 10 e abaixo de 7.

int main() {
    int idade, totalPessoas = 0;
    float indice, somaIdade = 0, somaIndice = 0;
    int satisfacao5 = 0, satisfacao10 = 0, abaixoDe7 = 0;

    do {
        printf("Digite a idade (999 para encerrar): ");
        scanf("%d", &idade);

        if (idade != 999) {
            // Entrada do índice de satisfação com validação entre 5 e 10
            do {
                printf("Digite o indice de satisfacao (5 a 10): ");
                scanf("%f", &indice);
                if (indice < 5 || indice > 10) {
                    printf("Indice invalido! Por favor, insira um valor entre 5 e 10.\n");
                }
            } while (indice < 5 || indice > 10);

            totalPessoas++;
            somaIdade += idade;
            somaIndice += indice;

            // Contabilizando as respostas de satisfação
            if (indice == 5) satisfacao5++;
            if (indice == 10) satisfacao10++;
            if (indice < 7) abaixoDe7++;
        }
    } while (idade != 999);

       // Verificação para evitar divisão por zero caso nenhuma pessoa seja entrevistada
    
    if (totalPessoas > 0) {
        float mediaIdade = somaIdade / totalPessoas;
        float mediaIndice = somaIndice / totalPessoas;
        float percentual5 = (float)satisfacao5 / totalPessoas * 100;
        float percentual10 = (float)satisfacao10 / totalPessoas * 100;
        float percentualAbaixoDe7 = (float)abaixoDe7 / totalPessoas * 100;

        // Exibindo os resultados da pesquisa
        printf("\nResultados da Pesquisa de Opinião:\n");
        printf("Total de pessoas entrevistadas: %d\n", totalPessoas);
        printf("Idade média das pessoas entrevistadas: %.2f\n", mediaIdade);
        printf("Média do índice de satisfação: %.2f\n", mediaIndice);
        printf("Número de satisfação 5: %d (%.2f%%)\n", satisfacao5, percentual5);
        printf("Número de satisfação 10: %d (%.2f%%)\n", satisfacao10, percentual10);
        printf("Percentual de pessoas com satisfação abaixo de 7: %.2f%%\n", percentualAbaixoDe7);
    } else {
        printf("Nenhuma pessoa foi entrevistada.\n");
    }

    return 0;
}
