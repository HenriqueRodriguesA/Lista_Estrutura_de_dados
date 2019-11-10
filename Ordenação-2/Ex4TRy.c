#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>



int main()
{
    int t,n,k,cont,aux1;
    int i,j;
    do{
        scanf("%d",&t);
    }while((t<1)||(t>10));
    while(t!=0){
        cont=0;
        do{
            scanf("%d",&n);
        }while((n<1)||(n>1000));
        char minumundo[n][n];
        do{
            scanf("%d",&k);
        }while((k<1)||(k>(n*n)));
        getchar();
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                do{
                scanf("%c",&minumundo[i][j]);
                }while((minumundo[i][j]!='P')&&(minumundo[i][j]!='L'));
                getchar();
            }
        }
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(minumundo[i][j]=='P'){
                    for(aux1=1;aux1<=k;aux1++){
                        if((j+aux1)<n){
                            if(minumundo[i][j+aux1]=='L'){
                                    minumundo[i][j+aux1]='p';
                                    cont++;
                                    break;
                            }
                        }
                        else if((j-aux1)>=0){
                                if(minumundo[i][j-aux1]=='L'){
                                minumundo[i][j-aux1]='p';
                                cont++;
                                break;
                            }
                        }
                   }
                }
            }
        }
        printf("%d\n",cont);
        t--;
    }
    return 0;
}
