#include<vector>
#include<iostream>
#define MAX_N 100001
using namespace std;
int N;
int S[MAX_N];
vector<int> A[MAX_N],W[MAX_N];
int p[MAX_N];
char color[MAX_N];
int desmax;
 
int dismax;
 
 
void input()
{
	cin >> N;
	for (int i = 1; i <= N-1; i++)
	{
		int u, v,w;
		cin >> u >> v >> w ;
		A[u].push_back(v);
		A[v].push_back(u);
		W[u].push_back(w);
		W[v].push_back(w);
	}
}
void DFS(int u)
{ 
	color[u] = 'G';
	for (int i = 0; i < A[u].size(); i++)
	{
		int v = A[u][i];
		if (color[v] == 'W')
		{
			p[v] = u;
			S[v] = S[u] + W[u][i];
			if (dismax < S[v])
			{
				dismax = S[v];
				desmax = v;
			}
			DFS(v);
		}
	}
	
	color[u] = 'B';
}
 
void DFS()
{
	for (int v = 1; v <= N; v++)
	{
		color[v] = 'W';
	}
	
	for (int i = 1; i <= MAX_N; i++)
	{
		S[i] = 0;
	}
	DFS(1);
	//cout << dismax << endl;
	dismax = 0;
	for (int i = 1; i <= MAX_N; i++)
	{
		S[i] = 0;
	}
	for (int v = 1; v <= N; v++)
	{
		color[v] = 'W';
	}
 
	DFS(desmax);
	cout << dismax << endl;
 
}
int main()
{
	 desmax=0;
 
	 dismax=0;
 
 
	
	input();
	//printGraph();
	DFS();
 
	return 0;
}