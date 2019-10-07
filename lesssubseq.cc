#include <iostream>
using namespace std;
int N, M;
int a[100000];
int count = 0, S;
void solve(){
	for(int i=1;i<=N;i++)
	{
		S=a[i];
		if(S>M) continue;		
		count++;
		for(int j=i+1;j<=N;j++)
		{
				S=S+a[j];
				if(S>M) 
				{
					break;
				}
				count++;
		}
	}
	printf("%d",count);
}
int main()
{
	
	cin>>N>>M;
	
	for(int i = 1; i <= N; i++)
	{
		cin>>a[i];
	}
	solve();
    return 0;
}
