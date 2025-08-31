#include <iostream>
using namespace std;

int fa[2003];

void init(const int& n) {
	for(int i = 1; i <= n; ++i)
		fa[i] = i;
}

int fnd(const int& x) {
	if(fa[x] != x)
		fa[x] = fnd(fa[x]);
	return fa[x];
}

void mrge(const int& x, const int& y) {
	int fx = fnd(x), fy = fnd(y);
	if(fx != fy)
		fa[fx] = fy;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	init(2 * n);
	for(char op; m--; ) {
		int p, q;
		cin >> op >> p >> q;
		if(op == 'F')
			mrge(p, q);
		else {
			mrge(p + n, q);
			mrge(q + n, p);
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i)
		if(fnd(i) == i)
			++ans;
	cout << ans;
	return 0;
}