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
ll Solve(ll a[], int start, int end, ll p)
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
int main()
{
	ll P = pow(10, 9) + 7;
	int n;
	cin>>n;
	int a[n];
	for(int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	ll S = mul(a[0], a[1], P);
	for(int i = 2; i < n; i++)
	{
		S = mul(S, a[i], P);
	}
	cout<<S;
}