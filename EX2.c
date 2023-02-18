/*
Lista 1 - Exercício 5 
NOME: Guilherme Ferreira Gonçalves    RA: 221020561
DATA: 12/2022

Suponha um cadastro de alunos onde cada aluno contém os seguintes campos: Nome, 
Data de Nascimento (dia, mês, ano), RG, Sexo, Endereço (Rua, Cidade, Estado, CEP), 
RA  (Registro  de  Aluno)  e  CR  (Coeficiente  de  Rendimento:  número  real  no  intervalo 
[0,1]). Faça um programa que realize o cadastro de alunos em um vetor com 100 posi-
ções. O programa deve manipular este cadastro com as seguintes opções: 
 
1)  Inserir um novo aluno no cadastro. 
2)  Ordenar o cadastro por nome em ordem alfabética. 
3)  Ordenar o cadastro por CR, maiores primeiro. 
4)  Ler o valor de um RA e imprimir os dados do aluno no cadastro com mesmo RA. 
5)  Imprimir o cadastro na ordem atual.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAM 100


typedef struct {
    char rua[TAM], cidade[TAM], estado[TAM];
    int cep;
} endereco;


typedef struct {
    int dia, mes, ano;
} nascimento;


typedef struct {
    char nome[TAM];
    nascimento data;
    int rg;
    char sexo;
    endereco lugar;
    int ra;
    double cr;
} aluno;


aluno ListaAlunos[100];
int quant = 0;


void cadastrarAluno () {

    int num;
    printf("\n##### CADASTRO DE ALUNO #####\n\n");
    printf("Quantos alunos deseja cadastrar? ");
    scanf("%d", &num);
    printf("\n");

    for (int i = 0; i < num; i++) {
        aluno a;
        printf("Nome do aluno: ");
        scanf("%*c"); // limpeza de buffer
        fgets(a.nome, TAM, stdin);
        a.nome[0] = toupper(a.nome[0]);
        printf("Data de nascimento (dd/mm/aaaa): ");
        scanf("%d %d %d", &a.data.dia, &a.data.mes, &a.data.ano);
        printf("RG: ");
        scanf("%d", &a.rg);
        printf("Sexo (m/f): ");
        scanf("%*c"); // limpeza de buffer
        scanf("%c", &a.sexo);
        printf("Endereco:\n");
        printf("\tRua: ");
        scanf("%*c"); // limpeza de buffer
        fgets(a.lugar.rua, TAM, stdin);
        printf("\tCidade: ");
        //scanf("%*c"); // limpeza de buffer
        fgets(a.lugar.cidade, TAM, stdin);
        printf("\tEstado: ");
        //scanf("%*c"); // limpeza de buffer
        fgets(a.lugar.estado, TAM, stdin);
        printf("\tCEP: ");
        scanf("%d", &a.lugar.cep);
        printf("RA: ");
        scanf("%d", &a.ra);
        do {
            printf("Coeficiente de Rendimento[0,1]: ");
            scanf("%lf", &a.cr);
        } while (a.cr < 0 || a.cr > 1);
        ListaAlunos[quant] = a;
        quant++;
        printf("\n");
    }
    printf("#############################\n");
}


void ordenarPorNome () {

    int valor;
    aluno aux;
    printf("##### ORDENANDO POR NOME... #####\n");
    for (int i = 0; i < quant; i++) {
        for (int j = i+1; j < quant; j++ ) {
            valor = strcmp(ListaAlunos[i].nome, ListaAlunos[j].nome);
            if (valor > 0) {
                aux = ListaAlunos[i];
                ListaAlunos[i] = ListaAlunos[j];
                ListaAlunos[j] = aux;
            }   
        }
    }
    printf("Lista ordenada por nome!\n");
    printf("#################################\n");
}


void ordenarPorCR () {
    
    aluno aux;
    printf("##### ORDENANDO POR CR... #####\n");
    for (int i = 0; i < quant; i++) {
        for (int j = i+1; j < quant; j++) {
            if (ListaAlunos[i].cr < ListaAlunos[j].cr) {
                aux = ListaAlunos[i];
                ListaAlunos[i] = ListaAlunos[j];
                ListaAlunos[j] = aux;
            }
        }
    }
    printf("Lista ordenada por Coeficiente de Rendimento!\n");
    printf("###############################\n");
}


void consultarPorRA () {

    int ra;
    printf("##### CONSULTA POR RA #####\n\n");
    printf("Qual o RA do aluno? ");
    scanf("%d", &ra);
    printf("\n");

    for (int i = 0; i < quant; i++) {
        if (ra == ListaAlunos[i].ra) {
            printf("Nome: %s", ListaAlunos[i].nome);
            printf("Data de nascimento: %d/%d/%d\n", ListaAlunos[i].data.dia,ListaAlunos[i].data.mes, ListaAlunos[i].data.ano);
            printf("RG: %d\n", ListaAlunos[i].rg);
            printf("Sexo: %c\n", ListaAlunos[i].sexo);
            printf("Endereco:\n");
                printf("\tRua: %s", ListaAlunos[i].lugar.rua);
                printf("\tCidade: %s", ListaAlunos[i].lugar.cidade);
                printf("\tEstado: %s", ListaAlunos[i].lugar.estado);
                printf("\tCEP: %d\n", ListaAlunos[i].lugar.cep);
        printf("RA: %d\n", ListaAlunos[i].ra);
        printf("Coeficiente de Rendimento: %.2f\n", ListaAlunos[i].cr);
        printf("\n");
        }
    }
    printf("###########################\n\n");
}


void imprimirCadastroNaOrdemAtual () {

    printf("##### IMPRIMINDO CADASTRO #####\n\n");

    for (int i = 0; i < quant; i++) {
        printf("Nome: %s", ListaAlunos[i].nome);
        printf("Data de nascimento: %d/%d/%d\n", ListaAlunos[i].data.dia,ListaAlunos[i].data.mes, ListaAlunos[i].data.ano);
        printf("RG: %d\n", ListaAlunos[i].rg);
        printf("Sexo: %c\n", ListaAlunos[i].sexo);
        printf("Endereco:\n");
            printf("\tRua: %s", ListaAlunos[i].lugar.rua);
            printf("\tCidade: %s", ListaAlunos[i].lugar.cidade);
            printf("\tEstado: %s", ListaAlunos[i].lugar.estado);
            printf("\tCEP: %d\n", ListaAlunos[i].lugar.cep);
        printf("RA: %d\n", ListaAlunos[i].ra);
        printf("Coeficiente de Rendimento: %.2f\n", ListaAlunos[i].cr);
        printf("\n");
    }
    printf("###############################");
}


int main () {

   int opcao;
   printf("\n##### PROGRAMA DE CADASTRO DE ALUNOS #####\n\n");

    do {
        printf("\nDeseja:\n");
        printf("1 - Cadastrar um novo aluno\n");
        printf("2 - Ordenar o cadastro por nome\n");
        printf("3 - Ordenar o cadastro por CR\n");
        printf("4 - Consultar um cadastro por RA\n");
        printf("5 - Imprimir o cadastro na ordem atual\n");
        printf("Digite 0 para sair...\n");
        scanf("%d", &opcao);

        switch (opcao) {
        case 0:
            printf("\nPrograma encerrado...\n");
            break;
        case 1:
            cadastrarAluno();
            break;
        case 2:
            ordenarPorNome();
            break;
        case 3:
            ordenarPorCR();
            break;
        case 4:
            consultarPorRA();
            break;
        case 5:
            imprimirCadastroNaOrdemAtual();
            break;
        default:
            printf("Opcao invalida!\n");
            break;
        }
    } while (opcao != 0);

    return 0;
}
