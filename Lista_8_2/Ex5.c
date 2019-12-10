#include <stdio.h>
#include <stdlib.h>


void ordena(int *vet, int tam){
    int i,j,aux,auxi;
    for(i=0;i<tam;i++){
        aux=vet[i];
        auxi=i;
        for(j=i+1;j<tam;j++){
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
    return;
}

void ordenaDec(int *vet, int tam){
    int i,j,aux,auxi;
    for(i=0;i<tam;i++){
        aux=vet[i];
        auxi=i;
        for(j=i+1;j<tam;j++){
            if(aux<vet[j]){
                aux=vet[j];
                auxi=j;
            }
        }
        if(auxi!=i){
            vet[auxi]=vet[i];
            vet[i]=aux;
        }
    }
    return;
}

void mostrar(int *vet,int tam){
    int i;
    for(i=0;i<tam;i++){
        printf("%d ",vet[i]);
    }
    printf("\n");
}

int main()
{
    int t,i,d,p;
    int John,ContJohn,TimeJohn,Jack,ContJack,TimeJack,Joseph,ContJoseph,TimeJoseph;
    scanf("%d",&t);
    while(t!=0){
        scanf("%d %d", &d, &p);
        int probJohn[p],probJack[p],probJoseph[p];
        for(i=0;i<p;i++){
            scanf("%d",&probJohn[i]);
            probJack[i] = probJohn[i];
            probJoseph[i] = probJohn[i];
        }
        ordena(probJack,p);
        ordenaDec(probJoseph,p);
        John=0,ContJohn=0,TimeJohn=0,Jack=0,ContJack=0,TimeJack=0,Joseph=0,TimeJoseph=0,ContJoseph=0;
        for(i=0;i<p;i++){
            if((TimeJohn+probJohn[i])<=d){
                John+=(TimeJohn+probJohn[i]);
                TimeJohn+=probJohn[i];
                ContJohn++;
            }
            if((TimeJack+probJack[i])<=d){
                Jack+=(TimeJack+probJack[i]);
                TimeJack+=probJack[i];
                ContJack++;
            }
            if((TimeJoseph+probJoseph[i])<=d){
                Joseph+=(TimeJoseph+probJoseph[i]);
                TimeJoseph+=probJoseph[i];
                ContJoseph++;
            }
        }
        if((ContJohn>ContJack)&&(ContJohn>ContJoseph)){
            printf("John %d %d\n",ContJohn,John);
        }
        else if((ContJack>ContJohn)&&(ContJack>ContJoseph)){
            printf("Jack %d %d\n",ContJack,Jack);
        }
        else if((ContJoseph>ContJack)&&(ContJoseph>ContJohn)){
            printf("Joseph %d %d\n",ContJoseph,Joseph);
        }
        else if((ContJohn==ContJack)&&(ContJohn>ContJoseph)){
            if(John<Jack){
                printf("John %d %d\n",ContJohn,John);
            }
            else{
                printf("Jack %d %d\n",ContJack,Jack);
            }
        }
        else if((ContJohn==ContJoseph)&&(ContJohn>ContJack)){
            if(Joseph<John){
                printf("Joseph %d %d\n",ContJoseph,Joseph);
            }
            else if(John<Joseph){
                printf("John %d %d\n",ContJohn,John);
            }
            else{
                printf("Joseph %d %d\n",ContJoseph,Joseph);
            }
        }
        else if((ContJoseph==ContJack)&&(ContJohn<ContJoseph)){
            if(Joseph<Jack){
                printf("Joseph %d %d\n",ContJoseph,Joseph);
            }
            else{
                printf("Jack %d %d\n",ContJack,Jack);
            }
        }
        else if((ContJoseph==ContJack)&&(ContJohn==ContJoseph)){
            if((Jack<John)&&(Jack<Joseph)){
                printf("Jack %d %d\n",ContJack,Jack);
            }
            else if((Jack>John)&&(John<Joseph)){
                printf("John %d %d\n",ContJohn,John);
            }
            else if((Jack>Joseph)&&(Jack>Joseph)){
                printf("Joseph %d %d\n",ContJoseph,Joseph);
            }
            else{
                printf("Joseph %d %d\n",ContJoseph,Joseph);
            }
        }
        t--;
    }
    return 0;
}
