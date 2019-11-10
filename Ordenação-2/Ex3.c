#include <stdio.h>
#include <stdlib.h>
#include <string.h>


long int contarvogais(char* palavra){
    char Vogais[] = "aeiouAEIOU";
    int cont=0,i,j;
    for(i=0; palavra[i]!='\0';i++){
        for(j=0;Vogais[j]!='\0';j++){
            if((Vogais[j]) == (palavra[i])){
                cont++;
                break;
            }
        }
    }
    return cont;
}

int main()
{
    int n,i;
    char palavra[10000];
    do{
        scanf("%d",&n);
    }while((n<1)||(n>100));
    for(i=0;i<n;i++){
        getchar();
        do{
        scanf("%s",palavra);
        }while((strlen(palavra)<1)||(strlen(palavra)>10000));
        if(i != (n-1)){
            printf("%ld\n",contarvogais(palavra));
        }
        else{
            printf("%ld",contarvogais(palavra));
        }
    }
    return 0;
}
