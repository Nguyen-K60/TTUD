#include <bits/stdc++.h>
#define MAX_N 100001
using namespace std;
int N, M;
std::vector<int> A[MAX_N];
int d[MAX_N], f[MAX_N], p[MAX_N];
char color[MAX_N];
int t = 0;
int c = 0;
std::vector<int> path;
void DFS(int u)
{
	path.push_back(u);
	t = t + 1;
	d[u] = t;
	color[u] = 'G';
	for(int i = 0; i < A[u].size(); i++)
	{
		int v = A[u][i];
		if(color[v] == 'W')
		{
			p[v] = u;
			DFS(v);
		}
	}
	t = t + 1;
	f[u] = t;
	//color[u] = 'W';
}
void DFS()
{
	for(int v = 1; v <= N; v++)
	{
		color[v] = 'W';
	}
	t = 0;
	for(int v = 1; v <= N; v++)
	{
		if(color[v] == 'W')
		{
			path.clear();
			DFS(v);
			c++;
			for(int k = 0; k < path.size(); k++)
			{
				cout<<path[k]<<" ";
			}
			cout<<endl;
		}
	}
}
void input()
{
	cin>>N>>M;
	for(int i = 1; i <= M; i++)
	{
		int u,v;
		cin>>u>>v;
		A[u].push_back(v);
		A[v].push_back(u);
	}
}
void printGraph()
{
	for(int v = 1; v <= N; v++)
	{
		cout<<"A["<<v<<"]: ";
		for(int i = 0; i < A[v].size(); i++)
		{
			cout<<A[v][i]<<" ";
		}
		cout<<endl;
	}
}
int main()
{
	input();
	//printGraph();
	DFS();
	cout<<c;
	return 0;
}