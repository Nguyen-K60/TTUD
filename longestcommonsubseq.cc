#include<bits/stdc++.h>  
using namespace std; 
int X1[10000] ;  
int Y1[10000] ; 
int lcs(string &X, string &Y) 
{ 
      
    // Find lengths of two strings 
    int m = X.length(), n = Y.length(); 
  
    int L[2][n + 1]; 
  
    // Binary index, used to 
    // index current row and 
    // previous row. 
    bool bi; 
  
    for (int i = 0; i <= m; i++) 
    { 
          
        // Compute current  
        // binary index 
        bi = i & 1; 
  
        for (int j = 0; j <= n; j++) 
        { 
            if (i == 0 || j == 0) 
                L[bi][j] = 0; 
  
            else if (X[i-1] == Y[j-1]) 
                 L[bi][j] = L[1 - bi][j - 1] + 1; 
  
            else
                L[bi][j] = max(L[1 - bi][j],  
                               L[bi][j - 1]); 
        } 
    } 
  
    // Last filled entry contains 
    // length of LCS 
    // for X[0..n-1] and Y[0..m-1]  
    return L[bi][n]; 
} 
int main()  
{  
    int n;
    int m;
    cin>>n>>m;

     
    for(int i = 0; i < n; i++)
    {
        cin>>X1[i];
    }
    for(int i = 0; i < m; i++)
    {
        cin>>Y1[i];
    }
    string x;
    for(int i = 0; i < n; i++)
    {
        x += to_string(X1[i]);
    }
    string y;
    for(int i = 0; i < m; i++)
    {
        y += to_string(Y1[i]);
    }
    cout <<lcs(x, y);  
      
    return 0;  
}