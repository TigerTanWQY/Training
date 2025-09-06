#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int N = 2e6 + 3;
struct
{ int op, L, R, c, t; }
qry[N];
int n, m;
LL ans[N];
struct {
	int tot, a[N], nxt[N];
	void mdf(int L, int R) {
		for(int lst = 0, i = L; i <= R; lst = i, i = nxt[i]) {
			if(a[i] == 0)
				++tot;
			a[i] = 1;
			if(lst)
				nxt[lst] = nxt[R];
		}
	}
	int query(int L, int R) {
		int res = 0;
		for(int i = L; i <= R; i = nxt[i])
			res += !a[i];
		return R - L + 1 - res;
	}
} a, b;

void mdf(int p) {
	int op = qry[p].op, L = qry[p].L, R = qry[p].R, c = qry[p].c;
	if(op == 1) {
		int cntR = a.query(L, R), cnt = b.tot;
		ans[c] += 1LL * (R - L + 1 - cntR) * (m - cnt);
		a.mdf(L, R);
	} else {
		int cntR = a.tot, cnt = b.query(L, R);
		ans[c] += 1LL * (n - cntR) * (R - L + 1 - cnt);
		b.mdf(L, R);
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int k, q;
	cin >> n >> m >> k >> q;
	for(int i = 1; i <= q; ++i)
		cin >> qry[i].op >> qry[i].L >> qry[i].R >> qry[i].c >> qry[i].t;
	for(int i = 1; i <= n; ++i)
		a.nxt[i] = i + 1;
	for(int i = 1; i <= m; ++i)
		b.nxt[i] = i + 1;
	for(int i = q; i; --i)
		if(qry[i].t)
			mdf(i);
	for(int i = 1; i <= q; ++i)
		if(!qry[i].t)
			mdf(i);
	for(int i = 1; i <= k; ++i)
		cout << ans[i] << ' ';
	cout << endl; return 0;
}
