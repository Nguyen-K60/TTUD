#include <iostream>
using namespace std;
int n;
int x[100];
int check(int v, int k)
{
	if(k==1)
	{
		return 1;
	}
	return x[k-1] + v <= 1;
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
	for(int v = 0; v <= 1; v++)
	{
		if(check(v, k))
		{
			x[k] = v;
			if(k == n)
			{
				solution();
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
	cin>>n;
	TRY(1);
	return 0;
}
