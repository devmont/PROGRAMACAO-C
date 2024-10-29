#include <stdio.h>
#include <ctype.h>
#include <conio.h> 

/*
Objetivo: Calcular a média das notas dos alunos de uma disciplina, lendo as notas de cada aluno 
e contabilizando a quantidade de alunos cadastrados.
Entrada: Matrícula, nota de cada aluno, indicação do usuário sobre se há mais alunos para serem 
cadastrados (resposta 'S' para sim, 'N' para não).
Saída: Quantidade total de alunos cadastrados, média das notas dos alunos cadastrados.
*/

// Função para ler os dados dos alunos
void leDados(float *somaNotas, int *qtdeAlunos) {
    int matricula;
    float nota;

    // Leitura da matrícula do aluno
    printf("Digite a matrícula do aluno: ");
    scanf("%d", &matricula);

    // Leitura da nota do aluno
    printf("Digite a nota do aluno: ");
    scanf("%f", &nota);

    // Atualização da soma das notas e da quantidade de alunos
    *somaNotas += nota;
    (*qtdeAlunos)++;
}

int main(void) {
    float somaNotas = 0, mediaNotas;
    int qtdeAlunos = 0;
    char resp;

    // Loop para leitura dos dados dos alunos
    do {
        leDados(&somaNotas, &qtdeAlunos);
        printf("Existem mais alunos (S/N)? ");
        resp = toupper(getch());  // Lê a resposta sem necessidade de pressionar Enter
        printf("\n");
    } while (resp != 'N');

    // Cálculo da média das notas
    mediaNotas = somaNotas / qtdeAlunos;

    // Exibição dos resultados
    printf("Qtde de alunos = %d\n", qtdeAlunos);
    printf("Media das notas na disciplina = %.1f\n", mediaNotas);

    getch(); // Pausa para visualizar os resultados
    return 0;
}
