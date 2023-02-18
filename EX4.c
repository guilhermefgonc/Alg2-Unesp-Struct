/*
NOME: Guilherme Ferreira Gonçalves    
DATA: 12/2022

A) Declare uma estrutura chamada TipoReg contendo os seguintes campos: Nome, RG, 
Salario, Idade, Sexo, DataNascimento; onde Nome e RG são strings, Salario é real, I-
dade é inteiro, Sexo é char e DataNascimento é uma estrutura contendo três inteiros, 
dia, mês e ano. Declare uma estrutura chamada TipoCadastro que contém dois cam-
pos: um campo funcionário, contendo um vetor com 100 posições do tipo TipoReg e 
outro campo inteiro, Quant, que indica a quantidade de funcionários no cadastro.

B) Faça  uma  função,  IniciaCadastro,  que  inicia  uma  variável  do  tipo  TipoCadastro.  A 
função atribui a quantidade de funcionários como zero.

C) Faça uma função, LeFuncionarios, com uma variável do tipo TipoCadastro como pa-
râmetro de entrada. A função deve ler os dados de vários funcionários e colocar no ve-
tor do cadastro, atualizando a quantidade de elementos não nulos. A função deve retor-
nar com o cadastro atualizado. Lembre que o cadastro não suporta mais funcionários 
que os definidos no vetor de funcionários. 

D) Faça  uma  função,  chamada  ListaFuncionarios,  que  imprime  os  dados  de  todos  os 
funcionário.

E) Faça  duas  funções para ordenar os funcionários no cadastro. Uma que ordena pelo 
nome, OrdenaNome, e outra que ordena pelo salário, OrdenaSalario. 
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100


typedef struct {
    int dia, mes, ano;
} DataNascimento;

typedef struct {
    char nome[MAX], rg[MAX];
    double salario;
    int idade;
    char sexo;
    DataNascimento data;
} Registro;

typedef struct {
    Registro Funcionarios[MAX];
    int Quant;
} Cadastro;
Cadastro c;


// função para ler funcionarios
void LeFuncionarios (Registro novo) {

    int qtde;

    printf("----- CADASTRO DE FUNCIONARIOS -----\n\n");
    printf("Quantos funcionarios deseja cadastrar? ");
    scanf("%d", &qtde);
    printf("\n");

    for (int i = 0; i < qtde; i++) {
        printf("Nome: ");
        scanf("%*c"); // limpeza de buffer do teclado
        fgets(novo.nome, MAX, stdin);
        novo.nome[0] = toupper(novo.nome[0]);
        printf("RG: ");
        fgets(novo.rg, MAX, stdin);
        printf("Idade: ");
        scanf("%d", &novo.idade);
        printf("Sexo (M/F): ");
        scanf("%*c"); // limpeza de buffer do teclado
        scanf("%c", &novo.sexo);
        printf("Data de nascimento (DD/MM/AAAA): ");
        scanf("%d %d %d", &novo.data.dia, &novo.data.mes, &novo.data.ano);
        printf("Salario: ");
        scanf("%lf", &novo.salario);
        printf("\n");

       c.Funcionarios[c.Quant] = novo;
       c.Quant++;
    }   
    printf("------------------------------------\n\n");
}

// funcao para imprimir a lista de funcionarios na tela
void ListaFuncionarios () {

    printf("\n----- LISTA DE FUNCIONARIOS -----\n\n");

    for (int i = 0; i < c.Quant; i++) {
        printf("Nome: %s", c.Funcionarios[i].nome);
        printf("RG: %s", c.Funcionarios[i].rg);
        printf("Idade: %d\n", c.Funcionarios[i].idade);
        printf("Sexo: %c\n", c.Funcionarios[i].sexo);
        printf("Data de Nascimento: %d %d %d\n", c.Funcionarios[i].data.dia, c.Funcionarios[i].data.mes, c.Funcionarios[i].data.ano);
        printf("Salario: %.2lf\n", c.Funcionarios[i].salario);
        printf("\n");
    }
    printf("\n---------------------------------\n");
}


// funcao que ordena a lista de funcionarios por nome;
void OrdenaNome () {

    Registro aux;
    int valor;

    printf("----- ORDENANDO LISTA POR NOME... -----\n");

    for (int i = 0; i < c.Quant; i++) {
        for (int j = i+1; j < c.Quant; j++) {
            valor = strcmp(c.Funcionarios[i].nome, c.Funcionarios[j].nome);
            if (valor > 0) {
                aux = c.Funcionarios[i];
                c.Funcionarios[i] = c.Funcionarios[j];
                c.Funcionarios[j] = aux;
            }
        }
    }
    printf("\tLista ordenada por nome!\n");
    printf("---------------------------------------\n");
}


// funcao que ordena a lista de funcionarios por salario;
void OrdenaSalario () {

    Registro aux;
    printf("----- ORDENANDO LISTA POR SALARIO... -----\n");

    for (int i = 0; i < c.Quant; i++) {
        for (int j = i+1; j < c.Quant; j++) {
            if (c.Funcionarios[i].salario < c.Funcionarios[j].salario) {
                aux = c.Funcionarios[i];
                c.Funcionarios[i] = c.Funcionarios[j];
                c.Funcionarios[j] = aux;
            }
        }
    }
    printf("\tLista ordenada por salario!\n");
    printf("------------------------------------------\n");
}


int main () {

    Registro novoFuncionario;
    int opcao;

    printf("--------------------------------------------------\n");
    LeFuncionarios(novoFuncionario);
    
    do {
        printf("\n");
        printf("Deseja...\n");
        printf("1 - Cadastrar mais funcionarios\n");
        printf("2 - Imprimir lista de funcionarios\n");
        printf("3 - Ordenar lista por nome\n");
        printf("4 - Ordenar lista por salario\n");
        printf("Digite 0  para sair\n");
        scanf("%d", &opcao);

    switch (opcao)
    {
    case 0:
        printf("Programa encerrado...\n");
        break;
    case 1:
        LeFuncionarios(novoFuncionario);
        break;
    case 2:
        ListaFuncionarios();
        break;
    case 3:
        OrdenaNome();
        break;
    case 4:
        OrdenaSalario();
        break;
    default:
        printf("Opcao invalida!\n");
        break;
    }

    } while (opcao != 0);

    printf("--------------------------------------------------\n");

    return 0;
}
