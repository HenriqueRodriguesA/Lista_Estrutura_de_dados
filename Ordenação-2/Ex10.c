#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{
    int n,i,j,aux,cont=0;
    srand(time(NULL));
    do{
        n=rand()%360;/*EU coloquei 360 ao invez de 1000 porque meu computador so chega ate matriz 360x360
                       mais do que isso ele não roda, assim nao posso garantir que ele funcione até 1000*/
    }while((n<1)||(n>1000));
    printf("%d\n",n);
    long int matrizA[n][n],matrizB[n][n];
    double matrizAB[n][n];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            matrizA[i][j] = rand() % 2000 - 1000;
            matrizB[i][j] = rand() % 2000 - 1000;
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(j==0){
                printf("|%d ,",matrizA[i][j]);
            }
            else if(j==n-1){
                printf("%d|",matrizA[i][j]);
            }
            else{
                printf("%d ,",matrizA[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(j==0){
                printf("|%d ,",matrizB[i][j]);
            }
            else if(j==n-1){
                printf("%d|",matrizB[i][j]);
            }
            else{
                printf("%d ,",matrizB[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            matrizAB[j][i]=0;
            for(aux=0;aux<n;aux++){
               matrizAB[j][i]+=matrizA[j][aux]*matrizB[aux][i];
               cont++;
            }
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(j==0){
                printf("|%0.lf ,",matrizAB[i][j]);
            }
            else if(j==n-1){
                printf("%0.lf|",matrizAB[i][j]);
            }
            else{
                printf("%0.lf ,",matrizAB[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n%d",cont);
    return 0;
}
