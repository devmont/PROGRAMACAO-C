#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Objetivo: Gerenciar os dados de até 500 alunos em uma disciplina, fornecendo funcionalidades para leitura, cálculo de média, ordenação e apresentação de alunos aprovados/reprovados.
Entradas: Matrícula, Percentual de faltas, Nota.
Saídas: Média da classe, Alunos aprovados e reprovados, Listagem dos alunos, ordenados por matrícula ou nota.

*/

#define MAX_ALUNOS 500

// Estrutura para armazenar os dados dos alunos
typedef struct {
    int matricula;
    float percentualFaltas;
    float nota;
} Aluno;

// Funções auxiliares
void lerDadosAluno(Aluno alunos[], int *numAlunos);
void calcularMediaClasse(Aluno alunos[], int numAlunos);
void apresentarAlunosPorMatricula(Aluno alunos[], int numAlunos);
void apresentarAlunosReprovados(Aluno alunos[], int numAlunos);
void apresentarAlunosAprovados(Aluno alunos[], int numAlunos);
void apresentarAlunosPorNota(Aluno alunos[], int numAlunos);
void ordenarPorMatricula(Aluno alunos[], int numAlunos);
void ordenarPorNota(Aluno alunos[], int numAlunos);

// Função principal que apresenta o menu e aciona as funções
int main() {
    Aluno alunos[MAX_ALUNOS];
    int numAlunos = 0;
    int opcao;

    do {
        // Menu de opções
        printf("\nMenu de Opcoes:\n");
        printf("1. Leitura dos dados de um aluno\n");
        printf("2. Calculo e apresentacao da media da classe\n");
        printf("3. Apresentacao dos dados de todos os alunos ordenados por matricula\n");
        printf("4. Apresentacao dos alunos reprovados\n");
        printf("5. Apresentacao dos alunos aprovados\n");
        printf("6. Apresentacao dos dados de todos os alunos ordenados por nota\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                lerDadosAluno(alunos, &numAlunos);
                break;
            case 2:
                calcularMediaClasse(alunos, numAlunos);
                break;
            case 3:
                ordenarPorMatricula(alunos, numAlunos);
                apresentarAlunosPorMatricula(alunos, numAlunos);
                break;
            case 4:
                apresentarAlunosReprovados(alunos, numAlunos);
                break;
            case 5:
                apresentarAlunosAprovados(alunos, numAlunos);
                break;
            case 6:
                ordenarPorNota(alunos, numAlunos);
                apresentarAlunosPorNota(alunos, numAlunos);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}

// Função para ler os dados de um aluno
void lerDadosAluno(Aluno alunos[], int *numAlunos) {
    if (*numAlunos >= MAX_ALUNOS) {
        printf("Numero maximo de alunos atingido!\n");
        return;
    }

    printf("Digite a matricula do aluno: ");
    scanf("%d", &alunos[*numAlunos].matricula);
    printf("Digite o percentual de faltas do aluno (0 a 100): ");
    scanf("%f", &alunos[*numAlunos].percentualFaltas);
    printf("Digite a nota do aluno: ");
    scanf("%f", &alunos[*numAlunos].nota);

    (*numAlunos)++;
    printf("Dados do aluno cadastrados com sucesso!\n");
}

// Função para calcular a média da classe
void calcularMediaClasse(Aluno alunos[], int numAlunos) {
    if (numAlunos == 0) {
        printf("Nenhum aluno cadastrado.\n");
        return;
    }

    float somaNotas = 0;
    for (int i = 0; i < numAlunos; i++) {
        somaNotas += alunos[i].nota;
    }

    float media = somaNotas / numAlunos;
    printf("A media da classe e: %.2f\n", media);
}

// Função para apresentar todos os alunos ordenados por matrícula
void apresentarAlunosPorMatricula(Aluno alunos[], int numAlunos) {
    printf("\nLista de alunos ordenados por matricula:\n");
    for (int i = 0; i < numAlunos; i++) {
        printf("Matricula: %d, Faltas: %.2f%%, Nota: %.2f\n", 
               alunos[i].matricula, alunos[i].percentualFaltas, alunos[i].nota);
    }
}

// Função para apresentar os alunos reprovados
void apresentarAlunosReprovados(Aluno alunos[], int numAlunos) {
    printf("\nAlunos reprovados:\n");
    for (int i = 0; i < numAlunos; i++) {
        if (alunos[i].nota <= 7.0 || alunos[i].percentualFaltas >= 25.0) {
            printf("Matricula: %d, Faltas: %.2f%%, Nota: %.2f\n", 
                   alunos[i].matricula, alunos[i].percentualFaltas, alunos[i].nota);
        }
    }
}

// Função para apresentar os alunos aprovados
void apresentarAlunosAprovados(Aluno alunos[], int numAlunos) {
    printf("\nAlunos aprovados:\n");
    for (int i = 0; i < numAlunos; i++) {
        if (alunos[i].nota > 7.0 && alunos[i].percentualFaltas < 25.0) {
            printf("Matricula: %d, Faltas: %.2f%%, Nota: %.2f\n", 
                   alunos[i].matricula, alunos[i].percentualFaltas, alunos[i].nota);
        }
    }
}

// Função para apresentar os alunos ordenados por nota
void apresentarAlunosPorNota(Aluno alunos[], int numAlunos) {
    printf("\nLista de alunos ordenados por nota:\n");
    for (int i = 0; i < numAlunos; i++) {
        printf("Matricula: %d, Faltas: %.2f%%, Nota: %.2f\n", 
               alunos[i].matricula, alunos[i].percentualFaltas, alunos[i].nota);
    }
}

// Função para ordenar os alunos por matrícula (Bubble Sort)
void ordenarPorMatricula(Aluno alunos[], int numAlunos) {
    Aluno temp;
    for (int i = 0; i < numAlunos - 1; i++) {
        for (int j = 0; j < numAlunos - 1 - i; j++) {
            if (alunos[j].matricula > alunos[j + 1].matricula) {
                temp = alunos[j];
                alunos[j] = alunos[j + 1];
                alunos[j + 1] = temp;
            }
        }
    }
}

// Função para ordenar os alunos por nota (Bubble Sort)
void ordenarPorNota(Aluno alunos[], int numAlunos) {
    Aluno temp;
    for (int i = 0; i < numAlunos - 1; i++) {
        for (int j = 0; j < numAlunos - 1 - i; j++) {
            if (alunos[j].nota < alunos[j + 1].nota) {
                temp = alunos[j];
                alunos[j] = alunos[j + 1];
                alunos[j + 1] = temp;
            }
        }
    }
}

