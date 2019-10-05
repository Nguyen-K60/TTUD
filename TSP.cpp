#include <iostream>
using namespace std;
int n;
#define max 16
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
	int r = result + c[x[n]][0];
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
			
			x[k] = v;
			result += c[x[k-1]][x[k]];
			appear[v] = 1;
			if(k == n )
			{
				solution();
			}
			else
			{
				if(result + cmin*(n-k+1) < MIN)
				{				
					TRY(k + 1);
				}
			}
			appear[v] = 0;
			result -= c[x[k-1]][x[k]];
		}
	}
}
int main()
{
	cin>>n;
	for(int i = 0; i <= n ; i++)
	{
		for(int j = 0; j <= n; j++)
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
