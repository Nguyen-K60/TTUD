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
	int n, m, k;
	long long res = 0;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		cin >> u[i] >> v[i] >> w[i];
		res += 2 * w[i];
	}
	
	qs(0, m-1);
	
	long long INFTY = res;
	int ru, rv;
	int mask_res;
	for (int mask = 0; mask < (1 << n); mask++) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			cnt += (mask >> i) & 1;
		}
		if (cnt != k + 1) {
			continue;
		}
		for (int i = 1; i <= n; i++) {
			r[i] = -1;
		}
		long long tmp = 0;
		long long mask_e = 0;
		for (int i = 0; i < m; i++) {
			if (((mask >> (u[i] - 1) & 1)) && ((mask >> (v[i] - 1)) & 1)) {
				ru = root(u[i]);
				rv = root(v[i]);
				if (ru != rv) {
					merge(ru, rv);
					tmp += w[i];
					cnt--;
					mask_e += 1 << i;
				}
			}
			if (cnt == 1) {
				break;
			}
		}
		if (cnt == 1) {
			if (tmp < res) {
				mask_res = mask_e;
			}
			res = min(res, tmp);
		}
	}
	if (res == INFTY) {
		cout << -1;
	} else {
//		cout << mask_res << endl;
//		for (int i = 0; i < m; i++) {
//			if (mask_res >> i & 1) {
//				cout << u[i] << ' ' << v[i] << ' ' << w[i] << endl;
//			}
//		}
		cout << res;
	}
	cout << endl;
	return 0;
}
