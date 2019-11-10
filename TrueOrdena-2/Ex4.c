#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Placar

typedef struct{
int resolvidos;
char nome[50];
}aluno;


int main()
{
    int n,i,j,aux,auxi;
    char nomeaux[50];
    do{
        scanf("%d",&n);
    }while((n<1)||(n>100));
    aluno Alunos[n];
    for(i=0;i<n;i++){
        scanf("%s",Alunos[i].nome);
        scanf("%d",&Alunos[i].resolvidos);
        getchar();
    }
    for(i=0;i<n;i++){
        aux=Alunos[i].resolvidos;
        strcpy(nomeaux,Alunos[i].nome);
        auxi=i;
        for(j=i+1;j<n;j++){
            if(aux<=Alunos[j].resolvidos){
                if(aux==Alunos[j].resolvidos){
                    if((strcmp(nomeaux,Alunos[j].nome))>0){
                        strcpy(nomeaux,Alunos[j].nome);
                        auxi=j;
                    }
                }
                else{
                    aux=Alunos[j].resolvidos;
                    strcpy(nomeaux,Alunos[j].nome);
                    auxi=j;
                }
            }
        }
        if(auxi!=j){
            Alunos[auxi].resolvidos=Alunos[i].resolvidos;
            strcpy(Alunos[auxi].nome,Alunos[i].nome);
            Alunos[i].resolvidos=aux;
            strcpy(Alunos[i].nome,nomeaux);
        }
    }
    for(i=0;i<n-1;i++){
        printf("%s %d\n",Alunos[i].nome,Alunos[i].resolvidos);
    }
    printf("%s %d #reprovado(a)",Alunos[n-1].nome,Alunos[n-1].resolvidos);
    return 0;
}
