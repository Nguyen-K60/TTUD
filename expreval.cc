#include <iostream>
#include <math.h>
using namespace std;
int p = 1000000007;
int n;
int a[200000];
int b[200000];
int r = 0;
int v[200000];
int addmod(int a, int b, int P)
{
	//cout<<"add "<<a<<" "<<b<<endl;
	if((a >= 0 && b <= 0)||(a <= 0 && b >=0))
	{
		int w;
		if(abs(a) > abs(b))
		{
			w = abs(a) - abs(b);
			if(a < 0)
			{
				w = -w;
			}
		}
		else
		{
			w = abs(b) - abs(a);
			if(b < 0)
			{
				w = -w;
			}
		}
		while(w < 0)
		{
			w += P;
		}
		return w;
	}
	a = a % P;
	b = b % P;
	int tmp = P - a;
	if(tmp > b)
	{
		return (a+b);
	}
	return b - tmp;
}
int mul(int a, int b, int p)
{
	if(a==1) return b%p;
	if(b==1) return a%p;
	if(a>b)
	{
		int tmp = a;
		a = b;
		b = tmp;
	}
	int c = mul(a/2,b,p);
	c = addmod(c,c,p);
	if(a%2==0)
	{
		return c;
	}
	return addmod(c,b,p);
}
void Solve()
{
	//cout<<"mul"<<endl;
	for(int i = 1; i < n; i++)
	{
		if(b[i] == 2)
		{
			a[i] = mul(a[i], a[i-1], p);
			v[i-1] = 1;
			b[i] = 1;
		}
	}
		for(int i = 0; i < n; i++)
	{
		if(v[i] == 0)
		{
			if(b[i] == 1)
			{
				r = addmod(r, a[i], p);
			}
			else
			{
				r = addmod(r, -a[i], p);
			}
			v[i] = 1;
			// for(int i = 0; i < n; i++)
			// {
			// 	cout<<a[i]<<" ";
			// }
			// cout<<endl;
			// for(int i = 0; i < n; i++)
			// {
			// 	cout<<v[i]<<" ";
			// }
			// cout<<r;
			// cout<<endl;
		}
	}
	cout<<r;
}
int main()
{
	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>a[i];
		v[i] = 0;
	}
	for(int i = 1; i < n; i++)
	{
		cin>>b[i];
	}
	
		b[0] = 1;
	
	Solve();
	return 0;
}