#include<bits/stdc++.h> 
using namespace std;
#define ll long long int 
ll addmod(ll a, ll b, ll P)
{
	a = a % P;
	b = b % P;
	ll tmp = P - a;
	if(tmp > b)
	{
		return (a+b);
	}
	return b - tmp;
}
ll mul(ll a, ll b, ll p)
{
	if(a ==0 || b == 0)
	{
		return 0;
	}
	if(a==1) return b%p;
	if(b==1) return a%p;
	if(a>b)
	{
		ll tmp = a;
		a = b;
		b = tmp;
	}
	ll c = mul(a/2,b,p);
	c = addmod(c,c,p);
	if(a%2==0)
	{
		return c;
	}
	return addmod(c,b,p);
}
ll power(ll x, ll y, ll p) 
{ 
    ll res = 1;      // Initialize result 
  
    x = x % p;  // Update x if it is more than or 
                // equal to p 
  
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
  
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p; 
    } 
    return res; 
} 
  
// Returns n^(-1) mod p 
ll modInverse(ll n, ll p) 
{ 
    return power(n, p-2, p); 
}
ll binomialCoeff(ll n, ll k, ll p)  
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
        num = mul(num, n - i, p);
        if(num == 0)
        {
        	return 0;
        } 
        den = mul(den, i + 1, p); 
        if(den == 0)
        {
        	return 0;
        }
    }  
  	ll iv = modInverse(den, p);
    return mul(num, iv, p);  
} 
int main()
{
	int T;
	cin>>T;
	ll n[T], k[T], m[T];
	for(int i = 0; i < T; i++)
	{
		cin>>n[i]>>k[i]>>m[i];
	}
	for(int i = 0; i < T; i++)
	{
		cout<<binomialCoeff(n[i], k[i], m[i])<<endl;
	}
	return 0;
}