#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data Data;

// Data.h

Data * criaData (unsigned int dia, unsigned int mes, unsigned int ano);// 1

Data * copiaData (Data * d);// 2

void liberaData (Data * d);// 3

void somaDiasData (Data * d, unsigned int dias);// 4

void subtrairDiasData (Data * d, unsigned int dias);// 5

void alteraData (Data * d, unsigned int dia, unsigned int mes, unsigned int ano);// 6

unsigned int obtemDiaData (Data * d);// 7

unsigned int obtemMesData (Data * d);// 8

unsigned int obtemAnoData (Data * d);// 9

unsigned int bissextoData (Data * d);// 10

int comparaData (Data * d1, Data * d2);// 11

unsigned int numeroDiasDatas (Data * d1, Data * d2);// 12

unsigned int numeroMesesDatas (Data * d1, Data * d2);// 13

unsigned int numeroAnosDatas (Data * d1, Data * d2);// 14

unsigned int obtemDiaSemanaData (Data * d);// 15

char * imprimeData (Data * d,char formato[]);// 16

int menu();

// Data.c

struct data{
    unsigned int dia,mes,ano;
};

Data * criaData (unsigned int dia, unsigned int mes, unsigned int ano){
    Data* D = (Data*)malloc(sizeof(Data*));
    if(D!=NULL){
        D->dia=dia;
        D->mes=mes;
        D->ano=ano;
        return (D);
    }
    else
        printf("Erro falta de memoria\n");
}

Data * copiaData (Data * d){
    Data* D = (Data*)malloc(sizeof(Data*));
    if(D!=NULL){
        D=d;
        return(D);
    }
    else
        printf("Erro falta de memoria\n");
}

void liberaData (Data * d){
    if(d!=NULL){
        free(d);
    }
}

void somaDiasData (Data * d, unsigned int dias){
    int aux,aux1;
    if(d!=NULL){
        aux=dias+d->dia;
        if((d->mes==1)||(d->mes==3)||(d->mes==5)||(d->mes==7)||(d->mes==8)||(d->mes==10)){
            if(aux>31){
                aux=aux-31;
                d->mes+=1;
                d->dia=aux;
                return;
            }
            else
                d->dia=aux;
                return;
        }
        else if ((d->mes==4)||(d->mes==6)||(d->mes==9)||(d->mes==11)){
            if(aux>30){
                aux=aux-30;
                d->mes+=1;
                d->dia=aux;
                return;
            }
            else
                d->dia=aux;
                return;
        }
        else if(d->mes==2){
            aux1= bissextoData(d);
            if((aux>28) && (aux1==0)){
                aux=aux-28;
                d->mes+=1;
                d->dia=aux;
                return;
            }
            else if ((aux>29)&&(aux1==1)){
                aux=aux-29;
                d->mes+=1;
                d->dia=aux;
                return;
            }
            else
                d->dia=aux;
                return;
        }
        else if(d->mes==12)
            if(aux>31){
                aux=aux-31;
                d->mes=1;
                d->ano+=1;
                d->dia=aux;
                return;
            }
            else
                d->dia=aux;
                return;
    }
    else
        printf("Erro data nao existe\n");
}

void subtrairDiasData (Data * d, unsigned int dias){
    int aux,aux1;
    if(d!=NULL){
        aux=dias-d->dia;
        if((d->mes==2)||(d->mes==4)||(d->mes==6)||(d->mes==8)||(d->mes==9)||(d->mes==11)){
            if(aux<1){
                aux=31-aux;
                d->mes-=1;
                d->dia=aux;
                return;
            }
            else
                d->dia=aux;
                return;
        }
        else if ((d->mes==5)||(d->mes==7)||(d->mes==10)||(d->mes==12)){
            if(aux<1){
                aux=aux-30;
                d->mes-=1;
                d->dia=aux;
                return;
            }
            else
                d->dia=aux;
                return;
        }
        else if(d->mes==3){
            aux1= bissextoData(d);
            if((aux<1) && (aux1==0)){
                aux=28-aux;
                d->mes-=1;
                d->dia=aux;
                return;
            }
            else if ((aux<1)&&(aux1==1)){
                aux=29-aux;
                d->mes-=1;
                d->dia=aux;
                return;
            }
            else
                d->dia=aux;
                return;
        }
        else if(d->mes==1)
            if(aux<1){
                aux=31-aux;
                d->mes=12;
                d->ano-=1;
                d->dia=aux;
                return;
            }
            else
                d->dia=aux;
    }
    else
        printf("Erro data nao existe\n");

}

void alteraData (Data * d, unsigned int dia, unsigned int mes, unsigned int ano){
    if(d!=NULL){
        d->dia=dia;
        d->mes=mes;
        d->ano=ano;
    }
    else
        printf("Erro : data nao exite\n");
}

unsigned int obtemDiaData (Data * d){
    if(d!=NULL){
        return(d->dia);
    }
    else
        printf("Erro : data nao exite\n");
}

unsigned int obtemMesData (Data * d){
    if(d!=NULL){
        return(d->mes);
    }
    else
        printf("Erro : data nao exite\n");
}

unsigned int obtemAnoData (Data * d){
    if(d!=NULL){
        return(d->ano);
    }
    else
        printf("Erro : data nao exite\n");
}

unsigned int bissextoData (Data * d){
    if(d->ano%4==0){
        if(d->ano%100!=0){
            return 1;
        }
        else
            return 0;
    }
    else if(d->ano%400==0){
        return 1;
    }
    else
        return 0;
}

unsigned int bissextoData2 (int ano){
    if(ano%4==0){
        if(ano%100!=0){
            return 1;
        }
        else
            return 0;
    }
    else if(ano%400==0){
        return 1;
    }
    else
        return 0;
}

int comparaData (Data * d1, Data * d2){
    if(d1->ano==d2->ano){
        if(d1->mes==d2->mes){
            if(d1->dia==d2->dia)
                return 0;
            else if(d1->dia> d2->dia)
                return -1;
            else
                return 1;
        }
        else if(d1->mes>d2->mes){
            return -1;
        }
        else
            return 1;
    }
    else if(d1->ano>d2->ano)
        return -1;
    else
        return 1;
}

unsigned int numeroDiasDatas (Data * d1, Data * d2){
    if((d1!=NULL)&&(d2!=NULL)){
        return (d1->dia+d2->dia);
    }
    else
        printf("Erro : data nao existe\n");
}

unsigned int numeroMesesDatas (Data * d1, Data * d2){
    if((d1!=NULL)&&(d2!=NULL)){
        return (d1->mes+d2->mes);
    }
    else
        printf("Erro : data nao existe\n");
}

unsigned int numeroAnosDatas (Data * d1, Data * d2){
    if((d1!=NULL)&&(d2!=NULL)){
        return (d1->ano+d2->ano);
    }
    else
        printf("Erro : data nao existe\n");
}

unsigned int obtemDiaSemanaData (Data * d){
    if(d!=NULL){
    int dia,mes,ano;
    dia=d->dia;
    mes=d->mes;
    ano=d->ano;
    switch (mes)
    {
        case 1: break;
        case 2: dia += 31; break;
        case 3: dia += 59; break;
        case 4: dia += 90; break;
        case 5: dia += 120; break;
        case 6: dia += 151; break;
        case 7: dia += 181; break;
        case 8: dia += 212; break;
        case 9: dia += 243; break;
        case 10: dia += 273; break;
        case 11: dia += 304; break;
        case 12: dia += 334; break;
    }
           if ( ((ano%4)==0) && ( ((ano%100)!=0) || ((ano%400)==0) ) && (mes > 2))
               dia += 1;
               dia += -1 + (ano-1)*365 + (ano-1)/4 -(ano-1)/100 +(ano-1)/400 ;

             switch (dia % 7)
             {
                case 0: return 1;
                case 1: return 2;
                case 2: return 3;
                case 3: return 4;
                case 4: return 5;
                case 5: return 6;
                case 6: return 7;
             }

    }
    else
        return ("Erro : data nao existe\n");
}

char * imprimeData (Data * d,char formato[]){
    if(d!=NULL){
        if(strcmp(formato,"ddmmaaaa")==0){
        return printf("%d/%d/%d.\n",d->dia,d->mes,d->ano);
        }
        else if(strcmp(formato,"mmddaaaa")==0){
        return printf("%d/%d/%d.\n",d->mes,d->dia,d->ano);
        }
        else if(strcmp(formato,"aaaammdd")==0){
        return printf("%d/%d/%d.\n",d->ano,d->mes,d->dia);
        }
        else if(strcmp(formato,"aaaa")==0){
        return printf("%d.\n",d->ano);
        }
        else if(strcmp(formato,"mm")==0){
        return printf("%d.\n",d->mes);
        }
        if(strcmp(formato,"dd")==0){
        return printf("%d.\n",d->dia);
        }
        if(strcmp(formato,"ddmm")==0){
        return printf("%d/%d.\n",d->dia,d->mes);
        }
    }
    else
        return printf("Erro : data nao existe\n");
}

int menu(){
    int i;
    printf("Escolha um opsao ou aperte 17 para abrir o menu\n");
    scanf("%d",&i);
    if(i==17){
        printf("\n\nEscolha uma das alternativas a seguir : \n");
        printf("1 - Criar Data \n");
        printf("2 - Copiar Data \n");
        printf("3 - Liberar Data \n");
        printf("4 - Soma dias a Data \n");
        printf("5 - Subtrai dias da Data \n");
        printf("6 - Altera Data \n");
        printf("7 - Obtem dia da Data \n");
        printf("8 - Obtem dia da Mes \n");
        printf("9 - Obtem dia da Ano \n");
        printf("10 - Verificar ano bissexto \n");
        printf("11 - Comparar duas datas \n");
        printf("12 - Numero de dias datas  \n");
        printf("13 - Numero de meses datas \n");
        printf("14 - Numero de anos datas \n");
        printf("15 - Obtem dia da semana \n");
        printf("16 - Imprime Data \n");
        printf("0 - Sair \n");
        scanf("%d",&i);
    }
    return i;
}

int main()
{
    Data* D=NULL;
    Data* D1=NULL;
    int aux,cont1=0;
    char formato[10];
    char* c;
    unsigned int dia,mes,ano;
    int aux1;
    do{
        aux=menu();
        switch(aux){
            case 1:
            {
                if(cont1<2){
                    printf("Digite o ano : \n");
                    scanf("%d",&ano);
                    do{
                    printf("Digite o mes : \n");
                    scanf("%d",&mes);
                    if((mes<1) || (mes>12))
                        printf("Mes invalido\n");
                    }while((mes<1) || (mes>12));
                    if((mes==1)||(mes==3)||(mes==5)||(mes==7)||(mes==8)||(mes==10)||(mes==12)){
                        do{
                            printf("Digite o dia : \n");
                            scanf("%d",&dia);
                            if((dia<1)||(dia>31))
                                printf("Dia invalido\n");
                        }while((dia<1)||(dia>31));
                    }
                    else if((mes==4)||(mes==6)||(mes==9)||(mes==11)){
                        do{
                            printf("Digite o dia : \n");
                            scanf("%d",&dia);
                            if((dia<1)||(dia>30))
                                printf("Dia invalido\n");
                        }while((dia<1)||(dia>30));
                    }
                    else if ((mes==2)&&(bissextoData2(ano)==1)){
                        do{
                            printf("Digite o dia : \n");
                            scanf("%d",&dia);
                            if((dia<1)||(dia>29))
                                printf("Dia invalido\n");
                        }while((dia<1)||(dia>29));
                    }
                    else if ((mes==2)&&(bissextoData2(ano)==0)){
                        do{
                            printf("Digite o dia : \n");
                            scanf("%d",&dia);
                            if((dia<1)||(dia>29))
                                printf("Dia invalido\n");
                        }while((dia<1)||(dia>29));
                    }
                    if(cont1==0){
                        D = criaData(dia,mes,ano);
                        cont1++;
                    }
                    else{
                        D1 = criaData(dia,mes,ano);
                        cont1++;
                    }
                }
                else
                    printf("Nao e possivel criar mais Datas \n");
            }
            break;
            case 2:
                {
                    printf("Digite qual data vai ser copiada na outra 1 ou 2\n");
                    scanf("%d",&aux1);
                    if(aux1==1){
                        D1=copiaData(D);
                    }
                    else{
                        D=copiaData(D1);
                    }
                }
            break;
            case 3:
                {
                    printf("Digite qual data vai ser excluida 1 ou 2\n");
                    scanf("%d",&aux1);
                    if(aux1==1){
                        liberaData(D);
                    }
                    else{
                        liberaData(D1);
                    }
                }
            break;
            case 4:
                {
                    do{
                        printf("Digite um valor entra 1 a 30 para ser somado\n");
                        scanf("%d",&dia);
                        if((dia<1)||(dia>30))
                            printf("valor invalido");
                    }while((dia<1)||(dia>30));
                    printf("Digite qual data vai ser a soma 1 ou 2\n");
                    scanf("%d",&aux1);
                    if(aux1==1){
                        if(D!=NULL){
                            somaDiasData(D,dia);
                        }
                        else
                            printf("Data nao existe\n");
                    }
                    else{
                        if(D1!=NULL){
                            somaDiasData(D1,dia);
                        }
                        else
                            printf("Data nao existe\n");
                    }
                }
            break;
            case 5:
                {
                    do{
                        printf("Digite um valor entra 1 a 30 para ser subtraido\n");
                        scanf("%d",&dia);
                        if((dia<1)||(dia>30))
                            printf("valor invalido");
                    }while((dia<1)||(dia>30));
                    printf("Digite qual data vai ser a subtrasao 1 ou 2\n");
                    scanf("%d",&aux1);
                    if(aux1==1){
                        if(D!=NULL){
                            subtrairDiasData(D,dia);
                        }
                        else
                            printf("Data nao existe\n");
                    }
                    else{
                        if(D1!=NULL){
                            subtrairDiasData(D1,dia);
                        }
                        else
                            printf("Data nao existe\n");
                    }
                }
            break;
            case 6:
                {
                    printf("Digite o ano : \n");
                    scanf("%d",&ano);
                    do{
                    printf("Digite o mes : \n");
                    scanf("%d",&mes);
                    if((mes<1) || (mes>12))
                        printf("Mes invalido\n");
                    }while((mes<1) || (mes>12));
                    if((mes==1)||(mes==3)||(mes==5)||(mes==7)||(mes==8)||(mes==10)||(mes==12)){
                        do{
                            printf("Digite o dia : \n");
                            scanf("%d",&dia);
                            if((dia<1)||(dia>31))
                                printf("Dia invalido\n");
                        }while((dia<1)||(dia>31));
                    }
                    else if((mes==4)||(mes==6)||(mes==9)||(mes==11)){
                        do{
                            printf("Digite o dia : \n");
                            scanf("%d",&dia);
                            if((dia<1)||(dia>30))
                                printf("Dia invalido\n");
                        }while((dia<1)||(dia>30));
                    }
                    else if ((mes==2)&&(bissextoData2(ano)==1)){
                        do{
                            printf("Digite o dia : \n");
                            scanf("%d",&dia);
                            if((dia<1)||(dia>29))
                                printf("Dia invalido\n");
                        }while((dia<1)||(dia>29));
                    }
                    else if ((mes==2)&&(bissextoData2(ano)==0)){
                        do{
                            printf("Digite o dia : \n");
                            scanf("%d",&dia);
                            if((dia<1)||(dia>29))
                                printf("Dia invalido\n");
                        }while((dia<1)||(dia>29));
                    }
                    printf("Digite qual data vai ser a alterasao 1 ou 2\n");
                    scanf("%d",&aux1);
                    if(aux1==1){
                        if(D!=NULL){
                            alteraData(D,dia,mes,ano);
                        }
                        else
                            printf("Data nao existe\n");
                    }
                    else{
                        if(D1!=NULL){
                            alteraData(D1,dia,mes,ano);
                        }
                        else
                            printf("Data nao existe\n");
                    }

                }
            break;
            case 7:
                {
                    printf("Digite qual data o dia var ser obtido 1 ou 2\n");
                    scanf("%d",&aux1);
                    if(aux1==1){
                        if(D!=NULL){
                            dia=obtemDiaData(D);
                            printf("Dia : %d",dia);
                        }
                        else
                            printf("Data nao existe\n");
                    }
                    else{
                        if(D1!=NULL){
                            dia = obtemDiaData(D1);
                            printf("Dia : %d",dia);
                        }
                        else
                            printf("Data nao existe\n");
                    }
                }
            break;
            case 8 :
                {
                    printf("Digite qual data o mes var ser obtido 1 ou 2\n");
                    scanf("%d",&aux1);
                    if(aux1==1){
                        if(D!=NULL){
                            dia=obtemMesData(D);
                            printf("Mes : %d\n",dia);
                        }
                        else
                            printf("Data nao existe\n");
                    }
                    else{
                        if(D1!=NULL){
                            dia = obtemMesData(D1);
                            printf("Mes : %d\n",dia);
                        }
                        else
                            printf("Data nao existe\n");
                    }
                }
            break;
            case 9 :
                {
                    printf("Digite qual data o ano var ser obtido 1 ou 2\n");
                    scanf("%d",&aux1);
                    if(aux1==1){
                        if(D!=NULL){
                            dia=obtemAnoData(D);
                            printf("Ano : %d\n",dia);
                        }
                        else
                            printf("Data nao existe\n");
                    }
                    else{
                        if(D1!=NULL){
                            dia = obtemAnoData(D1);
                            printf("Ano : %d\n",dia);
                        }
                        else
                            printf("Data nao existe\n");
                    }
                }
            break;
            case 10:
                {
                    printf("Digite qual data vai se verificar o ano bissexto 1 ou 2\n");
                    scanf("%d",&aux1);
                    if(aux1==1){
                        if(D!=NULL){
                            dia=bissextoData(D);
                            if(dia==1)
                                printf("E ano bissexto\n");
                            else
                                printf("Nao e ano bissexto\n");
                        }
                        else
                            printf("Data nao existe\n");
                    }
                    else{
                        if(D1!=NULL){
                            dia = bissextoData(D1);
                            if(dia==1)
                                printf("E ano bissexto\n");
                            else
                                printf("Nao e ano bissexto\n");
                        }
                        else
                            printf("Data nao existe\n");
                    }
                }
            break;
            case 11:
                {
                    if((D!=NULL)&&(D1!=NULL)){
                        dia = comparaData(D,D1);
                        if(dia==1)
                            printf("Data 2 maior do que Data 1\n");
                        else if (dia==0)
                            printf("Data 1 e 2 sao iguais \n");
                        else if(dia==-1)
                            printf("Data 1 maior do que Data 2 \n");
                    }
                    else
                        printf("Data nao existe\n");
                }
            break;
            case 12:
                {
                    if((D!=NULL)&&(D1!=NULL)){
                        dia = numeroDiasDatas(D,D1);
                        printf("Numero de dias %d\n",dia);
                    }
                    else
                        printf("Data nao existe\n");
                }
            break;
            case 13:
                {
                    if((D!=NULL)&&(D1!=NULL)){
                        dia = numeroMesesDatas(D,D1);
                        printf("Numero de meses %d\n",dia);
                    }
                    else
                        printf("Data nao existe\n");
                }
            break;
            case 14:
                {
                    if((D!=NULL)&&(D1!=NULL)){
                        dia = numeroAnosDatas(D,D1);
                        printf("Numero de Anos %d\n",dia);
                    }
                    else
                        printf("Data nao existe\n");
                }
            break;
            case 15:
                {
                    printf("Digite de  qual data quer o dia da semana 1 ou 2\n");
                    scanf("%d",&aux1);
                    if(aux1==1){
                        if(D!=NULL){
                            dia=obtemDiaSemanaData(D);
                            switch(dia){
                                case 1:
                                        printf("Domingo\n");
                                break;
                                case 2:
                                        printf("Segunda\n");
                                break;
                                case 3:
                                        printf("Terca\n");
                                break;
                                case 4:
                                        printf("Quarta\n");
                                break;
                                case 5:
                                        printf("Quinta\n");
                                break;
                                case 6:
                                        printf("Sexta\n");
                                break;
                                case 7:
                                        printf("Sabado\n");
                                break;
                            }
                        }
                        else
                            printf("Data nao existe\n");
                    }
                    else{
                        if(D1!=NULL){
                            dia=obtemDiaSemanaData(D1);
                            switch(dia){
                                case 1:
                                        printf("Domingo\n");
                                break;
                                case 2:
                                        printf("Segunda\n");
                                break;
                                case 3:
                                        printf("Terca\n");
                                break;
                                case 4:
                                        printf("Quarta\n");
                                break;
                                case 5:
                                        printf("Quinta\n");
                                break;
                                case 6:
                                        printf("Sexta\n");
                                break;
                                case 7:
                                        printf("Sabado\n");
                                break;
                            }
                        }
                        else
                            printf("Data nao existe\n");
                    }
                }
            break;
            case 16:
                {
                    printf("Digite qual data vai ser Imprimida 1 ou 2\n");
                    scanf("%d",&aux1);
                    printf("Digite o formato 'aaaa','mm','dd','ddmmaaaa','aaaammdd','mmddaaaa','ddmm'\n");
                    scanf("%s",formato);
                    if(aux1==1){
                        if(D!=NULL){
                            c=imprimeData(D,formato);
                        }
                        else
                            printf("Data nao existe\n");
                    }
                    else{
                        if(D1!=NULL){
                            c=imprimeData(D,formato);
                        }
                        else
                            printf("Data nao existe\n");
                    }
                }
            break;
        }
    }while(aux!=0);
    return 0;
}
