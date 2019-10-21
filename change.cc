#include <bits/stdc++.h>
using namespace std;
int n;
int a[6] = {1, 5, 10, 50, 100, 500};
void Solve()
{
	int remain = 1000 - n;
	int count = 0;
	for(int i = 5; i >= 0; i--)
	{
		int c = remain/a[i];
		count += c;
		remain -= c*a[i];
	}
	cout<<count;
}
int main()
{
	cin>>n;
	Solve();
	return 0;
}