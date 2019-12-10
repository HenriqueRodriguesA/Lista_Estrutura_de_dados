#include <stdio.h>
#include <stdlib.h>
#define Sucesso 1
#define Falha -1

typedef struct Descritor* ApontaDescritor;
typedef struct Celula* ApontaCelula;

struct Descritor{
    ApontaCelula prim;
    int tam;
    ApontaCelula ult;
};

struct Celula{
    int chave;
    int ordem;
    ApontaCelula prox;
};

int CriarLista(ApontaDescritor* p){
    (*p)=(ApontaDescritor)malloc(sizeof(struct Descritor));
    if((*p)==NULL){
        return(Falha);
    }
    else{
        (*p)->prim=(ApontaCelula) NULL;
        (*p)->tam=0;
        (*p)->ult= (ApontaCelula) NULL;
        return(Sucesso);
    }
}

int InsInicio(ApontaDescritor* p , int chave){
    ApontaCelula q;
    q = (ApontaCelula) malloc(sizeof(struct Celula));
    if(q==NULL){
        return(Falha);
    }
    else{
            q->chave=chave;
            q->ordem=0;
            q->prox=(*p)->prim;
            (*p)->prim=q;
        if((*p)->tam==0){
            (*p)->ult=q;
        }
        (*p)->tam++;
        return(Sucesso);
    }
}

int InsFinal(ApontaDescritor* p , int chave){
    ApontaCelula q;
    if((*p)->tam==0){
        return(InsInicio(p,chave));
    }
    q = (ApontaCelula) malloc(sizeof(struct Celula));
    if(q==NULL){
        return(Falha);
    }
    else{
        q->chave=chave;
        q->ordem=0;
        q->prox=(ApontaCelula) NULL;
        ((*p)->ult)->prox=q;
        (*p)->ult=q;
        (*p)->tam++;
        return(Sucesso);
    }
}

int InsChave(ApontaDescritor*p ,int chave2,int chave1){
    ApontaCelula q,r;
    if((*p)->tam==0){
        return(Falha);
    }
    else{
        q = (ApontaCelula) malloc(sizeof(struct Celula));
        if(q==NULL){
            return(Falha);
        }
        else{
            if(((*p)->prim)->chave==chave2){
                q->chave=chave1;
                q->prox = ((*p)->prim)->prox;
                ((*p)->prim)->prox=q;
                (*p)->tam++;
                return(Sucesso);
            }
            else if (((*p)->ult)->chave==chave1){
                return(InsFinal(p,chave2));
            }
            else{
                r = (*p)->prim;
                while((r->prox!=NULL)&&(r->chave!=chave1)){
                    r=r->prox;
                }
                q->chave=chave2;
                q->ordem=0;
                q->prox=r->prox;
                r->prox=q;
                (*p)->tam++;
                return(Sucesso);
            }
        }
    }

}

int RemoveInicio(ApontaDescritor* p){
    ApontaCelula q;
    if((*p)->tam==0){
        return (Falha);
    }
    else{
        q = (*p)->prim;
        if((*p)->tam==1){
            (*p)->prim=(ApontaCelula)NULL;
            (*p)->ult=(ApontaCelula) NULL;
        }
        else{
        (*p)->prim=q->prox;
        }
        (*p)->tam--;
        free(q);
        return(Sucesso);
    }
}

int RemoveFinal(ApontaDescritor* p){
    ApontaCelula r,s;
    if((*p)->tam==0){
        return (Falha);
    }
    else{
        if((*p)->tam==1){
            return (RemoveInicio(p));
        }
        else{
            r=(*p)->prim;
            s=(*p)->prim;
            while(r->prox!=NULL){
                s=r;
                r=r->prox;
            }
            s->prox=(ApontaCelula) NULL;
            (*p)->ult=s;
            (*p)->tam--;
            free(r);
            return(Sucesso);
        }
    }


}

int RemoveChave(ApontaDescritor* p, int chave){
    ApontaCelula r,s;
    if((*p)->tam==0){
        return(Falha);
    }
    else{
        if(((*p)->prim)->chave==chave){
            return(RemoveInicio(p));
        }
        else if(((*p)->ult)->chave==chave){
            return (RemoveFinal(p));
        }
        else{
            r = (*p)->prim;
            s = (*p)->prim;
            while((r->prox!=NULL)&&(r->chave!=chave)){
                s=r;
                r=r->prox;
            }
            s->prox=r->prox;
            free(r);
            (*p)->tam--;
            return(Sucesso);
        }
    }
}

void Ordem(ApontaDescritor* p){
    ApontaCelula q;
    int i;
    if((*p)->tam==NULL){
        return;
    }
    else{
        q=(*p)->prim;
        for(i=0;i<(*p)->tam;i++){
            q->ordem=i+1;
            q=q->prox;
        }
        return;
    }
}

void Opera(ApontaDescritor* p,int chave1,int chave2){
    int aux,aux1,i;
    ApontaCelula q;
    unsigned int cont=0;
    if((*p)->tam==0){
        return (Falha);
    }
    else{
        q = (*p)->prim;

        for(i=0;i<(*p)->tam;i++){
            if(q->chave==chave1){
                aux=q->ordem;
            }
            if (q->chave==chave2){
                aux1=q->ordem;
            }
            q=q->prox;
        }
        if(aux>aux1){
            cont=aux-aux1;
            cont-=1;
        }
        else{
            cont=aux1-aux;
            cont-=1;
        }
        printf("%d\n",cont);
        return;
    }
}

void Quantidade(ApontaDescritor* p,int chave, int chave2){
    ApontaCelula r,s,aux;
    int cont=0;
    r = (*p)->prim;
    s = (*p)->prim;
    while((r->chave!=chave)&&(r->prox!=NULL)&&(r->chave!=chave2)){
        s=r;
        r= r->prox;
    }
    if(r->chave==chave){
        while((r->chave!=chave2)&&(r->prox!=NULL)){
            cont++;
            s=r;
            r= r->prox;
        }
    }
    else if(r->chave==chave2){
        while((r->chave!=chave)&&(r->prox!=NULL)){
            cont++;
            s=r;
            r= r->prox;
        }
    }
    printf("quantidade %d\n",cont-1);
    return;
}

void Mostrar(ApontaDescritor* p){
    ApontaCelula q;
    int i;
    if((*p)->tam==0){
        printf("Vazio\n");
        return;
    }
    else{
        q = (*p)->prim;
        printf("lista ");
        for(i=0;i<(*p)->tam;i++){
            printf("%d ",q->chave);
            q=q->prox;
        }
        printf("\n");
        return;
    }
}

int main()
{
    int i ,aux,chave,chave1,cont=1;
    char op;
    ApontaDescritor p;
    CriarLista(&p);
    scanf("%d",&aux);
    for(i=0;i<aux;i++){
        scanf("%d",&chave);
        InsFinal(&p,chave);
    }
    do{
        scanf("%c",&op);
        switch (op){
            case 'I':
            {
                scanf("%d%d",&chave,&chave1);
                InsChave(&p,chave,chave1);
                printf("inserido %d\n",chave);
            }
            break;
            case 'R':
            {
                scanf("%d",&chave);
                RemoveChave(&p,chave);
                printf("removido %d\n",chave);
            }
            break;
            case 'C':
            {
                scanf("%d%d",&chave,&chave1);
                Quantidade(&p,chave,chave1);
            }
            break;
            case 'M':
            {
                Mostrar(&p);
            }
            break;
            case 'F':
            {
                aux=0;
                printf("fim");
            }
            break;
        }
    }while(aux!=0);
    return 0;
}
