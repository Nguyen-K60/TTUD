#include <iostream>
using namespace std;
#define m 1000000007
int a[101];
int N, M;
void Solve()
{
	int S[N+1][M+1];
	for(int i = 0; i <= N; i++)
	{
		for(int j = 0; j <= M; j++)
		{
			S[i][j] = -1;
		}
	}
	for(int i = 1; i <= M; i++)
	{
		if(i % a[1] == 0)
		{
			S[1][i] = 1;
		}
		else
		{
			S[1][i] = 0;
		}
	}
	int T = 0;
	for(int i = 1; i <= N; i++)
	{
		T += a[i];
	}
	for(int i = 2; i <= N; i++)
	{
		for(int j = 1; j <= (M-T)/a[i]; j ++)
		{
			if(M - j*a[i] > 0 && S[i-1][M-j*a[i]] > -1)
			{
				S[i][M] = (S[i][M] + S[i-1][M-j*a[i]])%m;
			}
			else
			{
				break;
			}
		}
	}
	cout<<S[N][M];
}
int main()
{
	cin>>N>>M;
	for(int i = 1; i <= N; i++)
	{
		cin>>a[i];
	}
	Solve();
	return 0;
}