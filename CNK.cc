#include<bits/stdc++.h> 
using namespace std;
int min(int a, int b) 
{ 
    return (a < b) ? a : b; 
}
int CNK(int n, int k, int m) 
{ 
    int C[k+1]; 
    memset(C, 0, sizeof(C)); 
  
    C[0] = 1;  // nC0 is 1 
  
    for (int i = 1; i <= n; i++) 
    { 
        // Compute next row of pascal triangle using 
        // the previous row 
        for (int j = min(i, k); j > 0; j--) 
            C[j] = (C[j]%m + C[j-1]%m)%m; 
    } 
    return C[k]; 
}
int main()
{
	int T;
	cin>>T;
	int n[T], k[T], m[T];
	for(int i = 0; i < T; i++)
	{
		cin>>n[i]>>k[i]>>m[i];
	}
	for(int i = 0; i < T; i++)
	{
		if(n[i] - k[i] > k[i])
		{
			cout<<CNK(n[i], k[i], m[i])<<endl;
		}
		else
		{
			cout<<CNK(n[i], n[i] - k[i], m[i])<<endl;
		}
	}
	return 0;
}