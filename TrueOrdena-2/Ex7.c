#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Prime Numbers and Arrays


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
int Primo(int n){
    int i;
    if(n==2){
        return 1;
    }
    if(n==1){
        return 0;
    }
    for(i=2;i<(n+1)/2;i++){
        if((n%i)==0)
            return 0;
    }
    return 1;
}

unsigned int N_esimo(int n){
 int i,contador=1,aux=3,primo;
    if(n==1){
        return 2;
    }
    while(contador<=n){
        if( Primo(aux)==1){
            primo=aux;
            contador++;
            aux++;
        }
        else
            aux++;
    }
    if(n==2){
        return 3;
    }
    return primo;
}
int main()
{
    int *Vetor;
    int tamanho,i,L_esimo,K_esimo,aux;
    do{
        scanf("%d",&tamanho);
    }while((tamanho<1)||(tamanho>1000));
    Vetor=(int *) malloc(tamanho * sizeof(int));
    for(i=0;i<tamanho;i++){
        scanf("%d",&Vetor[i]);
    }
    for(i=0;i<tamanho;i++){
        aux=Vetor[i];
        Vetor[i]=N_esimo(aux);
    }
    Selection(Vetor,tamanho);
    for(i=0;i<tamanho;i++){
        printf("%d ",Vetor[i]);
    }
    return 0;
}
