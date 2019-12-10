#include <stdio.h>
#include <stdlib.h>

#define SUCESSO 1
#define FALHA 0

typedef struct celula* ApontaCelula;
typedef struct descritor* ApontaDescritor;

struct celula{
    int chave;
    int crit;
    ApontaCelula prox;
};

struct descritor{
    ApontaCelula prim;
    int tam;
    ApontaCelula ult;
};

int CriarLista(ApontaDescritor* p){
    *p = (ApontaDescritor) malloc(sizeof(struct descritor));
    if((*p)==NULL){
        return(FALHA);
    }
    else{
        (*p)->prim = (ApontaCelula) NULL;
        (*p)->tam = 0;
        (*p)->ult = (ApontaCelula) NULL;
        return(SUCESSO);
    }
}

int InsInicio(ApontaDescritor* p, int chave, int crit){
    ApontaCelula q;
    q = (ApontaCelula) malloc(sizeof(struct celula));
    if(q==NULL){
        return(FALHA);
    }
    else{
        q->chave = chave;
        q->crit = crit;
        q->prox = (*p)->prim;
        (*p)->prim = q;
        if((*p)->tam==0){
            (*p)->ult=q;
        }
        (*p)->tam++;
        return(SUCESSO);
    }
}

int InsFinal(ApontaDescritor* p, int chave, int crit){
    ApontaCelula q;
    if((*p)->tam==0){
        return(InsInicio(p,chave,crit));
    }
    else{
        q = (ApontaCelula) malloc(sizeof(struct celula));
        if(q==NULL){
            return(FALHA);
        }
        q->chave = chave;
        q->crit = crit;
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
            return(SUCESSO);
        }
    }
}

int RemFinal(ApontaDescritor* p){
    ApontaCelula r,s;
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
        s->prox = (ApontaCelula) NULL;
        (*p)->ult = s;
        (*p)->tam--;
        free(r);
        return(SUCESSO);
    }
}

int opera(ApontaDescritor* p,int op){
    ApontaCelula q;
    int j;
    if((*p)->tam==0){
        return(FALHA);
    }
    else{
        q = (*p)->prim;
        if(q->crit<op){
            RemInicio(p);
            return(1);
        }
        else{
            RemInicio(p);
            return(0);
        }
    }
}

int MostrarLista(ApontaDescritor* p){
    ApontaCelula q;
    int i,op=420;
    q = (*p)->prim;
    for(i=0;i<(*p)->tam;i++){
        printf("%d %d |%d|\n",q->chave,q->crit,op);
        op+=30;
        q=q->prox;
    }
    return(SUCESSO);
}

int main()
{
    int i, j, aux, auxHora, auxMim, auxCrit, cont=0, op=420;
    ApontaDescritor p;
    ApontaCelula q;
    j=CriarLista(&p);
    scanf("%d" ,&aux);
    for(i=0;i<aux;i++){
        scanf("%d %d %d",&auxHora,&auxMim,&auxCrit);
        auxHora = (auxHora*60)+auxMim;
        auxCrit = auxCrit+auxHora;
        j= InsFinal(&p,auxHora,auxCrit);
    }
    q = (p)->prim;
    if(op!=q->chave){
        op=q->chave;
        if((op%30)!=0){
            if((op%30)==10){
                op+=20;
            }
            else if((op%30)==20){
                op+=10;
            }
        }
    }
    for(i=0;i<aux;i++){
        j=opera(&p,op);
        cont=cont+j;
        op+=30;
        if(i!=aux-1){
        if((((p)->prim)->chave)>op){
                op=(((p)->prim)->chave);
                if((op%30)!=0){
                    if((op%30)==10){
                        op+=20;
                    }
                    else if((op%30)==20){
                        op+=10;
                    }
                }
            }
        }
    }
    printf("%d",cont);
    return 0;
}
