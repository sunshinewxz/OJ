#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int i=0,j=0,num=0,m=0,len=0,k1=0,k2=0,flag=0,o=0;
    char s[20],oper[20],temp;
    char gragh[5][5];
    while(gets(s))
    {
        if(s[0]=='Z')
        {
            return 0;
        }

        if(strlen(s)<5)
            s[4]=' ';
        flag=0;
        for(j=0;j<5;j++)
        {
            if(s[j]==' ')
            {
                k1=i;
                k2=j;
            }
            gragh[i][j]=s[j];
        }
        i++;

        if(i>4)
        {
            o=0;
            while(scanf("%c",&oper[o])==1)
            {
                if(oper[o]=='\n')
                    continue;
                if(oper[o]=='0')
                    break;
                else
                    o++;
            }
        }
        else
            continue;
        len=o+1;
        for(m=0;m<len;m++)
        {
            if(flag==1)
                break;
            switch (oper[m])
            {
            case 'A':
                if(k1==0)
                {
                    flag=1;
                    break;
                }
                temp=gragh[k1][k2];
                gragh[k1][k2]=gragh[k1-1][k2];
                gragh[k1-1][k2]=temp;
                k1--;
                break;
            case 'B':
                if(k1==4)
                {
                    flag=1;
                    break;
                }
                temp=gragh[k1][k2];
                gragh[k1][k2]=gragh[k1+1][k2];
                gragh[k1+1][k2]=temp;
                k1++;
                break;
            case 'L':
                if(k2==0)
                {
                    flag=1;
                    break;
                }
                temp=gragh[k1][k2];
                gragh[k1][k2]=gragh[k1][k2-1];
                gragh[k1][k2-1]=temp;
                k2--;
                break;
            case 'R':
                if(k2==4)
                {
                    flag=1;
                    break;
                }
                temp=gragh[k1][k2];
                gragh[k1][k2]=gragh[k1][k2+1];
                gragh[k1][k2+1]=temp;
                k2++;
                break;
            case '0':
                break;
            default :
                break;
            }
        }

        num++;
        printf("\n");
        printf("Puzzle #%d:\n",num);
        if(flag==1)
            printf("This puzzle has no final configuration.\n\n");
        else
        {
            for(i=0;i<5;i++)
            {
                for(j=0;j<4;j++)
                    printf("%c ",gragh[i][j]);
                printf("%c\n",gragh[i][4]);
            }
            printf("\n");
        }

        i=0;
        getchar();
    }
    return 0;
}
