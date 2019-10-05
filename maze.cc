#include <iostream>
using namespace std;
#define MAX 1000
int a[MAX][MAX];
int sol[MAX][MAX];
int N, M, i0, j0;
int f_best = 99999;
int f = 0;
void solution()
{
	if(f < f_best)
	{
		f_best = f;
	}
}
int check(int x, int y)
{
	if(sol[x][y] == 0 && a[x][y] == 0)
	{
		return 1;
	}
	return 0;
}
void Solve(int x, int y)
{
	//cout<<"solve "<<x<<" "<<y<<endl;
		if(check(x, y))
		{
			sol[x][y] = 1;
			f++;
			if(x == 1 || x == N || y == 1 || y == M)
			{
				solution();
			}
			else
			{
				if(f + N - x < f_best)
				{
					Solve(x + 1, y);
				}
					
				if(f + x - 1 < f_best)
				{
					Solve(x - 1, y);
				}
				if(f + y - 1 < f_best)
				{
					Solve(x, y - 1);
				}

				if(f + M - y < f_best)
				{
					Solve(x, y + 1);
				}
			}
			sol[x][y] = 0;
			f--;
		}
}


int main()
{
	cin>>N>>M>>i0>>j0;
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= M; j++)
		{
			cin>>a[i][j];
			sol[i][j] = 0;
		}
	}
	Solve(i0, j0);
	if(f_best == 99999)
	{
		cout<<-1;		
	}
	else
	{
		cout<<f_best;
	}
	return 0;
}