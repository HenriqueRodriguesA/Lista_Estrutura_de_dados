#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int mdc(int x, int y)
{
    int resto;
    do{
        resto=x%y;
        x=y;
        y=resto;
    }while(resto!=0);
    return x;
}

void Enumerasao(int k){
    int d,n;
    int aux1,aux2;
    int count = 0;
    for(d=1;d<=181;d++){
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
    unsigned int vet[10000],j,i=0;
    do{
        scanf("%d",&vet[i]);
        i++;
    }while(vet[i-1]!=0);
    for(j=0;j<i;j++){
        Enumerasao(vet[j]);
    }
    return 0;
}
