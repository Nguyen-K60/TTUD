#include <iostream>
#include <vector>
#define MAX 100001
#define MAX_M 200002
using namespace std;
int N, M, K;
vector<int> A[MAX], c[MAX];
int S[MAX];
int inS[MAX];
int d[MAX], node[MAX], idx[MAX], sH;
int s;
int t;
int maxD = 0;
bool Fixed[MAX];
void swap(int i, int j)
{
	int tmp = node[i]; node[i] = node[j]; node[j] = tmp;
	idx[node[i]] = i; idx[node[j]] = j;
}
void upHeap(int i)
{
	if (i == 0) return;
	while (i>0)
	{
		int pi = (i - 1) / 2;
		if (d[node[i]]<d[node[pi]])
		{
			swap(i, pi);
		}
		else break;
		i = pi;
	}
}
void downHeap(int i)
{
 
	int L = 2 * i + 1;
	int R = 2 * i + 2;
	int maxldx = i;
	if (L < sH && d[node[L]] < d[node[maxldx]]) maxldx = L;
	if (R < sH && d[node[R]] < d[node[maxldx]]) maxldx = R;
	if (maxldx != i)
	{
 
		swap(i, maxldx);
		downHeap(maxldx);
	}
}
void insert(int v, int k)
{
	d[v] = k;
	node[sH] = v;
	idx[node[sH]] = sH;
	upHeap(sH);
	sH++;
}
int inHeap(int v)
{
	return idx[v] >= 0;
}
void updateKey(int v, int k)
{
	if (d[v] > k)
	{
		d[v] = k;
		upHeap(idx[v]);
	}
	else
	{
		d[v] = k;
		downHeap(idx[v]);
	}
}
int deleteMin()
{
	int sel_node = node[0];
	swap(0, sH - 1);
	sH--;
	downHeap(0);
	return sel_node;
}
void solve(int a, int b)
{
	//cout<<"solve "<<a<<", "<<b<<endl;
	s = a;
	t = b;
	sH = 0;
	for (int v = 1; v <= N ; v++)
	{
		Fixed[v] = false;
		idx[v] = -1;
	}
	d[s] = 0;
	Fixed[s] = true;
	for (int i = 0; i < A[s].size(); i++)
	{
		int v = A[s][i];
		if(inS[v] == 0)
		{
			//continue;
		}
		insert(v, c[s][i]);
	}
	while (sH>0)
	{
		int u = deleteMin();
		Fixed[u] = true;
		for (int i = 0; i < A[u].size(); i++)
		{
			int v = A[u][i];
			if(inS[v] == 0)
			{
				//continue;
			}
			if (Fixed[v]) continue;
			if (!inHeap(v))
			{
				int w = d[u] + c[u][i];
				insert(v, w);
			}
			else
			{
				if (d[v] > d[u] + c[u][i])
				{
					updateKey(v, d[u] + c[u][i]);
					//cout<<"d "<<v<<" = "<<" d "<<u<<" + "<<c[u][i]<<endl;
				}
			}
		}
	}
	int rs = d[t];
	if (!Fixed[t]) rs = -1;
	if(rs > maxD)
	{
		maxD = rs;
	}
}
void Solve()
{
	for(int i = 1; i < K; i++)
	{
		for(int j = i+1; j <= K; j++)
		{
			solve(S[i], S[j]);
		}
	}
	cout<<maxD;
}
int main()
{
	cin>>N>>M;
	for(int i = 1; i <= M; i++)
	{
		int u, v, w;
		cin>>u>>v>>w;
		A[u].push_back(v);
		A[v].push_back(u);
		c[u].push_back(w);
		c[v].push_back(w);
	}
	cin>>K;
	for(int i = 0; i <= N; i++)
	{
		inS[i] = 0;
	}
	for(int i = 1; i <= K; i++)
	{
		int a;
		cin>>a;
		S[i] = a;
		inS[a] = 1;
	}
	Solve();
	return 0;
}