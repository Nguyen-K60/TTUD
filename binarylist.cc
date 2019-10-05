#include <iostream>
using namespace std;
#define MAX 100000
int n, K, I;
int so = -1;
int COUNT = 0;
int x[MAX];
int check(int v, int k)
{
	if(v == 1)
	{
		return 1;
	}
	if(k<I)
	{
		return 1;
	}
	int sum = 0;
	for(int i = k-1; i > k - I; i--)
	{
		if(x[i] == 1)
		{
			return 1;
		}
	}
	return 0;;
}
void solution()
{
	for(int i = 1; i <= n; i++)
	{
		cout<<x[i]<<" ";
	}
}
void TRY(int k)
{
	for(int v = 0; v <= 1; v++)
	{
		if(check(v, k))
		{
			x[k] = v;
			if(k == n)
			{
				COUNT++;
				if(COUNT == K)
				{
					so = 1;
					solution();
					return;
				}
			}
			else
			{
				TRY(k+1);
			}
		}
		
	}
}
int main()
{
	cin>>n>>K>>I;
	TRY(1);
	if(so == -1)
	{
		cout<<so;
	}
	return 0;
}
