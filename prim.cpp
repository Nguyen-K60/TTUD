#include <bits/stdc++.h>

using namespace std;

struct OutEdge {
	int v;
	long long w;
};

const int NMAX = 1E6 + 5;
const int INF = 1E9;

vector<OutEdge> e[NMAX];
int heap[NMAX];
int nheap = 0;
long long d[NMAX];
int iheap[NMAX];

void upHeap(int ic) {
	if (ic <= 1) {
		return;
	}
	
	int ip = ic / 2;
	int c = heap[ic];
	int p = heap[ip];
	
	if (d[c] < d[p]) {
		swap(heap[ic], heap[ip]);
		iheap[heap[ic]] = ic;
		iheap[heap[ip]] = ip;
		upHeap(ip);
	}
}

void downHeap(int ip) {
	if (ip * 2 > nheap) {
		return;
	}
	
	int p = heap[ip];
	int ic = ip * 2;
	int c = heap[ic];
	if (ic + 1 <= nheap) {
		int cc = heap[ic + 1];
		if (d[c] > d[cc]) {
			ic = ic + 1;
			c = cc;
		}
	}
	
	if (d[p] > d[c]) {
		swap(heap[ip], heap[ic]);
		iheap[heap[ic]] = ic;
		iheap[heap[ip]] = ip;
		downHeap(ic);
	}
}

void pushHeap(int u) {
	if (iheap[u] != 0) {
		upHeap(iheap[u]);
		return;
	}
	nheap++;
	heap[nheap] = u;
	iheap[u] = nheap;
	upHeap(nheap);
}

int popHeap() {
	int v = heap[1];
	heap[1]	= heap[nheap];
	nheap--;
	downHeap(1);
	return v;
}

int main() {
	int n, m, u, v;
	long long w;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		e[u].push_back({.v = v, .w = w});
		e[v].push_back({.v = u, .w = w});
	}
	
	memset(iheap, 0, sizeof(iheap));
	
	for (int i = 1; i <= n; i++) {
		d[i] = INF;
	}
	d[1] = 0;
	pushHeap(1);
	
	long long res = 0;
	
	while (nheap > 0) {
		u = popHeap();
		res += d[u];
		d[u] = 0;		// Dinh u da nam trong CK
		for (vector<OutEdge>::iterator it = e[u].begin(); it != e[u].end(); it++) {
			v = it->v;
			w = it->w;
			if (w < d[v]) {
				d[v] = w;
				pushHeap(v);
			}
		}
	}
	
	cout << res << endl;
}
