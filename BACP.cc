#include <iostream>
using namespace std;
#define max_n 30
#define max_m 10
int n,m;
int c[max_n];
int A[max_n][max_n];
int maxLoad = 9999;
int load[max_m];// load of period
int f_best;
int x[max_n];//period to which course is assigned
int cmin = 9999;
void solution()
{
	int max  = 0; 
	for (int i = 1; i <= m ; i++)
	{
		if (max < load[i]) max = load[i];
	}

	if(max < f_best){
		f_best = max;
	}
}
int check(int v, int k)
{
	for(int i = 1; i <= n; i++)
	{
		if(A[i][k] == 1)
		{
			if(x[i] > v)
			{
				return 0;
			}
		}
		else
		{
			if(A[k][i] == 1)
			{
				if(v > x[i])
				{
					return 0;
				}
			}
		}

	}
	return 1;
}
void TRY(int k)//c la course
{
	for(int v = 1; v <= m; v++)
	{
		if(check(v, k))
		{
			x[k] = v;
			load[v] += c[k];
			if(k==n)
			{
				solution();
			}
			else
			{
				
					TRY(k+1);
				
			}
			load[v] -= c[k];
		}
	}
}
int main()
{
	cin>>n>>m;
	for(int i = 1; i <= n; i++)
	{
		cin>>c[i];
		if(c[i] < cmin)
		{
			cmin = c[i];
		}
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
		load[i] = 0;
	}
	f_best = 9999;
	TRY(1);
	cout<<f_best;
	return 0;
}
