#include <iostream>
using namespace std;
int n;
int a[100001];
int idMin(int arr[], int size)
{
	int id = 0;
	int m = arr[0];
	for(int i = 1; i < size; i++)
	{
		if(arr[i] < m)
		{
			id = i;
			m = arr[i];
		}
	}
	return id;
}
int idMax(int arr[], int size)
{
	int id = 0;
	int m = arr[0];
	for(int i = 1; i < size; i++)
	{
		if(arr[i] > m)
		{
			id = i;
			m = arr[i];
		}
	}
	return id;
}
int Solve() 
{ 
    int ans = -1000000; 
    int s[n];
    s[0] = a[0]; 
    int odd = 0, even = 0;
    int o[100001], e[100001];

    for (int i = 1; i < n; ++i) 
    { 
    	s[i] = s[i-1] + a[i];
    } 
  	for(int i = 0; i < n; i ++)
  	{
  		if(s[i] % 2 == 0)
  		{
  			e[even] = s[i];
  			even++;
  		}
  		else
  		{
  			o[odd] = s[i];
  			odd++;
  		}
  	}
  	int e1 = 0, e2 = 0;
  	int im = idMax(e, even);
  	if(im > 0)
  	{
  		int im1 = idMin(e, im);
  		e1 = e[im] - e[im1];
  	
  	}
  	
  	int mm = idMax(o, odd);
  	if(mm > 0)
  	{
  		int mm1 = idMin(o, mm);
  		e2 = o[mm] - o[mm1];
  	}
  	int u = e1>e2?e1:e2;
  	if(u > 0)
  	{
  		return u;
  	}
    return ans; 
} 
int main()
{
	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	cout<<Solve();
	return 0;
}