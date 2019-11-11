#include <bits/stdc++.h>
using namespace std;
#define MAX 3001
#define MAX1 101
int N,K,c[MAX],a[MAX],F[MAX][MAX1];

void Solve()
{
	for(int i = 0; i <= N; i++)
	{
		for(int j =0; j<= K; j++)
		{
			F[i][j] = 0;
		}
	}
	F[1][0] = c[1];
	for(int i = 2; i <= N; i++)
	{
		for(int k = 1; k <= K; k++)
		{
			for(int j = 1; j <= i-1; j++)
			{
				if(a[j]+j >= i)
				{
					if(F[j][k-1] > 0)
					{
						if(F[i][k] < F[j][k-1] + c[i])
						{
							F[i][k] = F[j][k-1] + c[i];
							//cout<<"F["<<i<<"]["<<k<<"] = "<<F[i][k]<<endl;
						}
					}
				}
			}
		}
	}
	int t = F[N][1];
	for(int i = 2; i <= K; i++)
	{
		if(F[N][i] > t)
		{
			t = F[N][i];
		}
	}
	if(t > 0)
	{
		cout<<t;
	}
	else
	{
		cout<<-1;
	}
}
int main()
{
	cin>>N>>K;
	for(int i = 1; i <= N; i++)
	{
		cin>>c[i];
	}
	for(int i = 1; i <= N; i++)
	{
		cin>>a[i];
	}
	Solve();
	return 0;
}