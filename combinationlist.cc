#include <bits/stdc++.h> 
using namespace std; 
#define ll long long int 
ll n, m, K;

ll binomialCoeff(ll n, ll k)  
{   
    // Since C(n, k) = C(n, n-k)  
    if ( k > n - k ) 
    { 
        k = n - k;  
    }
    ll num = 1, den = 1;
    // Calculate value of  
    // [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]  
    for (int i = 0; i < k; ++i)  
    {  
        num *= (n-i)
        if(num % (i+1) == 0)
        {
            num /= (i+1);
        }
        else
        {
            den *= (i+1);
        }
    }  
    return num/den; 
} 
void Solve(ll n, ll m, ll K)
{

}
int main() 
{     
    cin>>n>>m>>K;
    Solve();
    return 0; 
}