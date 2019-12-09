#include <bits/stdc++.h>

using namespace std;

const int NMAX = 1E6 + 5;

int u[NMAX], v[NMAX], r[NMAX];
long long w[NMAX];

void qs(int l, int r) {
	if (l >= r) return;
	int i = l, j = r, x = w[(i+j)/2];
	do {
		while (w[i] < x) i++;
		while (w[j] > x) j--;
		if (i <= j) {
			swap(w[i], w[j]);
			swap(u[i], u[j]);
			swap(v[i], v[j]);
			i++;
			j--;
		}
	} while (i <= j);
	
	qs(l, j);
	qs(i, r);
}

int root(int x) {
	if (r[x] < 0) {
		return x;
	} else {
		r[x] = root(r[x]);
		return r[x];
	}
}

int merge(int u, int v) {
	if (r[v] < r[u]) {
		swap(u, v);
	}
	r[u] += r[v];
	r[v] = u;
}

int main() {
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> u[i] >> v[i] >> w[i];
	}
	
	qs(0, m-1);
	
	for (int i = 1; i <= n; i++) {
		r[i] = -1;
	}
	
	long long res = 0;
	int ru, rv;
	for (int i = 0; i < m; i++) {
		ru = root(u[i]);
		rv = root(v[i]);
		if (ru != rv) {
			merge(ru, rv);
			res += w[i];
		}
	}
	cout << res << endl;
}
