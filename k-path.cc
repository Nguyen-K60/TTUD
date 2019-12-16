#include <bits/stdc++.h>
#define MAX_N 51
#define INF 999999
using namespace std;
int n, m, k, q;
vector<int> A[MAX_N], w1[MAX_N], w2[MAX_N];
int minimum(int a, int b) 
{
   return (a<b)?a:b;
}

int shortKEdgePath(int u, int v, int edge) 
{
   if (edge == 0 && u == v)    //when 0 edge, no path is present            
      return 0;
   if (edge == 1 && cost[u][v] != INF)    //when only one edge, and (u,v) is valid
      return cost[u][v];
   if (edge <= 0)    //when edge is -ve, there are infinity solution        
      return INF;
   int shortPath = INF;

   for (int i = 0; i < A[u].size(); i++) 
   {    //for all vertices i, adjacent to u
   	int next = A[i];
      if (cost[u][v] != INF && u != next && v != next) 
      {
         int tempRes = shortKEdgePath(next, v, edge-1);
         if (tempRes != INF)
            shortPath = minimum(shortPath, cost[u][next] + tempRes);
      }
   }
   return shortPath;
}

int main()
{
	cin>>n>>m>>k>>q;
	for(int i = 1; i <= m; i++)
	{
		int u, v, a, b;
		A[u].push_back(v);
		A[v].push_back(u);
		w1[u].push_back(a);
		w1[v].push_back(a);
		w2[u].push_back(b);
		w2[v].push_back(b);
	}
	Solve();
	return 0;
}