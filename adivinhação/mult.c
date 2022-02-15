#include<stdio.h>
/*
int main(){
    int x;
    int y;
    int c_aux;

    printf("Digite o primeiro: ");scanf("%d", &x);

    printf("Digite o segundo: ");
    scanf("%d",&y);

    printf("\nO produto entre %d e %d é igual a %d.\n",x,y,x*y);

    scanf(" %c",&c_aux);
    return 0;

}*/
int main(){
int chute = 0;
int numerosecreto = 42;
int acertou = chute == numerosecreto;
printf("eita");
if(acertou) {
    printf("Parabéns! Você acertou!\n");
} else {
    if(chute > numerosecreto) {
        printf("Seu chute foi maior do que o número secreto!\n");
    } 
    if(chute < numerosecreto) {
        printf("Seu chute foi menor do que o número secreto!\n");
    }
}
return 0;
}