#include <stdio.h>
#include <stdlib.h>

//Separando Pares e Impares.

int main()
{
    int n,i,j,contpar=0,contimpar=0,auxi;

    do{
        scanf("%d",&n);
    }while((n<1)||(n>100));
    long int vet[n],par[n],impar[n],aux;
    for(i=0;i<n;i++){
        scanf("%ld",&vet[i]);
    }
    for(i=0;i<n;i++){
        if((vet[i]%2)==0){
            par[contpar]=vet[i];
            contpar++;
        }
        else{
            impar[contimpar]=vet[i];
            contimpar++;
        }
    }
    if(contpar!=0){
        for(i=0;i<contpar;i++){
            aux=par[i];
            auxi=i;
            for(j=i+1;j<contpar;j++){
                if(aux>par[j]){
                    aux=par[j];
                    auxi=j;
                }
            }
            if(auxi!=i){
                par[auxi]=par[i];
                par[i]=aux;
            }
        }
    }
    if(contimpar!=0){
        for(i=0;i<contimpar;i++){
            aux=impar[i];
            auxi=i;
            for(j=i+1;j<contimpar;j++){
                if(aux<impar[j]){
                    aux=impar[j];
                    auxi=j;
                }
            }
            if(auxi!=i){
                impar[auxi]=impar[i];
                impar[i]=aux;
            }
        }
    }
    if(contpar!=0){
        for(i=0;i<contpar;i++){
            printf("%ld ",par[i]);
        }
        if(contimpar!=0){
            printf("\n");
        }
    }
    if(contimpar!=0){
        for(i=0;i<contimpar;i++){
            printf("%ld ",impar[i]);
        }
    }
    return 0;
}
