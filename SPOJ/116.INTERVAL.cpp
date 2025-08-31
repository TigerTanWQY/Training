#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int N = 5e4 + 1, MN = N + 3;
struct Data {
	int L, R, w;
	bool operator<(const Data& A) const
	{ return R < A.R; }
} a[MN];
LL c[MN];

int lb(int x)
{ return x & -x; }

void mdf(int x, int w) {
	for(; x <= N; x += lb(x))
		c[x] += w;
}

LL qry(int x) {
	LL res = 0;
	for(; x > 0; x -= lb(x))
		res += c[x];
	return res;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int _T;
	cin >> _T;
	for(int n; _T--; memset(c, 0, sizeof(c))) {
		cin >> n;
		for(int i = 1; i <= n; ++i) {
			cin >> a[i].L >> a[i].R >> a[i].w;
			++a[i].L; ++a[i].R;
		}
		sort(a + 1, a + n + 1);
		stack<int> stk;
		for(int i = 1; i <= n; ++i) {
			for(int j = a[i - 1].R + 1; j <= a[i].R; ++j)
				stk.push(j);
			int k = qry(a[i].R) - qry(a[i].L - 1);
			for(int j = 1; j <= a[i].w - k; ++j)
			{ mdf(stk.top(), 1); stk.pop(); }
		}
		cout << qry(N);
		if(_T)
			cout.put('\n');
	}
	cout.flush(); return 0;
}