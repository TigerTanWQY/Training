#include <iostream>
using namespace std;

int fa[20003];

int fnd(const int x) {
	if(fa[x] != x)
		fa[x] = fnd(fa[x]);
	return fa[x];
}

void mrge(int x, int y) {
	x = fnd(x); y = fnd(y);
	if(x == y)
		return;
	fa[y] = x;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		fa[i] = i;
	for(int u, v; m--; ) {
		cin >> u >> v;
		mrge(u, v);
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i)
		if(fa[i] == i)
			++ans;
	cout << ans << endl;
	return 0;
}