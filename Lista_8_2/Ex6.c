#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCESSO 1
#define FALHA 0

typedef struct celula* ApontaCelula;
typedef struct descritor* ApontaDescritor;

struct celula{
    int c;
    ApontaCelula prox;
};

struct descritor{
    ApontaCelula prim;
    int tam;
    ApontaCelula ult;
};

int CriarLista(ApontaDescritor* p){
    (*p) = (ApontaDescritor) malloc(sizeof(struct descritor));
    if((*p)==NULL){
        return (FALHA);
    }
    else{
        (*p)->prim = (ApontaCelula) NULL;
        (*p)->tam  = 0;
        (*p)->ult  = (ApontaCelula) NULL;
        return (SUCESSO);
    }
}

int InsInicio (ApontaDescritor* p, int c){
    ApontaCelula q;
    q = (ApontaCelula) malloc(sizeof(struct celula));
    if(q == NULL){
        return (FALHA);
    }
    else{
        q->c = c;
        (*p)->prim = q;
        q->prox = (*p)->prim;
        (*p)->prim =q;
        (*p)->tam++;
        if((*p)->tam==0){
            (*p)->ult = q;
        }
        return(SUCESSO);
    }
}

int InsFinal(ApontaDescritor* p, int c){
    ApontaCelula q;
    if((*p)->tam==0){
        return(InsInicio(p,c));
    }
    else{
        q = (ApontaCelula) malloc(sizeof(struct celula));
        if(q==NULL){
            return(FALHA);
        }
        q->c = c;
        q->prox = (ApontaCelula) NULL;
        ((*p)->ult)->prox = q;
        (*p)->ult = q;
        (*p)->tam++;
        return(SUCESSO);
    }
}

int RemInicio(ApontaDescritor* p){
    ApontaCelula q;
    if((*p)->tam==0){
        return(FALHA);
    }
    else{
        q = (*p)->prim;
        if((*p)->tam==1){
            (*p)->prim = (ApontaCelula) NULL;
            (*p)->tam--;
            (*p)->ult = (ApontaCelula) NULL;
            free(q);
            return(SUCESSO);
        }
        else{
            (*p)->prim = q->prox;
            (*p)->tam--;
            free(q);
            return (SUCESSO);
        }
    }
}

int RemFinal(ApontaDescritor* p){
    ApontaCelula r,s;
    if((*p)->tam<=1){
        return (RemInicio(p));
    }
    else{
        r = (*p)->prim;
        s = (*p)->prim;
        while (r->prox != NULL){
            s = r;
            r = r->prox;
        }
        s->prox = (ApontaCelula) NULL;
        (*p)->ult = s;
        (*p)->tam--;
        free(r);
        return(SUCESSO);
    }
}

int RemChave(ApontaDescritor* p, int chave){
    ApontaCelula r,s;
    if((*p)->tam==0){
        return(FALHA);
    }
    else{
        if((*p)->prim->c==chave){
            return(RemInicio(p));
        }
        else if((*p)->ult->c==chave){
            return(RemFinal(p));
        }
        r = (*p)->prim;
        s = (*p)->prim;
        while((r->c!=chave)&&(r->prox!=NULL)){
            s=r;
            r=r->prox;
        }
        if(r->c==chave){
            s->prox=r->prox;
            (*p)->tam--;
            free(r);
            return(SUCESSO);
        }
        return(FALHA);
    }
}

int MostrarLista(ApontaDescritor* p){
    ApontaCelula q;
    int i;
    q = (*p)->prim;
    for(i=0;i<(*p)->tam;i++){
        printf("%d ",q->c);
        q=q->prox;
    }
    printf("\n");
    return(SUCESSO);
}

int main()
{
    int i=0,aux=1,j,cont;
    char equa[1000],c;
    ApontaDescritor p;
    j=CriarLista(&p);
    scanf("%[^\n]",equa);
    cont = strlen(equa);
    for(i=0;i<cont;i++){
        if(equa[i]=='('){
            j = InsInicio(&p,1);
        }
        else if(equa[i]==')'){
            aux = RemInicio(&p);
        }
        if(aux==0){
            printf("incorreta");
            break;
        }
    }
    if(aux!=0){
        if((p)->tam==0){
            printf("correta");
        }
        else{
            printf("incorreta");
        }
    }
    return 0;
}
