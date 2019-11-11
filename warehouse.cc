#include <iostream>
using namespace std;
int N, T, D;
int a[1001];
int t[1001];
void Solve()
{
	int F[N+1][N+1];
	int time[N+1][N+1];
	for(int i = 0; i <= N; i++)
	{
		for(int j =0; j<= N; j++)
		{
			F[i][j] = 0;
			time[i][j] = 0;
		}
	}
	// for(int i = 1; i <= D; i++)
	// {
	// 	F[i][1] = a[i];
	// 	time[i][1] = t[i];
	// }
	F[1][1] = a[1];
	time[1][1] = t[1];
	int r = 0;
	for(int i = 2; i <= N; i++)
	{
		for(int k = 2; k <= i; k++)
		{
			for(int j = 1; j <= i-1; j++)
			{
				if(D + j >= i)
				{
					 if(F[j][k-1] > 0)
					 {
						if(time[j][k-1] < T)
						{
							if(F[i][k] < F[j][k-1] + a[i] && time[j][k-1] + t[i] <= T)
							{
								F[i][k] = F[j][k-1] + a[i];
								time[i][k] = time[j][k-1] + t[i];
								//cout<<"F"<<i<<k<<" = "<<F[i][k]<<endl;
								if(F[i][k] > r)
								{
									r = F[i][k];
								}
							}
						}	
					}
				}
			}
		}
	}
	
	cout<<r;
}

int main()
{
	cin>>N>>T>>D;
	for(int i = 1; i <= N; i++)
	{
		cin>>a[i];
	}
	for(int i = 1; i <= N; i++)
	{
		cin>>t[i];
	}
	Solve();
	return 0;
}