#include <iostream>
using namespace std;
#define max_n 20
#define max_m 15
#define max_b 10
int n,m,b;
int found = 1;
int appear[max_n][max_m];
int L[max_n][max_n];
int load[max_m];// load of reviewers
int f_best = 99999;
int x[max_n][max_b];//reviewer to which course is assigned
void solution()
{
	int max  = 0; 
	for (int i = 1; i <= m ; i++)
	{
		if (max < load[i])
		{
			max = load[i];
		}
	}
	if(max < f_best)
	{
		f_best = max;
	}
	cout<<"solution: "<<endl;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= b; j++)
		{
			cout<<x[i][j]<<" ";
		}
		cout<<endl;
	}
}
int check(int v, int k)
{
	if(appear[k][v] == 1)
	{
		return 0;
	}
	return 1;
}
void TRY(int k,int c)//k la paper
{
	// if(L[k][0] < b)
	// {
	// 	found = 0;
	// 	return;
	// }
	// if(L[k][0] == b)
	// {
	// 	for(int i = 1; i <= b; i++)
	// 	{
	// 		x[k][i] = L[k][i];
	// 		load[L[k][i]]++;
	// 	}
	// }
	
	
		for(int i = c; i >= 1; i--)
		{
			for(int v = 1; v <= L[k][0]; v++)
			{
				if(check(L[k][v],k))
				{
					x[k][i] = L[k][v];
					load[L[k][v]]++;
					appear[k][L[k][v]] = 1;
					if(i == 1)
					{
						if(k < n)
						{
							TRY(k+1,b);
						}
						else
						{
							solution();
						}
					}
					else
					{
						TRY(k,c-1);
					}
					load[L[k][v]]--;
					appear[k][L[k][v]] = 0;
				}				
			}
		}
	

}
int main()
{
	cin>>n>>m>>b;

	for(int i = 1; i <= n; i++)
	{
		cin>>L[i][0];
		if(L[i][0] < b)
		{
			found = 0;
		}
		for(int j = 1; j <= L[i][0]; j++)
		{
			cin>>L[i][j];
		}
		cout<<endl;
	}
	
	if(found == 1)
	{
		TRY(1,b);
		cout<<f_best;
	}
	else
	{
		cout<<-1;
	}
	return 0;
}

