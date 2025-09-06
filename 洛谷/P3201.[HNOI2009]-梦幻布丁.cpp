#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1e5 + 3, M = 1e6 + 3;
int a[N], sz[M], st[M], f[M], hd[M], nxt[N], ans = 0;

void mrge(int x, int y) {
	for(int i = hd[x]; i; i = nxt[i])
		ans -= (a[i - 1] == y) + (a[i + 1] == y);
	for(int i = hd[x]; i; i = nxt[i])
		a[i] = y;
	nxt[st[x]] = hd[y]; hd[y] = hd[x]; sz[y] += sz[x];
	hd[x] = st[x] = sz[x] = 0;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		f[a[i]] = a[i];
		ans += (a[i] != a[i - 1]);
		if(!hd[a[i]])
			st[a[i]] = i;
		++sz[a[i]]; nxt[i] = hd[a[i]]; hd[a[i]]=i;
	}
	for(int op, x, y; m--; ) {
		cin >> op;
		if(op == 2)
			cout << ans << '\n';
		else {
			cin >> x >> y;
			if(x == y)
				continue;
			if(sz[f[x]] > sz[f[y]])
				swap(f[x], f[y]);
			if(!sz[f[x]])
				continue;
			mrge(f[x], f[y]);
		}
	}
	cout.flush(); return 0;
}
