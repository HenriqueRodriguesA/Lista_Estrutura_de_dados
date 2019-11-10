#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double multiplica (int a,int n){
    int i;
    double aux=1;
    for(i=0;i<n;i++){
        aux*=a;
    }
    return aux;

}

int main()
{
    unsigned int n,i,cont=0;
    double aux1=1,aux2=1;
    do{
        scanf("%d",&n);
    }while((n<1)||(n>100000));
    unsigned int vet[n];
    for(i=0;i<n;i++){
        do{
            scanf("%d",&vet[i]);
        }while((vet[i]<1)||(vet[i]>100000));
        aux1*=vet[i];

    }
    while(aux1>=aux2){
        cont++;
        aux2=multiplica(cont,n);
    }
    for(i=0;i<n;i++){
        vet[i]=cont;
    }
    for(i=0;i<n;i++){
        printf("%d ",vet[i]);
    }
    return 0;
}
