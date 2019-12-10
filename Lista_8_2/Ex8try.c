#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    int i, aux=1, n;
    int vet [1000];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&vet[i]);
    }
    if(n==1){
        printf("sim");
    }
    else{
        if(vet[0]>vet[1]){
            for(i=0;i<n-1;i++){
                if(vet[i]<vet[i+1]){
                    printf("nao");
                    aux=0;
                    break;
                }
            }
            if(aux==1){
                printf("sim");
            }
        }
        else if(vet[0]<vet[1]){
            for(i=0;i<n-1;i++){
                if(vet[i]>vet[i+1]){
                    printf("nao");
                    aux=1;
                    break;
                }
            }
            if(aux==1){
                printf("sim");
            }
        }
    }
    return 0;
}
