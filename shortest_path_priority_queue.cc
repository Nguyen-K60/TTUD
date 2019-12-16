//#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#define MAX 100001
#define INF 1000000
using namespace std;
vector<int> A[MAX], c[MAX];
int n, m, s, t;
int d[MAX], node[MAX], idx[MAX], sH;
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
void solve()
{
	sH = 0;
	for (int v = 1; v <=n ; v++)
	{
		Fixed[v] = false;
		idx[v] = -1;
	}
	d[s] = 0;
	Fixed[s] = true;
	for (int i = 0; i < A[s].size(); i++)
	{
		int v = A[s][i];
		insert(v, c[s][i]);
	}
	while (sH>0)
	{
		int u = deleteMin();
		Fixed[u] = true;
		for (int i = 0; i < A[u].size(); i++)
		{
			int v = A[u][i];
			if (Fixed[v]) continue;
			if (!inHeap(v))
			{
				int w = d[u] + c[u][i];
				insert(v, w);
			}
			else
			{
				if (d[v] > d[u] + c[u][i])
					updateKey(v, d[u] + c[u][i]);
			}
		}
	}
	int rs = d[t];
	if (!Fixed[t]) rs = -1;
	cout << rs;
}
void input()
{
	cin >> n >> m;
	int u, v, w;
	
	for (int i = 1; i <= m; i++)
	{
		cin >> u >> v >> w;
		//if (u == s) d[v] = w;
		A[u].push_back(v);
		c[u].push_back(w);
 
	}
	cin >> s >> t;
 
}
int main()
{
//	freopen("input.txt", "r", stdin);
	input();
	solve();
	return 0;
}