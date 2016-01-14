#include <iostream>
#include <stack>
#include <string>
using namespace std;

typedef struct Matrix
{
    int a,b;
    Matrix(int a=0,int b=0):a(a),b(b) {}
}matrix[26];

stack<Matrix> s;

int main()
{
    int n,i,len;
    matrix m;
    string expr;
    cin >> n;
    for(i=0;i<n;i++)
        cin >> m[i].a >> m[i].b;            //输入n个矩阵的维度
    while(cin >> expr)
    {
        len=expr.length();
        bool error=false;
        int ans=0;
        for(i=0;i<len;i++)
        {
            if(isalpha(expr[i]))
                s.push(m[expr[i]-'A']);
            else if(expr[i]==')')
            {
                Matrix m2=s.top();
                s.pop();
                Matrix m1=s.top();
                s.pop();
                if(m1.b!=m2.a)
                {
                    error=true;
                    break;
                }
                ans+=m1.a*m1.b*m2.b;
                s.push(Matrix(m1.a,m2.b));
            }
        }
        if(error)
            cout<<"error"<<endl;
        else
            cout<<ans<<endl;
    }

    return 0;
}
