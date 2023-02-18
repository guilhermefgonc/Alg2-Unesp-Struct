/*
NOME: Guilherme Ferreira Gonçalves   
DATA: 12/2022

Considere a estrutura 
struct vetor{ 
float x; 
float y; 
float z; 
}; 
que represente um vetor no R3. Desenvolva um programa que calcule a soma de dois 
vetores.
*/


#include <stdio.h>


typedef struct {
    float x,y,z;
} vetor;


void somaVetoresR3() {

    // leitura dos vetores
    vetor v1, v2, vSoma;
    printf("\n##### SOMA DE VETORES #####\n\n");
    printf("Digite o valor do primeiro vetor:\n");
    printf("\tX: ");
    scanf("%f", &v1.x);
    printf("\tY: ");
    scanf("%f", &v1.y);
    printf("\tZ: ");
    scanf("%f", &v1.z);
    printf("\nDigite o valor do segundo vetor:\n");
    printf("\tX: ");
    scanf("%f", &v2.x);
    printf("\tY: ");
    scanf("%f", &v2.y);
    printf("\tZ: ");
    scanf("%f", &v2.z);
    scanf("%*c");

    // soma dos vetores
    vSoma.x = v1.x + v2.x;
    vSoma.y = v1.y + v2.y;
    vSoma.z = v1.z + v2.z;
    printf("\nVetores somados!\n\n");
    printf("Primeiro vetor:   X: %.2f | Y: %.2f | Z: %.2f\n", v1.x, v1.y, v1.z);
    printf("Segundo vetor:    X: %.2f | Y: %.2f | Z: %.2f\n", v2.x, v2.y, v2.z);
    printf("Soma dos vetores: X: %.2f | Y: %.2f | Z: %.2f\n", vSoma.x, vSoma.y, vSoma.z);
    printf("\n");
    printf("###########################\n\n");
}


int main () {

    int opcao;
    printf("##### SOMA DE VETORES NO R3 #####\n\n");
    
    do {
        printf("Deseja...\n");
        printf("0 - Sair do programa\n");
        printf("1 - Somar dois vetores no R3\n");
        scanf("%d", &opcao);

        switch (opcao) {
        case 0:
            printf("Programa encerrado...\n");
            break;
        case 1:
            somaVetoresR3();
            break;
        default:
            printf("Opcao invalida!\n");
            break;
        }
    } while (opcao != 0);
    
    return 0;
}
