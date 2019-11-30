#include <stdio.h>
#include <stdlib.h>
typedef struct conjunto Conjunto;

// Conjunto.h

Conjunto* Cria_Conjunto();//1

int conjuntoVazio(Conjunto* C);//2

int insereElementoConjunto(int x , Conjunto* C);//3

int excluirElementoConjunto(int x , Conjunto* C);//4

int tamanhoConjunto(Conjunto* C);//5

int maior(int x,Conjunto* C);//6

int menor(int x,Conjunto* C);//7

int pertenceConjunto(int x , Conjunto* C);//8

int conjuntosIdenticos(Conjunto* C1, Conjunto* C2);//9

int subconjunto(Conjunto* C1, Conjunto* C2);//10

Conjunto* complemento(Conjunto* C1, Conjunto* C2);//11

Conjunto* uniao(Conjunto* C1, Conjunto* C2);//12

Conjunto* interseccao(Conjunto* C1,Conjunto* C2);//13

Conjunto* diferenca(Conjunto* C1, Conjunto* C2);//14

void conjuntoPartes(Conjunto* C);//15

void mostraConjunto(Conjunto C,int x);//16

int copiarConjunto(Conjunto* C1,Conjunto* C2);//17

void destroiConjunto(Conjunto* C);//18

void ordenaConjunto(Conjunto* C);

void ordenaConjuntoTotal(Conjunto* C);

// Conjunto.c

struct conjunto{
    int conj[100];
    int total;
};

Conjunto* Cria_Conjunto(){//1
    int i;
    Conjunto* C =(Conjunto*)malloc(sizeof(Conjunto));
    if(C != NULL){
        for(i=0;i<100;i++)
        C -> conj[i]=-1;
    }
    C ->total = 0;
    return (C);
}

int conjuntoVazio(Conjunto* C){//2
    if(C->conj[0] == -1){
        return(1);
    }
    else{
        return(0);
    }
}

int insereElementoConjunto(int x , Conjunto* C){//3
    int i;
    if(C->total!=50){
        for(i =0 ; i < C->total ; i++){
            if(C->conj[i] == x){
               return(0);
            }
        }
        C->conj[C->total]=x;
        C->total+=1;
        if(C->total!= 1){
            ordenaConjuntoTotal(C);
        }
        return(1);
    }
    else{
        printf("Falha especial atingiu o limite do conjunto\n");
        return (3);
    }
}

int excluirElementoConjunto(int x , Conjunto* C){//4
    int i;
    for(i = 0 ; i < C->total; i++){
        if(C->conj[i] == x){
            C ->conj[i]=-1;
            C->total--;
            ordenaConjunto(C);
            return(1);
        }
    }
    return (0);
}

void ordenaConjunto(Conjunto* C){
int i,j,aux,aux1;

for(i=0;i<C->total;i++){
    if(C->conj[i]==-1){
        aux=100;
    }
    else{
        aux = C->conj[i];
    }
    aux1=i;
    for(j=i+1;j<99;j++){
        if((aux > C->conj[j]) && (C->conj[j]!= -1)){
            aux1=j;
            aux=C->conj[j];
        }
    }
    if(aux1!=i){
        if(C->conj[i] == -1){
            C->conj[i]=C->conj[aux1];
            C->conj[aux1]= -1;
        }
        else{
            aux = C->conj[i];
            C->conj[i]=C->conj[aux1];
            C->conj[aux1]=aux;
        }
    }
}
}

void ordenaConjuntoTotal(Conjunto* C){
    int i,j,aux,aux1;

    for(i=0;i<C->total;i++){
        aux = C->conj[i];
        aux1=i;
        for(j=i+1;j<C->total;j++){
            if((aux > C->conj[j])){
                aux1=j;
                aux = C->conj[j];
            }
        }
        if(aux1!=i){
            aux = C->conj[i];
            C->conj[i]=C->conj[aux1];
            C->conj[aux1]=aux;
        }
    }
}

int tamanhoConjunto(Conjunto* C){//5
    if(C->total!=0){
        return(C->total);
    }
    else{
        return(0);
    }
}

int maior(int x,Conjunto* C){//6
    int aux=0,i;

    for(i=0;i<C->total;i++){
        if(x < C->conj[i]){
            aux++;
        }
    }
    return(aux);
}

int menor(int x,Conjunto* C){//7
    int aux=0,i;

    for(i=0;i<C->total;i++){
        if(x > C->conj[i]){
            aux++;
        }
    }
    return(aux);
}

int pertenceConjunto(int x , Conjunto* C){//8
    for(int i =0 ; i < 100 ; i++){
        if(C->conj[i] == x){
            return(1);
        }
    }
    return(0);
}

int conjuntosIdenticos(Conjunto* C1, Conjunto* C2){//9
    if(C1->total != C2->total){
        return(0);
    }
    for(int i =0 ; i < C1->total ; i++){
        if(C1->conj[i] != C2->conj[i]){
            return(0);
        }
    }
    return(1);
}

int subconjunto(Conjunto* C1, Conjunto* C2){//10
    int aux=0,i,j;
    if(C1->total>C2->total){
        return 0;
    }
    for(i = 0;i<C2->total;i++){
        for(j = 0 ; j<C1->total;j++){
            if(C2->conj[i]==C1->conj[j]){
                aux++;
                break;
            }
        }
        if(aux==C1->total){
            return 1;
        }
    }
    return 0;
}

Conjunto* complemento(Conjunto* C1, Conjunto* C2){//11
    int aux,i,j,cont=0;
    Conjunto* C3 = NULL;
    C3 = Cria_Conjunto();
    if(C3==0){
        return;
    }
    aux = subconjunto(C1,C2);
    if(aux==0){
        return;
    }
    else{
        for(int i = 0;i<C2->total;i++){
            aux=0;
            for(int j = 0 ; j<C1->total;j++){
                if(C2->conj[i]==C1->conj[j]){
                    aux=1;
                    break;
                }
            }
            if(aux==0){
                C3->conj[cont]=C2->conj[i];
                C3->total++;
                cont++;
            }
        }
        ordenaConjuntoTotal(C3);
        return(C3);
    }
}

Conjunto* uniao(Conjunto* C1,Conjunto* C2){//12
    int aux,i,j,cont=0;
    Conjunto* uni=NULL;
    uni = Cria_Conjunto();
    if(uni==0){
        return;
    }
    for(i=0;i<C1->total;i++){
        aux=0;
        for(j=0;j<C2->total;j++){
            if(C1->conj[i]==C2->conj[j]){
                aux=1;
                break;
            }
        }
        if(aux==0){
            uni->conj[cont]=C1->conj[i];
            uni->total++;
            cont++;
        }
    }
    for(i=0;i<C2->total;i++){
        aux=0;
        for(j=0;j<C1->total;j++){
            if(C2->conj[i]==C1->conj[j]){
                aux=1;
                break;
            }
        }
        if(aux==0){
            uni->conj[cont]=C2->conj[i];
            uni->total++;
            cont++;
        }
    }
    ordenaConjuntoTotal(uni);
    return(uni);
}

Conjunto* interseccao(Conjunto* C1,Conjunto* C2){//13
    int aux,i,j,cont=0;
    aux = conjuntosIdenticos(C1,C2);
    if(aux==1){
        return(C1);
    }
    Conjunto* inter=NULL;
    inter = Cria_Conjunto();
    if(inter==0){
        return;
    }
    for(i=0;i<C1->total;i++){
        aux=0;
        for(j=0;j<C2->total;j++){
            if(C1->conj[i]==C2->conj[j]){
                aux=1;
                break;
            }
        }
        if(aux==1){
            inter->conj[cont]=C1->conj[i];
            inter->total++;
            cont++;
        }
    }
    ordenaConjuntoTotal(inter);
    return(inter);
}

Conjunto* diferenca(Conjunto* C1, Conjunto* C2){//14
    int i,j,aux,cont=0;
    Conjunto* dif=NULL;
    dif = Cria_Conjunto();
    if(dif==0){
        return;
    }
    for(int i = 0;i<C1->total;i++){
        aux=0;
        for(int j = 0 ; j<C2->total;j++){
            if((C1->conj[i]==C2->conj[j])&& (C1->conj[i]!=-1)){
                aux=1;
                break;
            }
        }
        if(aux==0){
            dif->conj[cont]=C1->conj[i];
            dif->total++;
            cont++;
        }
    }
    ordenaConjuntoTotal(dif);
    return(dif);
}

void conjuntoPartes(Conjunto* C){//15
    int i,j,cont;
    printf("Conjunto das parstes de C {{},");
    for(i=0;i<C->total;i++){
        printf(" {%d},",C->conj[i]);
    }
    for(i=0;i<C->total;i++){
        for(j=i+1;j<C->total;j++){
            printf(" {%d,%d},",C->conj[i],C->conj[j]);
        }
    }
    if(C->total==3){
    printf(" {%d,%d,%d}}",C->conj[0],C->conj[1],C->conj[2]);
    }
    else{
        printf("}\n");
    }
}

void mostraConjunto(Conjunto C,int x){//16
    int count=0;
    if(x==1){
        printf("Conjunto C {");
            for(int i = 0; i<C.total; i++){
                if(count==0){
                    printf("%d",C.conj[i]);
                    count++;
                }
                else{
                    printf(", %d",C.conj[i]);
                }
            }
        printf("}.\n");
    }
    else{
        printf("Conjunto C {");
            for(int i = C.total-1; i>=0; i--){
                if(count==0){
                    printf("%d",C.conj[i]);
                    count++;
                }
                else{
                    printf(", %d",C.conj[i]);
                }
            }
        printf("}.\n");
    }
}

int copiarConjunto(Conjunto* C1,Conjunto* C2){//17
    if((C1!=NULL)&&(C2!=NULL)){
        int i;
        destroiConjunto(C2);
        C2=NULL;
        C2=Cria_Conjunto();
        if(C2==NULL){
            return(0);
        }
        for(i=0;i<C1->total;i++){
            C2->conj[i]=C1->conj[i];
        }
        C2->total=C1->total;
        return(1);
    }
    else{
        return(0);
    }
}


void destroiConjunto(Conjunto* C){//18
    free(C);
}

int menu(){
    int i;
    printf("Escolha uma opcao ou aperte 19 para ver o menu\n");
    scanf("%d",&i);
    if(i==19){
        printf("\n\nEscolha uma das alternativas a seguir : \n");
        printf("1 - Criar Conjunto \n");
        printf("2 - Verifica se o Conjunto esta vazio \n");
        printf("3 - Inserir elemento no conjunto \n");
        printf("4 - Excluir elemento do conjunto \n");
        printf("5 - Calcula Cardinalidade \n");
        printf("6 - Determine a quantidade de elementos do conjunto maior do que x \n");
        printf("7 - Determine a quantidade de elementos do conjunto menor do que x \n");
        printf("8 - Encontrar elemento no conjunto \n");
        printf("9 - Verificar se dois conjuntos sao iguas \n");
        printf("10 - Verificar se Conjunto 1 esta contido em 2 \n");
        printf("11 - O complemento do Conjunto 1 em Conjunto 2 \n");
        printf("12 - A uniao do Conjunto 1 com Conjunto 2 \n");
        printf("13 - A interseccao do Conjunto 1 e Conjunto 2 \n");
        printf("14 - Diferensa do Conjunto 1 e Conjunto 2 \n");
        printf("15 - Conjunto das Partes \n");
        printf("16 - Mostrar o Conjunto \n");
        printf("17 - Copie o conteudo de C1 para C2 \n");
        printf("18 - Destruir o conjunto \n");
        printf("0 - Sair \n");
        scanf("%d",&i);
    }
    return i;
}
int main()
{
    Conjunto* p=NULL;
    Conjunto* p2=NULL;
    int i,aux,cont1=0,aux1,aux2,aux3;
    do{
        aux=menu();
        switch(aux){
            case 1:
                {
                    if(cont1<2){
                        if(cont1==0){
                            p = Cria_Conjunto();
                            cont1++;
                        }
                        else{
                            p2 = Cria_Conjunto();
                            cont1++;
                        }
                    }
                    else
                        printf("Nao e possivel criar mais conjuntos \n");
                }
                break;
            case 2:
                {
                    printf("Escolha em qual conjunto 1 ou 2 vai fazer a verificacao\n");
                    scanf("%d",&aux2);
                    if(aux2==1){
                        if(p!=NULL){
                            aux3=conjuntoVazio(p);
                            if(aux3==1){
                                printf("O Conjunto 1 esta vazio \n");
                            }
                            else{
                                printf("O Conjunto 1 nao esta vazio\n");
                            }
                        }
                        else
                            printf("Conjunto nao existe\n");
                    }
                    else if(aux2==2){
                        if(p2!=NULL){
                            aux3=conjuntoVazio(p2);
                            if(aux3==1){
                                printf("O Conjunto 2 esta vazio \n");
                            }
                            else{
                                printf("O Conjunto 2 nao esta vazio\n");
                            }
                        }
                        else
                            printf("Conjunto nao existez\n");
                    }
                }
                break;
            case 3:
                {
                    printf("Escolha o elemento a ser adicionado\n");
                    scanf("%d",&aux1);
                    printf("Escolha em qual conjunto 1 ou 2\n");
                    scanf("%d",&aux2);
                    if(aux2==1){
                        if(p!=NULL){
                            aux3=insereElementoConjunto(aux1,p);
                            if(aux3==1){
                                printf("Sucesso\n");
                            }
                            else if (aux3==0){
                                printf("O elemento %d ja existe no conjunto 1 \n",aux1);
                            }
                        }
                        else
                            printf("Conjunto nao existe\n");
                    }
                    else if(aux2==2){
                        if(p2!=NULL){
                            aux3=insereElementoConjunto(aux1,p2);
                            if(aux3==1){
                                printf("Sucesso\n");
                            }
                            else if (aux3==0){
                                printf("O elemento %d ja existe no conjunto 2 \n",aux1);
                            }
                        }
                        else
                            printf("Conjunto nao existe\n");
                    }
                }
                break;
            case 4:
                {
                    printf("Escolha o elemento a ser excluido\n");
                    scanf("%d",&aux1);
                    printf("Escolha em qual conjunto 1 ou 2\n");
                    scanf("%d",&aux2);
                    if(aux2==1){
                        if(p!=NULL){
                            aux3=excluirElementoConjunto(aux1,p);
                            if(aux3==1){
                                printf("Sucesso\n");
                            }
                            else{
                                printf("O elemento %d nao existe no conjunto 1 \n",aux1);
                            }
                        }
                        else
                            printf("Conjunto nao existe\n");
                    }
                    else if(aux2==2){
                        if(p2!=NULL){
                            aux3=excluirElementoConjunto(aux1,p2);
                            if(aux3==1){
                                printf("Sucesso\n");
                            }
                            else{
                                printf("O elemento %d nao existe no conjunto 2 \n",aux1);
                            }
                        }
                        else
                            printf("Conjunto nao existe\n");
                    }
                }
                break;
            case 5:
                {
                    printf("Escolha em qual conjunto 1 ou 2 voce quer a cardinalidade\n");
                    scanf("%d",&aux2);
                    if(aux2==1){
                        if(p!=NULL){
                            aux3=tamanhoConjunto(p);
                            printf("O conjunto 1 tem cardinalidade %d\n",aux3);
                        }
                        else{
                            printf("Conjunto nao existe\n");
                        }
                    }
                    else{
                        if(p2!=NULL){
                            aux3=tamanhoConjunto(p2);
                            printf("O conjunto 2 tem cardinalidade %d\n",aux3);
                        }
                        else{
                            printf("Conjunto nao existe\n");
                        }
                    }
                }
                break;
            case 6:
                {
                    printf("Escolha o elemento a ser comparado\n");
                    scanf("%d",&aux1);
                    printf("Escolha em qual conjunto 1 ou 2\n");
                    scanf("%d",&aux2);
                    if(aux2==1){
                        if(p!=NULL){
                            aux3=maior(aux1,p);
                            printf("No conjunto 1 existe %d elementos maior do que %d\n",aux3,aux1);
                        }
                        else{
                            printf("Conjunto nao existe\n");
                        }
                    }
                    else{
                        if(p2!=NULL){
                            aux3=maior(aux1,p2);
                            printf("No conjunto 2 existe %d elementos maior do que %d\n",aux3,aux1);
                        }
                        else{
                            printf("Conjunto nao existe\n");
                        }
                    }
                }
                break;
            case 7:
                {
                    printf("Escolha o elemento a ser comparado\n");
                    scanf("%d",&aux1);
                    printf("Escolha em qual conjunto 1 ou 2\n");
                    scanf("%d",&aux2);
                    if(aux2==1){
                        if(p!=NULL){
                            aux3=menor(aux1,p);
                            printf("No conjunto 1 existe %d elementos menor do que %d\n",aux3,aux1);
                        }
                        else{
                            printf("Conjunto nao existe\n");
                        }
                    }
                    else{
                        if(p2!=NULL){
                            aux3=menor(aux1,p2);
                            printf("No conjunto 2 existe %d elementos menor do que %d\n",aux3,aux1);
                        }
                        else{
                            printf("Conjunto nao existe\n");
                        }
                    }
                }
                break;
            case 8:
                {
                    printf("Escolha o elemento a ser encontrado\n");
                    scanf("%d",&aux1);
                    printf("Escolha em qual conjunto 1 ou 2\n");
                    scanf("%d",&aux2);
                    if(aux2==1){
                        if(p!=NULL){
                            aux3=pertenceConjunto(aux1,p);
                            if(aux3==1){
                                printf("%d pertence ao conjunto 1 \n",aux1);
                            }
                            else{
                                printf("%d nao pertence ao conjunto 1 \n",aux1);
                            }
                        }
                        else
                            printf("Conjunto nao existe\n");
                    }
                    else if(aux2==2){
                        if(p2!=NULL){
                            aux3=pertenceConjunto(aux1,p2);
                            if(aux3==1){
                                printf("%d pertence ao conjunto 2 \n",aux1);
                            }
                            else{
                                printf("%d nao pertence ao conjunto 2 \n",aux1);
                            }
                        }
                        else
                            printf("Conjunto nao existe\n");
                    }
                }
                break;
            case 9:
                {
                    if((p!=NULL)&&(p2!=NULL)){
                        aux3=conjuntosIdenticos(p,p2);
                        if(aux3==1){
                            printf("Conjunto 1 e 2 sao identicos \n");
                        }
                        else{
                            printf("Conjunto 1 e 2 nao sao identicos \n");
                        }
                    }
                    else
                        printf("Conjunto nao existe\n");
                }
                break;
            case 10:
                {
                    if((p!=NULL)&&(p2!=NULL)){
                        printf("Escolha em qual conjunto 1 ou 2 vai fazer a verificacao\n");
                        scanf("%d",&aux2);
                        if(aux2==1){
                            aux1=subconjunto(p,p2);
                            if(aux1==0){
                                printf("Conjunto 1 nao esta contido no Conjunto 2\n");
                            }
                            else
                                printf("Conjunto 1  esta contido no Conjunto 2\n");
                            }
                        else{
                            aux1=subconjunto(p2,p);
                            if(aux1==0){
                                printf("Conjunto 2 nao esta contido no Conjunto 1\n");
                            }
                            else
                                printf("Conjunto 2  esta contido no Conjunto 1\n");
                            }
                        }
                    else
                        printf("Conjunto nao existe\n");
                }
                break;
            case 11:
                {
                    if((p!=NULL)&&(p2!=NULL)){
                        printf("Escolha em qual conjunto 1 ou 2 vai fazer a verificacao\n");
                        scanf("%d",&aux2);
                        Conjunto* p3 =NULL;
                        if(aux2==1){
                            p3=complemento(p,p2);
                            if(p3!=NULL){
                                mostraConjunto(*p3,1);
                            }
                            else{
                                printf("O conjunto 1 nao esta contido no 2 para existir complemento \n");
                            }
                            destroiConjunto(p3);
                        }
                        else{
                            p3=complemento(p2,p);
                            if(p3!=NULL){
                                mostraConjunto(*p3,1);
                            }
                            else{
                                printf("O conjunto 2 nao esta contido no 1 para existir complemento \n");
                            }
                            destroiConjunto(p3);
                        }
                    }
                    else
                        printf("Conjunto nao existe\n");
                }
                break;
            case 12:
                {
                    if((p!=NULL)&&(p2!=NULL)){
                            Conjunto* p3 =NULL;
                            p3=uniao(p,p2);
                            if(p3!=NULL){
                                mostraConjunto(*p3,1);
                            }
                            else{
                                printf("Falha \n");
                            }
                            destroiConjunto(p3);
                    }
                    else
                        printf("Conjunto nao existe\n");
                }
                break;
            case 13:
                {
                    if((p!=NULL)&&(p2!=NULL)){
                            Conjunto* p3 = NULL;
                            p3=interseccao(p,p2);
                            if(p3!=NULL){
                                mostraConjunto(*p3,1);
                            }
                            else{
                                printf("Falha \n");
                            }
                            destroiConjunto(p3);
                    }
                    else
                        printf("Conjunto nao existe\n");
                }
                break;
            case 14:
                {
                    if((p!=NULL)&&(p2!=NULL)){
                        printf("Escolha em qual conjunto 1 ou 2 vai fazer a verificacao\n");
                        scanf("%d",&aux2);
                        Conjunto* p3 =NULL;
                        if(aux2==1){
                            p3=diferenca(p,p2);
                            if(p3!=NULL){
                                mostraConjunto(*p3,1);
                            }
                            else{
                                printf("Falha \n");
                            }
                        }
                        else{
                            p3=diferenca(p2,p);
                            if(p3!=NULL){
                                mostraConjunto(*p3,1);
                            }
                            else{
                                printf("Falha \n");
                            }
                        }
                    }
                    else
                        printf("Conjunto nao existe\n");
                }
                break;
            case 15:
                {
                    printf("Escolha em qual conjunto 1 ou 2 vai fazer a verificacao\n");
                    scanf("%d",&aux2);
                    if(aux2==1){
                        if(p!=NULL){
                            conjuntoPartes(p);
                        }
                        else
                            printf("Conjunto nao existe\n");
                    }
                    else{
                        if(p2!=NULL){
                            conjuntoPartes(p2);
                        }
                        else
                            printf("Conjunto nao existe\n");
                    }
                }
                break;
            case 16:
                {
                    printf("Escolha em qual conjunto 1 ou 2 vai fazer a verificacao\n");
                    scanf("%d",&aux2);
                    printf("Escolha na ordem crecente 1 ou decrecente 2\n");
                    scanf("%d",&aux1);
                    if(aux2==1){
                        if(p!=NULL){
                            mostraConjunto(*p,aux1);
                        }
                        else
                            printf("Conjunto nao existe\n");
                    }
                    else{
                        if(p2!=NULL){
                            mostraConjunto(*p2,aux1);
                        }
                        else
                            printf("Conjunto nao existe\n");
                    }
                }
                break;
            case 17:
                {
                    printf("Escolha em qual conjunto 1 ou 2 o conteudo vai ser copiado \n");
                    scanf("%d",&aux2);
                    if(aux2==1){
                        if(p!=NULL){
                            aux3=copiarConjunto(p,p2);
                            if(aux3==1){
                                printf("Sucesso\n");
                            }
                            else{
                                printf("Falha\n");
                            }
                        }
                        else
                            printf("Conjunto nao existe\n");
                    }
                    else{
                        if(p2!=NULL){
                            aux3=copiarConjunto(p2,p);
                            if(aux3==1){
                                printf("Sucesso\n");
                            }
                            else{
                                printf("Falha\n");
                            }
                        }
                        else
                            printf("Conjunto nao existe\n");
                    }
                }
                break;
            case 18:
                {
                    printf("Escolha em qual conjunto 1 ou 2 vai fazer a verificacao\n");
                    scanf("%d",&aux2);
                    if(aux2==1){
                        if(p!=NULL){
                            destroiConjunto(p);
                            p=NULL;
                            cont1=0;
                        }
                        else
                            printf("Conjunto nao existe\n");
                    }
                    else{
                        if(p2!=NULL){
                            destroiConjunto(p2);
                            p2=NULL;
                            cont1=1;
                        }
                        else
                            printf("Conjunto nao existe\n");
                    }
                }
                break;
        }
    }while(aux!=0);
    return 0;
}
