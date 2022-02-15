#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
   int num;

   while(1){
    printf("INTEGER NUMBER: (0 to close) ");
    scanf("%d",&num);
    if(num==0) break;

   for(int i = 1; i <=10;i++){
       printf("%d x %d = %d\n", num, i, num * i);
   }
   }
   
}