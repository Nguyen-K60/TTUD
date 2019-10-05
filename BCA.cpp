#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int n, m, k;
int h[MAX];
int Store[MAX][MAX];
int Conflict[MAX][MAX];
int load[MAX];
int sz[MAX]; 

// Variables
int X[MAX];
int f[MAX];
int f_best;

int input(){
	scanf("%d %d", &n, &m);

	// printf (" Input duration: \n");
	for (int i=1; i <=n; i++)
		scanf("%d", &h[i]);

	// printf (" Input TEACHERS : \n");
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &sz[i]);
		for (int j=1; j<=sz[i]; j++)
			scanf("%d", &Store[i][j]);
	}

	// printf (" Input CONFLICT: \n");
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
			scanf("%d", &Conflict[i][j]);
	}
}

int check(int v, int k)
{
	for(int i = 1; i<=k-1; i++){
		if(Conflict[i][k] && v == X[i]) return 0;
	}
	return 1;
}


void solution(){
	int max  = 0; 
	for (int i = 1; i <= m ; i++)
	{
		if (max < f[i]) max = f[i];
	}

	if(max < f_best){
		f_best = max;
	}
}

void TRY(int k){
	// for (int i=0; i<m; i++){
	// 	for (int j=0; j<n; i++){
	// 		if (Store[i][j] == i)
	// 			load[i] += h[j]; 
	// 	}
	// }

	for (int i = 1; i <= sz[k]; i++){

		int v = Store[k][i];
	
		if(check(v, k))
		{
			X[k] = v;
			f[v] += h[k];	// Accumulate load for teacher v
			if(k == n){
				solution();
			}
			else{
				TRY(k+1);
			}
			f[v] -=  h[k]; // Recover laod when backtracking

		}
	}

}

void solve(){
	f_best = 1000000;
	for ( int i=1; i <= m; i++) f[i] = 0;
	TRY(1);
	if(f_best == 1000000)
		printf("-1");
	else
		printf("%d", f_best);
}
int main()
{
	input();
	
	solve();
}