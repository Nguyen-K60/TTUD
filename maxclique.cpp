#include <bits/stdc++.h>
using namespace std;
int n,m;
vector <int> adj[13];
int appear[13];
int path[13];
int rs = 0;
void solution(int s)
{
	if(s > rs)
	{
		rs = s;
//		for(int i = 1; i<= s; i++)
//		{
//			cout<<path[i]<<" ";
//		}
//		cout<<endl;
	}
}
int check(int newV, int currentSize)
{
//	if(appear[newV] == 1)
//	{
//		return 0;
//	}
	int pass[currentSize+1];	
	for(int i = 1; i <= currentSize; i++)
	{
		pass[i] = 0;
		for(int j = 0; j < adj[newV].size(); j++)
		{
			if(path[i] == adj[newV][j])
			{
				pass[i] = 1;
				break;
			}
		}
	}
	for(int i = 1; i <= currentSize; i++)
	{
		if(pass[i] == 0)
		{
		//	cout<<"khong thoa man"<<endl;
			return 0;
		}
	}
	return 1;
}
void maxclique(int currentV, int currentSize)
{
	//cout<<"max clique "<<currentV<<endl;
	int n = adj[currentV].size();
	for(int i = 0; i < n; i++)
	{
		int newV = adj[currentV][i];
	//	cout<<"newV "<<newV<<endl;
		if(appear[newV] == 1)
		{
	//		cout<<"da xuat hien"<<endl;
			continue;
		}
		if(check(newV, currentSize))
		{
			appear[newV] = 1;
			path[currentSize+1] = newV;
			solution(currentSize+1);
			maxclique(newV, currentSize+1);
			appear[newV] = 0;
		}
	}
}
void solve()
{
	for(int i = 1; i <= n; i++)
	{
		path[1] = i;
		appear[i] = 1;
		maxclique(i, 1);
		appear[i] = 0;
	}
}
int main()
{
	cin>>n>>m;
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
	cout<<rs;
	return 0;
}
