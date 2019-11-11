#include <iostream>
using namespace std;
int n, b;
int a[31];
int x[31];
int s = 0;
int r = 0;
int p = 1000000007;
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
void Solution()
{
	if(s == b)
	{
		r = addmod(r,1,p);
		// for(int i = 1; i <= n; i++)
		// {
		// 	if(x[i] == 0)
		// 	{
		// 		cout<<"+";
		// 	}
		// 	else
		// 	{
		// 		cout<<"-";
		// 	}
		// 	cout<<a[i];
		// }
		// cout<<endl;
	}
}
void Try(int k)
{
	for(int i = 0; i < 2; i++)
	{
		if(i == 0)
		{
			x[k] = i;
			s += a[k];
			if(k == n)
			{
				Solution();
			}
			else
			{
				Try(k+1);
			}
			s -= a[k];
		}
		else
		{
			x[k] = i;
			s -= a[k];
			if(k == n)
			{
				Solution();
			}
			else
			{
				Try(k+1);
			}
			s += a[k];
		}
	}
}
int main()
{
	cin>>n>>b;
	for(int i = 1; i <= n; i++)
	{
		cin>>a[i];
	}
	s = a[1];
	Try(2);
	cout<<r;
	return 0;
}