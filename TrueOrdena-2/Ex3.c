#include <stdio.h>
#include <stdlib.h>

//Altura

void selection(int vet[] ,int n){
    int i,j,aux,auxi;
    for(i=0;i<n;i++){
        aux=vet[i];
        auxi=i;
        for(j=i+1;j<n;j++){
            if(aux>vet[j]){
                aux=vet[j];
                auxi=j;
            }
        }
        if(auxi!=i){
            vet[auxi]=vet[i];
            vet[i]=aux;
        }
    }
}

int main()
{
    int nc,n,i,j;
    do{
        scanf("%d",&nc);
    }while(nc>100);
    while(nc!=0){
        do{
            scanf("%d",&n);
        }while((n<1)||(n>10000));
        int vet[n],aux;
        for(i=0;i<n;i++){
            scanf("%d",&vet[i]);
        }
        selection(vet,n);
        for(i=0;i<n;i++){
            printf("%d ",vet[i]);
        }
        printf("\n");
        nc--;
    }
    return 0;
}
