#include <bits/stdc++.h> 
#include <stdio.h>
using namespace std;
#define MAX 100000
long long N, x[MAX], y[MAX];
double MIN = 100000000;
int first = -1, second = -1;
double CalculateDistance(int i, int j)
{
	
}
void Solve()
{
	double f;
	for(int i = N-1; i > 0; i--)
	{
		for(int j = i - 1; j >= 0; j--)
		{
			int xx = x[i] - x[j];
			if(xx > MIN)
			{
				continue;
			}
			int yy = y[i] - y[j];
			if(yy > MIN)
			{
				continue;
			}
			f = std::sqrt(xx*xx+yy*yy);
			if(f < MIN)
			{
				first = j;
				second = i;
				MIN = f;
			}
		}
	}
}
int main()
{
	cin>>N;
	for(int i = 0; i < N; i++)
	{
		cin>>x[i]>>y[i];
	}
	Solve();
	printf("%d %d %.6lf",first, second, MIN );
	return 0;
}