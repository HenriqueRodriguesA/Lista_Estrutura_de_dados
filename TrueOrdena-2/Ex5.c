#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Insertion - Selection

int Selection(int *vetor,int n){
    int i,j,min,cont=0;
    for(i=0;i<n-1;i++){
        min=i;
        for(j=i+1;j<n;j++){
            if(vetor[j]<vetor[min]){
            min=j;
            }
        }
        if(vetor[i]!=vetor[min]){
            troca(&vetor[i],&vetor[min]);
            cont++;
        }
    }
    return cont;
}
int Insertion(int *vetor , int n){
    int i,j=1,aux,cont=0;
    while(j<n){
        aux=vetor[j];
        i=j-1;
        while((i>=0)&&(vetor[i]>aux)){
            vetor[i+1]=vetor[i];
            i--;
            cont++;
        }
        vetor[i+1]=aux;
        j++;
        cont++;
    }
    return cont;
}

void troca(int *v,int *b){
    int aux;
    aux=*v;
    *v=*b;
    *b=aux;
}

int main()
{
    int *VetorSel,*VetorInc,a,b;
    int tamanho,i;
    do{
        scanf("%d",&tamanho);
    }while((tamanho<1)||(tamanho>1000));
    VetorSel = (int *) malloc(tamanho * sizeof(int));
    VetorInc = (int *) malloc(tamanho * sizeof(int));
    for(i=0;i<tamanho;i++){
        scanf("%d",&VetorSel[i]);
        VetorInc[i]=VetorSel[i];
    }
    printf("%d",(Insertion(VetorInc,tamanho)-Selection(VetorSel,tamanho)));
    return 0;
}

