#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

long int determinate(int mat[3][3] ,int n){
    int i,j,w,e;
    long int det;
    if(n==1){
        return mat[0][0];
    }
    else if(n==2){
        det = ((mat[0][0]*mat[0][3])-(mat[0][1]*mat[0][2]));
        return det;
    }
    else if(n==3){
        det = ((mat[0][0]*mat[1][1]*mat[2][2])+(mat[0][1]*mat[1][2]*mat[2][0])+(mat[0][2]*mat[1][0]*mat[2][1])
               -(mat[2][0]*mat[1][1]*mat[0][2])-(mat[2][1]*mat[1][2]*mat[0][0])-(mat[2][2]*mat[1][0]*mat[0][1]));
        return det;
    }
}

long int det4(int mat[4][4],int n,int t,long int det){
    int i,j,cont=0;
    int aux1[3][3];
    while(t!=n){
        for(i=0;i<4;i++){
            for(j=0;j<4;j++){
                if(t==0){
                    aux1[i][j]=mat[i+1][j+1];
                }
                else if(t==1){
                    if(j<1){
                        aux1[i][j]=mat[i+1][j];
                    }
                    else{
                        aux1[i][j]=mat[i+1][j+1];
                    }
                }
                else if(t==2){
                    if(j<2){
                        aux1[i][j]=mat[i+1][j];
                    }
                    else{
                        aux1[i][j]=mat[i+1][j+1];
                }
                }
                else if(t==3){
                    aux1[i][j]=mat[i+1][j];
                }

            }
        }
        if((t%2)==0){
            det+=determinate(aux1,3);
        }
        else{
            det-=determinate(aux1,3);
        }
            t++;
    }
    return det;
}

int main()
{
    int i,j,n;
    long int det;
    srand(time(NULL));
    do{
        n=rand()%5;
    }while(n==0);
    int mat[n][n];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            mat[i][j]=rand()%10;
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
    if(n<=3){
        det = determinate(mat,n);
        printf("Determinante : %d",det);
    }
    else{
        det= det4(mat,n,0,0);
        printf("Determinante : %d",det);
    }

    return 0;
}
