#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//Olimpíadas


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
    int i,j,modalidade,nasao,medalha,min,aux;
    do{
            scanf("%d",&nasao);
    }while((nasao<1)||(nasao>100));
    do{
        scanf("%d",&modalidade);
    }while((modalidade<1)||(modalidade>50));
    int Vetor[nasao][2];
    for(i=0;i<(nasao);i++){
        Vetor[i][0]=i+1;
        Vetor[i][1]=0;
    }
    for(i=0;i<modalidade;i++){
        for(j=0;j<3;j++){
            scanf("%d",&medalha);
            if(j==0){
                Vetor[medalha-1][1]+=100;
            }
            else if(j==1){
                Vetor[medalha-1][1]+=15;
            }
            else if(j==2){
                Vetor[medalha-1][1]+=1;
            }
        }
    }
    for(i=0;i<nasao-1;i++){
        min=i;
        for(j=i+1;j<nasao;j++){
            if(Vetor[j][1]>Vetor[min][1]){
                min=j;
            }
        }
        if(Vetor[i][1]!=Vetor[min][1]){
            aux=Vetor[i][1];
            medalha=Vetor[i][0];
            Vetor[i][1]=Vetor[min][1];
            Vetor[i][0]=Vetor[min][0];
            Vetor[min][1]=aux;
            Vetor[min][0]=medalha;
        }
    }
    for(i=0;i<nasao;i++){
        printf("%d ",Vetor[i][0]);
    }
    return 0;
}

