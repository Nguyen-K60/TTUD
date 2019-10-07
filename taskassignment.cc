#include<bits/stdc++.h> 
using namespace std;
#define MAX 35
int N, M, K;
int c[MAX][MAX];
int x[MAX];//who do this job
int load[MAX];//number of job of worker
int cmin = 9999;//min value in c[][]
int minC = 9999;// min cost
int cost = 0; //current cost
int check(int v, int k)
{
	if(load[v] >= K)
	{
		return 0;
	}
	return 1;
}
void solution()
{
	if(cost < minC)
	{
		minC = cost;
	}
}
void TRY(int k)
{
	for(int v = 1; v <= M; v++)
	{
		if(check(v, k))
		{
			x[k] = v;
			load[v] ++;
			cost += c[v][k];
			if(k==N)
			{
				solution();
			}
			else
			{
				if(cost + cmin*(N-k) < minC)
				{
					TRY(k+1);
				}
				
			}
			load[v] --;
			cost -= c[v][k];
		}
	}
}
int main()
{
	cin>>N>>M>>K;
	for(int i = 1; i <= M; i++)
	{
		load[i] = 0;
		for(int j = 1; j <= N; j++)
		{
			cin>>c[i][j];
			if(c[i][j] < cmin)
			{
				cmin = c[i][j];
			}
		}
		cout<<endl;
	}
	TRY(1);
	cout<<minC;
	return 0;
}