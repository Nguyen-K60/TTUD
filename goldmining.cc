#include <iostream>
using namespace std;
#define max 100001
int n;
int L1, L2;
int a[max];
void Solve()
{
	int s[max];
    s[1] = a[1];
    int ans = s[1];
    for(int i=1;i<=n;i++)
    {
		s[i]=a[i];
		for(int k =L1;k<=L2;k++)
		{
			int sj=0;
			if(i-k>=1)
			{
				sj=s[i-k];
			}
			if(s[i]<sj+a[i])
			{
				s[i]=sj+a[i];
			}
		}
		if(ans<s[i])
		{
			ans=s[i];
		}
	}
    cout<<ans; 
}
int main()
{
	cin>>n>>L1>>L2;
	for(int j = 1; j <= n; j++)
	{
		cin>>a[j];
	}	
	Solve();
	return 0;
}
