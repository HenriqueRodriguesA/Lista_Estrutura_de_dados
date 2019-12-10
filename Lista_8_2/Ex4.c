#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,n,c,i,aux1,aux2,m,auxmaior,auxi;
    scanf("%d", &t);
    while(t!=0){
        scanf("%d %d", &n, &c);
        int cor[c],anoes[n];
        for(i=0;i<n;i++){
            scanf("%d",&anoes[i]);
        }
        scanf("%d",&m);
        while(m!=0){
        for(i=0;i<c;i++){
            cor[i]=0;
        }
        scanf("%d %d", &aux1, &aux2);
        for(i=aux1-1;i<aux2;i++){
            cor[anoes[i]-1]++;
        }
        auxmaior=-1;
        for(i=0;i<c;i++){
            if(auxmaior<cor[i]){
                auxmaior=cor[i];
                auxi=i;
            }
        }
        if(auxmaior>(((aux2-aux1)+1)/2)){
            printf("bonita %d\n",auxi+1);
        }
        else{
            printf("feia\n");
        }
        m--;
        }
        t--;

    }
    return 0;
}
