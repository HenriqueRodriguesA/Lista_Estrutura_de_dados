#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long int contarvogais(char* palavra,int n){
    char Vogais[] = "AEIOUaeiou";
    int cont=0,i,j;
    for(i=0; i<n;i++){
        for(j=0;j<10;j++){
            if((Vogais[j])==(palavra[i])){
                cont++;
            }
        }
    }
    return cont;
}

int main()
{
    int n,i,aux;
    char palavra[10000];
    do{
        scanf("%d",&n);
    }while((n<1)||(n>100));
    for(i=0;i<n;i++){
        getchar();
        do{
        scanf("%[^\n]",palavra);
        }while((strlen(palavra)<1)||(strlen(palavra)>10000));
        aux=strlen(palavra);
        printf("%ld\n",contarvogais(palavra,aux));
    }
    return 0;
}
