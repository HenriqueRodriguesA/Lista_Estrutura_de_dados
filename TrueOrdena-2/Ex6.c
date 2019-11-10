#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Ordenação


void Selection(int *vetor,int n){
    int i,j,min;
    for(i=0;i<n-1;i++){
        min=i;
        for(j=i+1;j<n;j++){
            if(vetor[j]<vetor[min]){
            min=j;
            }
        }
        if(vetor[i]!=vetor[min]){
            troca(&vetor[i],&vetor[min]);
        }
    }
}

void troca(int *v,int *b){
    int aux;
    aux=*v;
    *v=*b;
    *b=aux;
}

int main()
{
    int n,i,aux1,aux2;
    do{
        scanf("%d",&n);
    }while((n<1)||(n>1000));
    int vet[n];
    for(i=0;i<n;i++){
        scanf("%d",&vet[i]);
    }
    scanf("%d %d",&aux1,&aux2);
    Selection(vet,n);
    printf("%d",(vet[aux1-1]+vet[aux2-1]));
    return 0;
}

