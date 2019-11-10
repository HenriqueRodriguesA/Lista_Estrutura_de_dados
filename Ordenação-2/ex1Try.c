#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int mdc(int x, int y)
{
    int resto;
    do{
        resto = x%y;
        x=y;
        y=resto;
    }while(resto!=0);

    return x;
}

void Enumerasao(int k){
    int d,n;
    int aux1,aux2;
    int count = 0;
    for(d=1;d<200;d++){
        for(n=0;n<=d;n++){
            if((mdc(n,d)) == 1){
                count++;
            }
            if(count==k){
                printf("%d/%d\n",n,d);
                return;
            }
        }
    }
}

int main()
{
    int vet[10000],cont=0,i=0;
    do{
        scanf("%d",&vet[i]);
        i++;
        cont++;
    }while(vet[i-1]!=0);
    for(i=0;i<cont;i++){
        Enumerasao(vet[i]);
    }
    return 0;
}
