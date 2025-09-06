#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1e5 + 3;
struct Node {
	int L, R, val, id;
	bool operator<(const Node& A) const
	{ return val < A.val; }
} a[N], q[N];
int c[N], ans[N], n;

int lb(int x)
{ return x & -x; }

void upd(int x) {
	for(; x <= n; x += lb(x))
		++c[x];
}

int qry(int x) {
	int res = 0;
	for(; x; x -= lb(x))
		res += c[x];
	return res;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int _T;
	cin >> _T;
	for(int _id = 1, m; _id <= _T; cout.put('\n'), ++_id) {
		cin >> n >> m;
		for(int i = 1; i <= n; ++i) {
			cin >> a[i].val;
			a[i].id = i;
		}
		sort(a + 1, a + n + 1);
		for(int i = 1; i <= m; ++i) {
			cin >> q[i].L >> q[i].R >> q[i].val;
			q[i].id = i;
		}
		sort(q + 1, q + m + 1);
		for(int i = 1, k = 1; i <= m; ++i) {
			for(; k <= m && a[k].val <= q[i].val; ++k)
				upd(a[k].id);
			ans[q[i].id] = qry(q[i].R + 1) - qry(q[i].L);
		}
		cout << "Case " << _id << ":\n";
		for(int i = 1; i <= m; ++i)
			cout << ans[i] << '\n';
		for(int i = 1; i <= n; ++i)
			c[i] = 0;
	}
	cout.flush(); return 0;
}
