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
    unsigned long int T,A,B,C,aux;
    double k;
    int i;
    do{
        scanf("%d",&T);
    }while((T<1)||(T>10));
    while(T != 0){
        do{
            scanf("%d",&A);
        }while((A<1)||(A>100000));
        do{
            scanf("%d",&B);
        }while((B<1)||(B>100000));
        do{
            scanf("%d",&C);
        }while((C<1)||(C>100000));
        do{
            scanf("%lf",&k);
        }while((k<1)||(k>10000000000));
        printf("%d\n",vezes(A,B,C,k));
        T--;
    }
    return 0;
}
