#include <iostream>
using namespace std;
int N;
int Q = 0;
int a[1002];
void Solve()
{
	int Q[N+1];
	Q[1] = 0;
	if(a[1] < a[2])
	{
		Q[2] = 1;
	}
	else
	{
		Q[2] = 0;
	}

	for(int i = 3; i <= N; i++)
	{
		Q[i] = Q[i-1];
		for(int j = i-1; j >= 1; j--)
		{
			if(a[i] > a[j])
			{
				Q[i] ++;
			}
		}
	}
	cout<<Q[N];
}
int main()
{
	cin>>N;
	for(int i = 1; i <= N; i++)
	{
		cin>>a[i];
	}
	Solve();
	return 0;
}