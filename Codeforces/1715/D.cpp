#include <bits/stdc++.h>
using namespace std;
using U = unsigned;

constexpr const U N = 1e5 + 3;
vector<U> v[N], w[N];
U a[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	U n, m;
	cin >> n >> m;
	memset(a, 0xff, sizeof a);
	for(U i, j, x; m--; ) {
		cin >> i >> j >> x;
		a[i] &= x; a[j] &= x;
		v[i].push_back(j); v[j].push_back(i);
		w[i].push_back(x); w[j].push_back(x);
	}
	for(U i = 1; i <= n; ++i) {
		a[i] = 0;
		for(size_t j = 0; j < v[i].size(); ++j)
			a[i] |= w[i][j] - (i != v[i][j]? a[v[i][j]]: 0);
		cout << a[i] << ' ';
	}
	cout << endl; return 0;
}
