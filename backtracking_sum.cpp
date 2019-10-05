#include <iostream>
using namespace std;
int n;
int M;
int x[100];
int T = 0;
int cnt = 0;
int check(int v, int k)
{
	if(k < n)
	{
		return T + v <= M ;
	}
	return T + v == M;
}
void solution()
{
	cout<<cnt++<<": ";
	for(int i = 1; i <= n; i++)
	{
		cout<<x[i]<<" ";
	}
	cout<<endl;
}
void TRY(int k)
{
	for(int v = 1; v <= M - T - (n-k); v++)
	{
		if(check(v, k))
		{
			x[k] = v;
			T += v;
			if(k ==n)
			{
				solution();
			}
			else
			{
				TRY(k+1);
			}
			T -= v;
		}		
	}
}
int main()
{
	cin>>n>>M;
	TRY(1);
	return 0;
}
