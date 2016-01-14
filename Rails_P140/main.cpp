#include <iostream>
#include <stack>
using namespace std;
const int MAXN = 1000 + 10;

int main()
{
    int n,i;
    int target[MAXN];
    while(scanf("%d",&n) == 1)
    {
        stack<int> s;
        int A=1,B=1;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&target[i]);
        }
        int ok=1;
        while(B<n)
        {
            if(A==target[B])
            {
                A++;
                B++;
            }
            else if(!s.empty() && s.top() == target[B])
            {
                s.pop();
                B++;
            }
            else if(A<=n)
                s.push(A++);
            else
            {
                ok=0;
                break;
            }
        }
        printf("%s\n",ok?"Yes":"No");
    }

    return 0;
}
