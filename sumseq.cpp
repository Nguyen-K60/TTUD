#include <iostream>
using namespace std;
#define P 1000000007
int sumseq(int a[], int n, int p)
{
	int result = a[0] % p;
	for(int i = 1; i < n; i++)
	{
		result = (a[i] % p + result) % p;
	}
	return result;
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	cout<<sumseq(a,n,P);
	return 0;
}
