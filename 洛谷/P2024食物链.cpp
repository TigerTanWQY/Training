#include <iostream>
#include <algorithm>
using namespace std;

int fa[150003];

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

bool same(const int& x, const int& y)
{ return fnd(x) == fnd(y); }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	init(3 * n);
	int ans = 0;
	for(int op, x, y; k--; ) {
		cin >> op >> x >> y;
		if(x > n || y > n)
			++ans;
		else if(op == 1)
			if(same(x, y + n) || same(x + n, y))
				++ans;
			else {
				mrge(x, y);
				mrge(x + n, y + n);
				mrge(x + n + n, y + n + n);
			}
		else
			if(x == y || same(x, y) || same(x, y + n))
				++ans;
			else {
				mrge(x + n, y);
				mrge(x + n + n, y + n);
				mrge(x, y + n + n);
			}
	}
	cout << ans;
	return 0;
}