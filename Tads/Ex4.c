#include <stdio.h>
#include <stdlib.h>
typedef struct world World;

// ponto.h

World * newWord (unsigned int n, unsigned int m);

World * cloneWorld (World * w);

void freeWorld (World * w);

unsigned int randomWorld (World * w, unsigned int n);

unsigned int addBacterium (World * w, unsigned int n, unsigned int f);

unsigned int addBacteriumXY (World * w, unsigned int n, unsigned int x, unsigned int y, unsigned int f);

unsigned int killBacterium (World * w, unsigned int n);

 unsigned int killBacteriumXY (World * w, unsigned int x, unsigned int y);

 World * jointWorlds (World * w1, World *w2);

 World * warWorlds (World * w1, World *w2);

 World * probabilisticWarWorlds (World * w1, World *w2, float p);

 unsigned int sizeWorld (World * w);

 unsigned int forceWorld (World * w);

 unsigned int showWorld (World * w);

// ponto.c

struct world{
    int Cultura[5][5];
    int Forca[5][5];
    int total;
    int linha;
    int coluna;
};

World* newWord (unsigned int n, unsigned int m){
    World* W = (World*) malloc(sizeof(World*));
    if(W!=NULL){
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                W->Cultura[i][j]= 0;
                W->Forca[i][j]= 0;
            }
        }
        W->total=0;
        W->linha=n;
        W->coluna=m;
        return (W);
    }
    else{
        printf("Erro nao tem memoria");
    }
}

World* cloneWorld (World * W){
    World* W1 = (World*) malloc(sizeof(World*));
    if(W1!=NULL){
        for(int i = 0 ; i < W->linha ; i++){
            for(int j = 0 ; j < W->coluna ; j++){
                W1->Cultura[i][j] = W->Cultura[i][j];
                W1->Forca[i][j] = W->Forca[i][j];
            }
        }
        W1->total=W->total;
        W1->linha=W->linha;
        W1->coluna=W->coluna;
        return (W1);
    }
    else{
        printf("Erro nao tem memoria\n");
    }
}

void freeWorld (World * w){
    if(w!=NULL){
        free(w->Cultura);
        free(w->Forca);
        free(w);
    }
    else{
        printf("Erro\n");
    }

}

int main()
{
    int i,j;
    World* p;
    World* p1;
    p = newWord(5,5);
    //p1 = cloneWorld(p);
    for(i= 0;i<p->linha;i++){
        for(j=0;j < p->coluna;j++){
            printf("P Numero linha %d coluna %d: [%d][%d]\n",i,j,p->Cultura[i][j],p->Forca[i][j]);
        }
    }
    printf("\nLinha %d || Coluna %d\n",p->linha,p->coluna);
    printf("Linha %d || Coluna %d\n\n",p1->linha,p1->coluna);
    for(i= 0;i<p1->linha;i++){
        for(j=0;j<p1->coluna;j++){
            printf("P1 Numero linha %d coluna %d: [%d][%d]\n",i+1,j+1,p1->Cultura[i][j],p1->Forca[i][j]);
        }
    }
    freeWorld(p);
    freeWorld(p1);
    return 0;
}
