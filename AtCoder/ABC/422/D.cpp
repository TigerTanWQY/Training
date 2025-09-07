#include <bits/stdc++.h>
using namespace std;
using LL = long long;

vector<LL> a;

void dfs(int u, LL w) {
	if(u == 0) {
		cout << w << ' ';
		return;
	}
	LL L, R;
	if(w == a[u])
		if(!(a[u] & 1)) {
			L = a[u-1];
			R = a[u-1];
		} else {
			L = a[u-1];
			R = a[u-1] + 1;
		}
	else
		if(!((a[u] + 1) & 1)) {
			L = a[u-1] + 1;
			R = a[u-1] + 1;
		} else {
			L = a[u-1];
			R = a[u-1] + 1;
		}
	dfs(u - 1, L);
	dfs(u - 1, R);
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n; LL k;
	cin >> n >> k;
	LL m = 1LL << n;
	if(k % m == 0) {
		cout.put('0').put('\n');
		for(LL i = 0; i < m; ++i)
			cout << k / m << ' ';
	} else {
		cout.put('1').put('\n');
		a.resize(n + 1);
		a[n] = k;
		for(int i = n - 1; ~i; --i)
			a[i] = a[i + 1] / 2;
		dfs(n, k);
	}
	cout << endl; return 0;
}
