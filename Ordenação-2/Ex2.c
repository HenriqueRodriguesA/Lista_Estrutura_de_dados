#include <stdio.h>
#include <stdlib.h>


int main()
{
    int n,i,q,aux1,cont,contaux;
    do{
        scanf("%d",&n);
    }while((n < 1)||(n > 1000));
    int moedas[n];
    for(i = 0 ;i < n ;i++){
        scanf("%d",&moedas[i]);
    }
    scanf("%d",&q);
    int dias[q];
    for(i = 0 ;i < q ;i++){
        scanf("%d",&dias[i]);
    }
    aux1=0;
    int aux[n];
    while(q!=aux1){
        cont=0;
        for(i=0;i<n;i++){
            aux[i]=0;
            if(moedas[i]<=dias[aux1]){
                cont++;
                aux[i]=i+1;
            }
        }
        if(cont==0){
            printf("%d\n",cont);
        }
        else{
            printf("%d ",cont);
            contaux=0;
            for(i=0;i<n;i++){
                if(aux[i]!=0){
                    printf("%d ",aux[i]);
                    contaux++;
                }
                if(contaux==cont){
                    break;
                }
            }
            printf("\n");
        }
        aux1++;
    }
    return 0;
}
