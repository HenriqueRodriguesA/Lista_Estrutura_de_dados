#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int vezes(int A ,int B ,int C ,int k){
    int i,aux;
    for(i=0;i<k;i++){
        if(((A*(i*i))+(B*i)+C)>=k){
            aux=i;
            return aux;
        }
    }
}



int main()
{
    int T,A,B,C,k,aux;
    int i;
    do{
        scanf("%d",&T);
    }while((T<1)||(T>10));
    while(T != 0){
        scanf("%d %d %d %d",&A,&B,&C,&k);
        printf("%d\n",vezes(A,B,C,k));
        T--;
    }
    return 0;
}
