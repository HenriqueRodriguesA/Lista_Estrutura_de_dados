#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    int i=0,aux,j,cont,test=0,veti=0;
    char equa[1000],c;
    int vet[1000];
    scanf("%d",&test);
    getchar();
    while(test!=0){
        veti=0;
        aux=1;
        vet[veti]=-1;
        test--;
        scanf("%[^\n]",equa);
        getchar();
        cont = strlen(equa);
        for(i=0;i<cont;i++){
            if(equa[i]=='('){
                vet[veti]=1;
                veti++;
            }
            else if(equa[i]=='{'){
                vet[veti]=2;
                veti++;
            }
            else if(equa[i]=='['){
                vet[veti]=3;
                veti++;
            }
            else if(equa[i]==')'){
                if(vet[veti-1]==1){
                    vet[veti-1]=-1;
                    veti--;
                }
                else{
                    aux=0;
                }
            }
            else if(equa[i]=='}'){
                if(vet[veti-1]==2){
                    vet[veti-1]=-1;
                    veti--;
                }
                else{
                    aux=0;
                }
            }
            else if(equa[i]==']'){
                if(vet[veti-1]==3){
                    vet[veti-1]=-1;
                    veti--;
                }
                else{
                    aux=0;
                }
            }
            if(aux==0){
                printf("mal-formada\n");
                break;
            }
        }
        if(aux!=0){
            if(vet[0]==-1){
                printf("bem-formada\n");
            }
            else{
                printf("mal-formada\n");
            }
        }
    }
    return 0;
}
