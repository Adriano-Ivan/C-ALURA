#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int somar(int numeros[],int tam){
    int a = 0;
    for(int i = 0; i < tam; i++){
        a += numeros[i];
    }
    return a;
}
int main(){

    int numeros[]={23,28,2,8,1};

    printf("RESULT: %d",somar(numeros, sizeof(numeros)/sizeof(int)));
}