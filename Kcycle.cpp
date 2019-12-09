#include <bits/stdc++.h>
using namespace std;
int n,m,k;
vector <int> adj[51];
int appear[51];
int path[51];
int rs = 0;
void solution()
{
	rs++;
//	for(int i = 1; i <= k; i++)
//	{
//		cout<<path[i]<<" ";
//	}
//	cout<<endl;
}
void cycle (int currentV, int firstV, int numV)
{
	for(int i = 0; i < adj[currentV].size(); i++)
	{
		
		int nextV = adj[currentV][i];
		if(appear[nextV] == 1)
		{
			continue;
		}
		appear[nextV] = 1;
		path[numV] = nextV;
		if(numV == k+1)
		{
			if(nextV == firstV)
			{
				solution();
			}
		}
		else
		{
			cycle(nextV, firstV, numV+1);
		}
		appear[nextV] = 0;
	}
}
void solve()
{
	for(int i = 1; i <= n; i++)
	{
		path[1] = i;
		cycle(i, i, 2);		
	}
	cout<<rs/k/2;
}
int main()
{
	cin>>n>>m>>k;
	for(int i = 1; i <= m; i++)
	{
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i = 1; i <= n; i++)
	{
		appear[i] = 0;
	}
	solve();
	return 0;
}
