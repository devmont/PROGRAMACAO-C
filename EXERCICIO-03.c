#include <stdio.h>

/*

Objetivo: Ler dados de clientes de um banco e calcular o cliente com maior e menor saldo e quantos têm saldo abaixo da média.

Entradas: Número de clientes (<= 50), número da conta e saldo de cada cliente.

Saída: Conta e cliente com maior saldo, conta e cliente com menor saldo, e quantidade de clientes com saldo abaixo da média. 

*/

#define MAX_CLIENTES 50

int main(){

    int numClientes = 0;
    int contas[MAX_CLIENTES];
    float saldos[MAX_CLIENTES];
    float saldoTotal = 0, saldoMedio;
    int i, maiorSaldoIdx = 0, menorSaldoIdx = 0, clientesAbaixoDaMedia = 0;

    //ler o numero de clientes:

    do{
        printf("Digite o numero de clientes (maximo de 50): ");
        scanf("%d", &numClientes);
        if(numClientes < 1 || numClientes > 50){
            printf("Numero errado Digite um numero entre 1 e 50");
        }
    }while( numClientes < 1 || numClientes > 50);

    //entreda de dados dos clientes

    for (i = 0; i < numClientes; i++){
        printf("\n digite o numero da conta do cliente %d:", i + 1);
        scanf("%d", &contas[i]);
        printf("digite o saldo atual do cliente %d: R$ ", i + 1);
        scanf("%f", &saldos[i]);

        //acumular saldo total

        saldoTotal += saldos[i];

        //atualizar o indide de maior e menor saldo

        if (saldos[i] > saldos[maiorSaldoIdx]){
            maiorSaldoIdx = i;
        }
        if (saldos[i] < saldos[menorSaldoIdx]){
            menorSaldoIdx = i;
        }
    }

    //calcular o saldo medio

    saldoMedio = saldoTotal / numClientes;

    //Contar quantos clientes tem saldo abaixo da media

    for (i = 0; i < numClientes; i++){
        if(saldos[i] < saldoMedio){
            clientesAbaixoDaMedia++;
        }
    }

    printf("==================================\n\n");

    // Exibir os resultados

    printf("Cliente com o maior saldo:\n");
    printf("Conta: %d | Saldo: R$ %.2f\n\n", contas[maiorSaldoIdx], saldos[maiorSaldoIdx]);

    printf("Cliente com o menor saldo:\n");
    printf("Conta: %d | Saldo: R$ %.2f\n\n", contas[menorSaldoIdx], saldos[menorSaldoIdx]);

    printf("Quantidade de clientes com saldo abaixo da media (R$ %.2f): %d\n", saldoMedio, clientesAbaixoDaMedia);


    return 0;
}


