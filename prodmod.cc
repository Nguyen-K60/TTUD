#include<bits/stdc++.h> 
using namespace std;
#define ll long long int 
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
ll Solve(ll a[], ll start, ll end, ll p)
{
	if(start == end)
	{
		return a[start] % p;
	}
	if(start == (end - 1))
	{
		return (a[start]%p * a[end]%p)%p;
	}
	int mid = (start + end)/2;
	ll left = Solve(a, start, mid, p);
	ll right = Solve(a, mid + 1, end, p);
	return (left%p * right%p)%p;
}
int main()
{
	ll P = pow(10, 9) + 7;
	ll n;
	cin>>n;
	ll a[n];
	for(int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	cout<<Solve(a, 0, n-1, P);
}