#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCESSO 1
#define FALHA 0

typedef struct celula* ApontaCelula;
typedef struct descritor* ApontaDescritor;

struct celula{
    int chave;
    ApontaCelula prox;
};

struct descritor{
    ApontaCelula prim;
    int tam;
    ApontaCelula ult;
};

int InicializarLista(ApontaDescritor* p){
    (*p) = (ApontaDescritor)malloc(sizeof(struct descritor));
    if((*p)==NULL){
        return FALHA;
    }
    else{
        (*p)->prim=(ApontaCelula) NULL;
        (*p)->tam=0;
        (*p)->ult=(ApontaCelula) NULL;
        return(SUCESSO);
    }
}

int InsInicio(ApontaDescritor* p,int chave){
    ApontaCelula q;
    q = (ApontaCelula)malloc(sizeof(struct celula));
    if((q)==NULL){
        return(FALHA);
    }
    else{
        q->chave = chave;
        q->prox = (*p)->prim;
        if((*p)->tam==0){
            (*p)->ult=q;
        }
        (*p)->prim=q;
        (*p)->tam++;
        return(SUCESSO);
    }
}

int InsFinal(ApontaDescritor* p , int chave){
    ApontaCelula q;
    if((*p)->tam==0){
        return(InsInicio(p,chave));
    }
    else{
        q = (ApontaCelula) malloc(sizeof(struct celula));
        if((q)==NULL){
            return(FALHA);
        }
        else{
            q->chave = chave;
            q->prox = (ApontaCelula) NULL;
            ((*p)->ult)->prox = q;
            (*p)->ult = q;
            (*p)->tam++;
            return(SUCESSO);
        }
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
            (*p)->prim=q->prox;
            (*p)->tam--;
            free(q);
            return(SUCESSO);
        }
    }
}

int RemFinal(ApontaDescritor* p){
    ApontaCelula r,s;
    if((*p)->tam==0){
        return(FALHA);
    }
    else{
        if((*p)->tam==1){
            return(RemInicio(p));
        }
        else{
            r = (*p)->prim;
            s = (*p)->prim;
            while(r->prox!=NULL){
                s=r;
                r=r->prox;
            }
            s->prox=(ApontaCelula) NULL;
            (*p)->ult = s;
            (*p)->tam--;
            free(r);
            return(SUCESSO);
        }
    }
}

int RemChave(ApontaDescritor* p, int chave){
    ApontaCelula r,s;
    if((*p)->tam==0){
        return(FALHA);
    }
    else{
        if((*p)->prim->chave==chave){
            return(RemInicio(p));
        }
        else if((*p)->ult->chave==chave){
            return(RemFinal(p));
        }
        r = (*p)->prim;
        s = (*p)->prim;
        while((r->chave!=chave)&&(r->prox!=NULL)){
            s=r;
            r=r->prox;
        }
        if(r->chave==chave){
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
        printf("%d ",q->chave);
        q=q->prox;
    }
    return(SUCESSO);
}

int main()
{
    int i,aux,aux1,j;
    ApontaDescritor p;
    j=InicializarLista(&p);
    scanf("%d",&aux);
    for(i=0;i<aux;i++){
        scanf("%d",&aux1);
        j=InsFinal(&p , aux1);
    }
    scanf("%d",&aux);
    for(i=0;i<aux;i++){
        scanf("%d",&aux1);
        j=RemChave(&p,aux1);
    }
    j=MostrarLista(&p);
    return 0;
}
