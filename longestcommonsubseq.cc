#include<bits/stdc++.h>  
using namespace std; 
#define MAX 10001
int X[MAX] ;  
int Y[MAX] ; 
int R[MAX][MAX];
int n;
int m;
int bigger(int a, int b)
{
    return a>b?a:b;
}
void Solve()
{ 
    R[1][0] = 0;
    R[0][1] = 0;
    for(int j = 1; j <= m; j++)
    {
        if(!R[1][j-1])
        {
            if(Y[j] == X[1])
            {
                R[1][j] = 1;
            }
            else
            {
                R[1][j] = 0;
            }
        }
        else
        {
            R[1][j] = 1;
        }
    }
    for(int j = 1; j <= n; j++)
    {
        if(!R[j-1][1])
        {
            if(X[j] == Y[1])
            {
                R[j][1] = 1;
            }
            else
            {
                R[j][1] = 0;
            }
        }
        else
        {
            R[j][1] = 1;
        }
    }
    for(int i = 2; i <= n; i++)
    {
        for(int j = 2; j <= m; j++)
        {
            if(X[i] == Y[j])
            {
                R[i][j] = 1 + R[i-1][j-1];
            }
            else
            {
                R[i][j] = bigger(R[i][j-1], R[i-1][j]);
            }
        }
    }
    cout<<R[n][m]<<endl;
} 
int main()  
{  
    
    cin>>n>>m;     
    for(int i = 1; i <= n; i++)
    {
        cin>>X[i];
    }
    for(int i = 1; i <= m; i++)
    {
        cin>>Y[i];
    }
    Solve();  
      
    return 0;  
}