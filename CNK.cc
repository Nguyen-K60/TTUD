#include<bits/stdc++.h> 
using namespace std;
#define ll long long int 
// ll addmod(ll a, ll b, ll P)
// {
// 	a = a % P;
// 	b = b % P;
// 	ll tmp = P - a;
// 	if(tmp > b)
// 	{
// 		return (a+b);
// 	}
// 	return b - tmp;
// }
// ll mul(ll a, ll b, ll p)
// {
// 	if(a ==0 || b == 0)
// 	{
// 		return 0;
// 	}
// 	if(a==1) return b%p;
// 	if(b==1) return a%p;
// 	if(a>b)
// 	{
// 		ll tmp = a;
// 		a = b;
// 		b = tmp;
// 	}
// 	ll c = mul(a/2,b,p);
// 	c = addmod(c,c,p);
// 	if(a%2==0)
// 	{
// 		return c;
// 	}
// 	return addmod(c,b,p);
// }
ll mul(ll a, ll b, ll mod) 
{ 
    ll res = 0; // Initialize result 
    a = a % mod; 
    while (b > 0) 
    { 
        // If b is odd, add 'a' to result 
        if (b % 2 == 1) 
            res = (res + a) % mod; 
  
        // Multiply 'a' with 2 
        a = (a * 2) % mod; 
  
        // Divide b by 2 
        b /= 2; 
    } 
  
    // Return result 
    return res % mod; 
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
ll Solve(ll a[], ll start, ll end, ll p)
{
	if(start == end)
	{
		return a[start] % p;
	}
	if(start == (end - 1))
	{
		return mul(a[start], a[end], p);
	}
	int mid = (start + end)/2;
	ll left = Solve(a, start, mid, p);
	ll right = Solve(a, mid + 1, end, p);
	return mul(left, right, p);
}
ll binomialCoeff(ll n, ll k, ll p)  
{   
    // Since C(n, k) = C(n, n-k)  
    if ( k > n - k ) 
    { 
        k = n - k;  
  	}
    // Calculate value of  
    // [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]  
    ll nums[k], dens[k];
    for (int i = 0; i < k; ++i)  
    {  
    	nums[i] = n-i;
    	dens[i] = i+1;          
    }  
    ll num = Solve(nums, 0, k-1, p);
    ll den = Solve(dens, 0, k-1, p);
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