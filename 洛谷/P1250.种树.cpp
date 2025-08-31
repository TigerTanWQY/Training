#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 3e4 + 1, MN = N + 3;
struct Data {
	int L, R, w;
	bool operator<(const Data& A) const
	{ return R < A.R; }
} a[5003];
int c[MN];

int lb(int x)
{ return x & -x; }

void mdf(int x, int w) {
	for(; x <= N; x += lb(x))
		c[x] += w;
}

int qry(int x) {
	int res = 0;
	for(; x; x -= lb(x))
		res += c[x];
	return res;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= m; ++i)
		cin >> a[i].L >> a[i].R >> a[i].w;
	sort(a + 1, a + m + 1);
	stack<int> stk;
	for(int i = 1; i <= m; ++i) {
		for(int j = a[i - 1].R + 1; j <= a[i].R; ++j)
			stk.push(j);
		int k = qry(a[i].R) - qry(a[i].L - 1);
		for(int j = 1; j <= a[i].w - k; ++j)
		{ mdf(stk.top(), 1); stk.pop(); }
	}
	cout << qry(n) << endl;
	return 0;
}
