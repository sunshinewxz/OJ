#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int circle[25]={0};

void create_Circle(int n)
{
    int i;
    for(i=1;i<n+1;i++)
        circle[i]=i;
}

int goA(int pA,int k,int n)
{
    if(circle[pA]!=0)
        k--;
    while(k--)
    {
        do{
            pA=pA+1;
            pA=pA%(n+1);
        }
        while(circle[pA]==0);
    }

    return pA;
}

int goB(int pB,int m,int n)
{
    if(circle[pB]!=0)
        m--;
    while(m--)
    {
        do{
            pB=pB-1;
            pB=(pB+n+1)%(n+1);
        }
        while(circle[pB]==0);
    }

    return pB;
}

int main()
{
    int n,k,m,i,pA,pB,num=0;
    scanf("%d%d%d",&n,&k,&m);
    create_Circle(n);
    pA=1;
    pB=n;
    while(num<n)
    {
        pA=goA(pA,k,n);
        pB=goB(pB,m,n);
        if(pA!=pB)
        {
            printf("%d,%d\n",circle[pA],circle[pB]);
            circle[pA]=0;
            circle[pB]=0;
            num=num+2;
        }
        else
        {
            printf("%d\n",circle[pA]);
            circle[pA]=0;
            num++;
        }
    }

    return 0;
}
