#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "forca.h"

char palavra_secreta[TAMANHO_DA_PALAVRA];
char chutes[26];
int numero_de_chutes= 0;

void validarAberturaDoArquivo(FILE* f){
    if(f == NULL){
       printf("Desculpe, o banco de dados nao esta disponivel.\n\n");
       exit(1);
   }
}
void imprimirCabecalho(){
    printf("***************************\n");
    printf("        Jogo de Forca      \n");
    printf("***************************\n");
}

void chutar(){
    char chute;
    scanf(" %c",&chute);

    chutes[numero_de_chutes]=chute;
    numero_de_chutes++;
}

void desenhar_forca(){

    int erros = pegar_quantidades_de_numeros_errados();

    printf("  _______      \n");
    printf(" |/      |     \n");
    printf(" |      %c%c%c \n",(erros >=1 ? '(':' '),(erros >= 1 ? '_': ' '),(erros >= 1? ')':' ') );
    printf(" |      %c%c%c \n",(erros >=3 ? '\\': ' '),(erros >=2 ? '|':' '),(erros >= 3 ?'/':' '));
    printf(" |       %c    \n",(erros >= 2 ? '|': ' '));
    printf(" |      %c %c  \n",(erros >=4 ?'/':' '),(erros >= 4 ?'\\':' '));
    printf(" |             \n");
    printf("_|___          \n");
    printf("\n\n");

    for(int i = 0; i <strlen(palavra_secreta);i++){
        // imprime palavra secreta
        int achou = ja_chutou(palavra_secreta[i]);

        if(achou){
            printf("%c ",palavra_secreta[i]);
        }else{
            printf("_ ");
        }   
    }
}

void adicionar_palavra(){
    char quer_adicionar;

    printf("Voce deseja adicionar uma nova palavra ao jogo ? (S/N) ");

    scanf(" %c", &quer_adicionar);

    if(quer_adicionar=='S'){
        char nova_palavra[TAMANHO_DA_PALAVRA];
        printf("Qual a nova palavra ? ");
        scanf("%s", nova_palavra);

        FILE* file;

        file = fopen("palavras.txt","r+");
        validarAberturaDoArquivo(file);

        int qtd;
        fscanf(file, "%d",&qtd);
        qtd++;

        fseek(file,0,SEEK_SET);
        fprintf(file,"%d",qtd);

        fseek(file, 0, SEEK_END);

        fprintf(file,"\n%s",nova_palavra);

        fclose(file);
    }
}
void escolher_palavra(){
   FILE* f;

   f = fopen("palavras.txt","r");

   validarAberturaDoArquivo(f);
   
   int qtd_de_palavras;
   fscanf(f,"%d",&qtd_de_palavras);

   srand(time(0));
   int randomico = rand()% qtd_de_palavras;

   for(int i = 0; i <= randomico; i++){
       fscanf(f,"%s",palavra_secreta);
   }

   fclose(f);
}

int acertou(){
    for(int i = 0; i < strlen(palavra_secreta);i++){
        if(!ja_chutou(palavra_secreta[i])){
            return 0;
        }
    }

    return 1;
}

int pegar_quantidades_de_numeros_errados(){
   int erros = 0;

   for(int i = 0; i < numero_de_chutes;i++){
         int existe = 0;

        for(int j = 0; j < strlen(palavra_secreta);j++){

            if(chutes[i]==palavra_secreta[j]){
                existe = 1;
                break;
            }
        }

         if(!existe) erros++;
   }

   return erros;
}
int enforcou(){
   int erros = pegar_quantidades_de_numeros_errados();
   return erros >= 5;
}

int ja_chutou(char letra){
    int achou = 0;
    for(int j = 0; j < numero_de_chutes
    ; j++){
        if(chutes[j]==letra){
            achou = 1;
            break;
        }
    }

    return achou;
}

int main(){
    escolher_palavra();

    imprimirCabecalho();

    do{
        desenhar_forca();
        printf("\n");

        chutar();

    } while(!acertou()  && !enforcou() );

    if(acertou()){
        desenhar_forca();
        printf("\nParabéns ! Voce ganhou !\n");
    }else{
        printf("\nVoce perdeu dessa vez ! Tente novamente quando puder !\n\n");
    }
    
    adicionar_palavra();

    return 0;
}