#include <iostream>
using namespace std;
int n;
#define max 100
int appear[max];
int c[max][max];
int cmin = 9999999;
int x[max];
int result = 0;
int MIN = 9999999;
int check(int v, int k)
{
	return !appear[v];
}
void solution()
{
	int r = result + c[x[n]+n][0];
	if(r < MIN)
	{
		MIN = r;
	}
}
void TRY(int k)
{
	for(int v = 1; v <= n; v++)
	{		
		if(check(v, k))
		{	
			int dt;		
			x[k] = v;
			if(k == 1)
			{
				dt = c[0][x[k]];
			}
			else
			{
				dt = c[x[k-1]+n][x[k]];
			}
			result += dt;
			result += c[x[k]][x[k]+n];
			appear[v] = 1;
	
			if(k == n )
			{
				solution();
			}
			else
			{
				if(result + cmin*(n-k+1)*2 < MIN)
				{				
					TRY(k + 1);
				}
			}
			appear[v] = 0;

			result -= dt;
			result -= c[x[k]][x[k]+n];
		}
	}
}
int main()
{
	cin>>n;
	for(int i = 0; i < 2*n + 1 ; i++)
	{
		for(int j = 0; j < 2*n + 1; j++)
		{
			cin>>c[i][j];
			if(c[i][j] < cmin && c[i][j] > 0)
			{
				cmin = c[i][j];
			}
		}
		cout<<endl;
		appear[i] = 0;

	}
	TRY(1);
	cout<<MIN;
	return 0;
}
