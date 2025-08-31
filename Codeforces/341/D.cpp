#include<bits/stdc++.h>
using namespace std;
using LL = long long;

LL c[2][2][1003][1003];
int n;

auto lb = [](int x) { return x & -x; };

void mdf(int x, int y, LL w) {
	for(int i = x; i <= n; i += lb(i))
		for(int j = y; j <= n; j += lb(j))
			c[x & 1][y & 1][i][j] ^= w;
}

LL qry(int x, int y) {
	LL res = 0;
	for(int i = x; i; i -= lb(i))
		for(int j = y; j; j -= lb(j))
			res ^= c[x & 1][y & 1][i][j];
	return res;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int _q;
	cin >> n >> _q;
	for(int op, x1, y1, x2, y2; _q-- && cin >> op >> x1 >> y1 >> x2 >> y2; ) {
		if(op == 1)
			cout << (qry(x2, y2) ^ qry(x2, y1 - 1) ^
				qry(x1 - 1, y2) ^ qry(x1 - 1, y1 - 1)) << '\n';
		else {
			LL w;
			cin >> w;
			mdf(x1, y1, w); mdf(x1, y2 + 1, w);
			mdf(x2 + 1, y1, w); mdf(x2 + 1, y2 + 1, w);
		}
	}
	cout.flush(); return 0;
}
