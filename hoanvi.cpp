//liet ke hoan vi
#include <iostream>
using namespace std;
#define max 100
int n;
int x[max];
int appear[max];
int check(int v, int k)
{
	return !appear[v];
}
void solution()
{
	for(int i = 1; i <= n; i++)
	{
		cout<<x[i];
	}
	cout<<endl;
}
void TRY(int k)
{
	for(int v = 1; v <= n; v++)
	{
		if(check(v, k))
		{
			x[k] = v;
			appear[v] = 1;
			if(k == n )
			{
				solution();
			}
			else
			{
				TRY(k + 1);
			}
			appear[v] = 0;
		}
	}
}
int main()
{
	cin>>n;
	for(int i = 1; i <= n; i++)
	{
		appear[i] = 0;
	}
	TRY(1);
	return 0;
}
