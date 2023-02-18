/* 
NOME: Guilherme Ferreira Gonçalves
DATA: 12/2022

Defina uma estrutura que represente bandas de música. Essa estrutura deve ter o no-
me da banda, que tipo de música ela toca, o número de integrantes e em que posição 
do ranking essa banda está dentre as suas cinco bandas favoritas. Se a banda não es-
tiver tiver entre suas cinco bandas favoritas, utilize o número zero neste campo. Em se-
guida, desenvolva as funções que seguem: 
 
a) Faça uma função que cadastre um determinado número de bandas. A quantidade de 
bandas a serem cadastradas deve ser fornecida pelo usuário. As bandas devem ser 
armazenadas em um vetor em que cada elemento é uma estrutura conforme defini-
do anteriormente.  
b) Faça uma função que faça uma busca de acordo com o ranking da banda. Essa fun-
ção deve exibir todas as informações da banda de um determinado ranking. 
c)  Crie uma função que solicite ao usuário um tipo de música e exiba as bandas com 
esse tipo de música no seu ranking.  
d) Crie uma função que solicite o nome de uma banda ao usuário e informe se ela está 
entre suas bandas favoritas ou não 
*/

#include <stdio.h>
#define TAM 10


typedef struct {
    char nome[50];
    int tipo;
    int integrantes;
    int ranking;
} Banda;
Banda ListaDeBandas[TAM];


int cadastroBanda () {

    int numero;
    printf("##### CADASTRO DE BANDAS #####\n\n");
    printf("Quantas bandas deseja cadastrar? (No maximo 10): ");
    scanf("%d", &numero);
    printf("\n");

    Banda b;
    for (int i = 0; i < numero; i++) {
        printf("Nome da banda: ");
        scanf("%*c"); // para limpar o buffer do teclado
        fgets(b.nome, 50, stdin);
        printf("Tipo de musica que a banda toca (1- Rock, 2- Pop, 3- Funk, 4- Reggae, 5- Outro): ");
        scanf("%d", &b.tipo);
        printf("Numero de integrantes da banda: ");
        scanf("%d", &b.integrantes);
        printf("Em que posicao do ranking essa banda esta dentre as suas 5 bandas favoritas? (Se nao estiver, digite 0): ");
        scanf("%d", &b.ranking);
        printf("\n");
        ListaDeBandas[i] = b;
          
    }
    printf("##############################\n\n");
    return numero;
}


void buscarPorRanking (int num) {
    
    int rnk;
    printf("##### BUSCA POR RANKING #####\n\n");
    printf("Qual ranking deseja buscar? ");
    scanf("%d", &rnk);
    printf("\n");

    for (int i = 0; i < num; i++) {
        if (ListaDeBandas[i].ranking == rnk) {
            printf("Nome: %s", ListaDeBandas[i].nome);
            switch (ListaDeBandas[i].tipo) {
            case 1:
                printf("Tipo de musica que a banda toca: Rock\n");
                break;
            case 2:
                printf("Tipo de musica que a banda toca: Pop\n");
                break;
            case 3:
                printf("Tipo de musica que a banda toca: Funk\n");
                break;
            case 4:
                printf("Tipo de musica que a banda toca: Reggae\n");
                break;
            default:
                printf("Tipo de musica que a banda toca: Outro\n");
                break;
            }
            printf("Numero de integrantes da banda: %d\n", ListaDeBandas[i].integrantes);
            printf("Posicao no ranking: %d\n", ListaDeBandas[i].ranking);
            printf("\n");
        }
    }
    printf("\n#############################\n\n");
}


void buscarPorTipo (int num) {

    int genero;
    printf("##### BUSCA POR TIPO #####\n\n");
    printf("Qual tipo deseja buscar? (1- Rock, 2- Pop, 3- Funk, 4- Reggae, 5- Outro) ");
    scanf("%d", &genero);
    printf("\n");

    for (int i = 0; i < num; i++) {
        if (ListaDeBandas[i].tipo == genero) {
            printf("Nome: %s", ListaDeBandas[i].nome);
            switch (ListaDeBandas[i].tipo) {
            case 1:
                printf("Tipo de musica que a banda toca: Rock\n");
                break;
            case 2:
                printf("Tipo de musica que a banda toca: Pop\n");
                break;
            case 3:
                printf("Tipo de musica que a banda toca: Funk\n");
                break;
            case 4:
                printf("Tipo de musica que a banda toca: Reggae\n");
                break;
            default:
                printf("Tipo de musica que a banda toca: Outro\n");
                break;
            }
            printf("Numero de integrantes da banda: %d\n", ListaDeBandas[i].integrantes);
            printf("Posicao no ranking: %d\n", ListaDeBandas[i].ranking);
            printf("\n");
        }
    }
    printf("\n#############################\n\n");
}


void entreFavoritas (int num) {

    printf("##### FAVORITAS #####\n\n");

    for (int i = 0; i < num; i++) {
        if (ListaDeBandas[i].ranking > 0 && ListaDeBandas[i].ranking <= 5) {
            printf("Nome: %s", ListaDeBandas[i].nome);
            switch (ListaDeBandas[i].tipo) {
            case 1:
                printf("Tipo de musica que a banda toca: Rock\n");
                break;
            case 2:
                printf("Tipo de musica que a banda toca: Pop\n");
                break;
            case 3:
                printf("Tipo de musica que a banda toca: Funk\n");
                break;
            case 4:
                printf("Tipo de musica que a banda toca: Reggae\n");
                break;
            default:
                printf("Tipo de musica que a banda toca: Outro\n");
                break;
            }
            printf("Numero de integrantes da banda: %d\n", ListaDeBandas[i].integrantes);
            printf("Posicao no ranking: %d\n", ListaDeBandas[i].ranking);
            printf("\n");
        }
    }
    printf("\n#####################\n\n");
}


int main () {

    int num;
    printf("\nSeja bem-vindo ao programa de cadastro de bandas!\n\n");
    num = cadastroBanda();
    
    int opcao;
    
    do {
        printf("Deseja:\n");
        printf("1 - Buscar banda por ranking\n");
        printf("2 - Buscar banda por tipo de musica\n");
        printf("3 - Saber se uma banda esta entre suas favoritas\n");
        printf("Digite 0 para sair...\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 0:
            printf("Tchau...");
            break;
        case 1:
            buscarPorRanking(num);
            break;
        case 2:
            buscarPorTipo(num);
            break;
        case 3:
            entreFavoritas(num);
            break;
        default:
            printf("Opcao invalida!\n\n");
            break;
        }

    } while (opcao != 0);

    return 0;
}
