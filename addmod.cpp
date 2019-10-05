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
int main()
{
	int a, b;
	int c = pow(10,9) + 7;
	cin>>a>>b;
	cout<<addmod(a,b,c);
}
