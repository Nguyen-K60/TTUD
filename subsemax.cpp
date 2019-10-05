#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	int smax = a[0];
	int maxendhere = a[0];
	for(int i = 1; i < n; i++)
	{
		int u = maxendhere + a[i];
		int v = a[i];
		maxendhere = u>v?u:v;
		if(maxendhere > smax)
		{
			smax = maxendhere;
		}
	}
	cout<<smax;
    return 0;
}
