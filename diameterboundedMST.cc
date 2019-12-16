#include <bits/stdc++.h>
using namespace std;
#define MAX_N 16
#define MAX_M 26
#define MAX_K 11
int n, m, k;
vector <int> adj[MAX_N];
typedef pair<int, int> myPair;
map <myPair, int> weight;
int main()
{
	cin>>n>>m>>k;
	for(int i = 1; i<= m; i++)
	{
		int u, v, w;
		cin>>u>>v>>w;
		adj[u].push_back(v);
		adj[v].push_back(u);
		weight.push_back(make_pair(u, v), w);
		weight.push_back(make_pair(v, u), w);
	}
	return 0;
}