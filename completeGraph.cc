#include <bits/stdc++.h>
#define MAX 1000
using namespace std;

int main()
{
	int n;
	cin>>n;
	int g[n][n];
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin>>g[i][j];
		}
	}	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(g[i][j] == 0 && i != j)
			{
				cout<<"0";
				return 0;
			}
		}
	}
	cout<<1;
	return 0;
}