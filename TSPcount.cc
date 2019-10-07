#include <stdio.h>
#include <stdlib.h>
int n,m, c[20][20], cmin = 100000,P[20];
int f = 0,fmin = 100000;
int s[20];
int count = 0;
void input(){
	int i,j;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&c[i][j]);
			if(cmin>c[i][j] && c[i][j]!=0) cmin = c[i][j];
		}
	}
	s[1] = 1;
}
void solution(int k){
	if(f+c[s[n]][s[1]]<=m){
		count++;
	}
}
 
void TRY(int k){
	for(int i=2;i<=n;i++){
		if(!P[i]){
			s[k] = i;
			P[i] = 1;
			f = f + c[s[k-1]][s[k]];
			int gg = f + (n-k+1)*cmin;
			if(k==n) solution(k);
			if(gg<=m){
				TRY(k+1);
			}
				P[i] = 0;
				f = f - c[s[k-1]][s[k]];
			}
		}
	}
 
int main(void){
	input();
	TRY(2);
	printf("%d",count);
	return 0;
}