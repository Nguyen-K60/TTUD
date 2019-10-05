#include <iostream>
#include <math.h>
using namespace std;
int addmod(int a, int b, int P)
{
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
int xmun(int x, int n, int p) 
{ 
    if(n==1)
    {
    	return x%p;
	}
    	
    int a = xmun(x,n/2,p);
    a = mul(a,a,p);
    if(n%2==0)
    {
    	return a;
	}
	return mul(a,x,p);
} 
int main()
{
	int a,b;
	int p=pow(10, 9)+7;

	cin>>a>>b;
	cout<<xmun(a,b,p);
	return 0;
}
