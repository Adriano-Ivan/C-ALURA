#include<stdlib.h>
#include<stdio.h>
#include<locale.h>
#include<time.h>

void imprimir_cabecalho(){
 // Imprime cabeçalho do jogo
    printf("\n\n");
    printf("          P  /_\\  P                              \n");
    printf("         /_\\_|_|_/_\\                            \n");
    printf("     n_n | ||. .|| | n_n         Bem vindo ao     \n");
    printf("     |_|_|nnnn nnnn|_|_|     Jogo de Adivinhação! \n");
    printf("    |" "  |  |_|  |"  " |                         \n");
    printf("    |_____| ' _ ' |_____|                         \n");
    printf("          \\__|_|__/                              \n ");
    printf("\n\n");
}

void exibirFeedback(int acertou,int tentativas, int pontos){
    printf("%d\n",acertou);
    if(acertou==1) {
        printf("             OOOOOOOOOOO               \n");
        printf("         OOOOOOOOOOOOOOOOOOO           \n");
        printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
        printf("    OOOOOO      OOOOO      OOOOOO      \n");
        printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
        printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
        printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
        printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
        printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
        printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
        printf("         OOOOOO         OOOOOO         \n");
        printf("             OOOOOOOOOOOO              \n");
        printf("\n\n");

        printf("Parabéns! Você ganhou!\n");
        printf("Você acertou em %d tentativas!\n", tentativas);
        printf("Total de pontos: %.1f\n", pontos);

    } else {
            printf("Você perdeu! Tente de novo!\n");

            printf("       \\|/ ____ \\|/    \n");
            printf("        @~/ ,. \\~@      \n");
            printf("       /_( \\__/ )_\\    \n");
            printf("          \\__U_/        \n");
    }
}

void imprimir_opcoes_de_dificuldade(){
    printf("Escolha um nível de dificuldade para o jogo: \n");
    printf("1 - EASY (25 CHANCES)\n");
    printf("2 - AVERAGE (15 CHANCES)\n");
    printf("3 - HARD (10 CHANCES)\n");
    printf("4 - WARRIOR (5 CHANCES)\n");
    printf("Escolha: ");
}

int main(){
    setlocale(LC_ALL,"Portuguese");
   // char aux_char;

    int segundos_semente = time(0);
    srand(segundos_semente);
    int numero_secreto=rand()%100+1;

    int chute;
    int acertou=0;
    int tentativas = 1;
    double pontos = 2000;

    int numero_de_tentativas;

    imprimir_cabecalho();
    imprimir_opcoes_de_dificuldade();

    scanf("%d", &numero_de_tentativas);

    switch(numero_de_tentativas){
        case 4:
            numero_de_tentativas=5;
            break;
        case 3:
            numero_de_tentativas=10;
            break;
        case 2:
            numero_de_tentativas=15;
            break;
        default:
            numero_de_tentativas=25;
    }

    while(tentativas <= numero_de_tentativas){
        printf("\nTentativa %d\n",tentativas);
        printf("Qual é o seu chute ?");
        scanf(" %d", &chute);
        printf("\nSeu chute foi %d",chute);

        if(chute < 0){
            printf("Você não pode chutar números negativos.");
            continue;
        }

        acertou = chute==numero_secreto;

        if(acertou){
            printf("\nParabéns ! O número secreto era %d.\n", chute);
            break;
        }else {
            int maior = chute > numero_secreto;
            
            if(maior){
                printf("\nSeu chute foi maior que o chute secreto.\n");
            }else{
                printf("\nSeu chute foi menor que o chute secreto.\n");
            }
            printf("\nInfelizemnte, você errou dessa vez.\n");

        }
        tentativas++;

        double pontos_perdidos =abs(chute - numero_secreto) / (double)2;
        pontos = pontos-pontos_perdidos;
    }
    printf("\nFIM DE JOGO\n");
    
    exibirFeedback(acertou,tentativas, pontos);
  
    //scanf(" %c",&aux_char);
    return 0;
}