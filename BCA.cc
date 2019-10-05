#include <iostream>
using namespace std;
#define max 50
int n,m;
int h[max];
int k[max][max];
int A[max][max];
int L[max][max];
int maxLoad = 9999;
void MaxLoad()
{
	int load[m];
	for(int i = 1; i <= m ; i++)
	{
		load[i-1] = 0;
		for(int j = 1; j <= n; j++)
		{
			if(L[i][j] != 9999)
			{
				load[i-1] += h[L[i][j]];
			}
		}
		
	}
	int id = 0;
	for(int i = 1; i < m; i++)
	{
		if(load[i] > load[id])
		{
			id = i;
		}
	}
	if(load[id] < maxLoad)
		{
			maxLoad = load[id];
		}
}
int check(int v, int b)
{
	for(int i = 1; i <= n; i++)
	{
		if(L[v][i] == 9999)
		{
			continue;
		}
		else
		{
			if(A[b][L[v][i]] == 1)
			{
				return 0;
			}
		}
	}
	return 1;
}
void solution()
{
	MaxLoad();
}
void TRY(int b)//b la course
{
	for(int v = 1; v <= k[b][0]; v++)//v la giao vien
	{		
		if(check(k[b][v], b))
		{			
			L[k[b][v]][b] = b;
			if(b == n)
			{
				solution();
			}
			else
			{
				TRY(b + 1);
			}
			L[k[b][v]][b] = 9999;
		}
	}
}
int main()
{
	cin>>n>>m;
	for(int i = 1; i <= n; i++)
	{
		cin>>h[i];
	}
	for(int i = 1; i <= n; i++)
	{
		cin>>k[i][0];
		for(int j = 1; j <= k[i][0]; j++)
		{
			cin>>k[i][j];
		}
		cout<<endl;
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			cin>>A[i][j];
		}
		cout<<endl;
	}
	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			L[i][j] = 9999;
		}		
	}
	TRY(1);
	cout<<maxLoad;
	return 0;
}
