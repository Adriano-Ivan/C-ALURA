#include<stdlib.h>
#include<stdio.h>

int main(){
    int soma = 0;
    int i = 1;

    while(i <= 100){
        soma += i++;
    }

    printf("O resultado é %d\n",soma);

    return 0;
}