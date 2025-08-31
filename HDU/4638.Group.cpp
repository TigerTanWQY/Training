#include <iostream>
#include <algorithm>
using namespace std;

constexpr const int N = 1e5 + 3;
struct Node {
	int L, R, id;
	bool operator<(const Node& A) const
	{ return R < A.R; }
} q[N];
int a[N], id[N], c[N], ans[N], n;

int lb(int x)
{ return x & -x; }

void mdf(int x, int w) {
	for(; x <= n; x += lb(x))
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
	int _T;
	cin >> _T;
	for(int m; _T--; ) {
		cin >> n >> m;
		for(int i = 1; i <= n; ++i) {
			cin >> a[i];
			id[a[i]] = i;
		}
		for(int i = 0; i < m; ++i) {
			cin >> q[i].L >> q[i].R;
			q[i].id = i;
		}
		sort(q, q + m);
		for(int i = 1, j = 0; i <= n; ++i) {
			mdf(i, 1);
			if(a[i] < n && id[a[i] + 1] < i)
				mdf(id[a[i] + 1], -1);
			if(a[i] > 1 && id[a[i] - 1] < i)
				mdf(id[a[i] - 1], -1);
			for(; j < m && q[j].R == i; ++j)
				ans[q[j].id] = qry(q[j].R) - qry(q[j].L - 1);
		}
		for(int i = 0; i < m; ++i)
			cout << ans[i] << '\n';
		fill(c, c + n + 1, 0);
	}
	cout.flush(); return 0;
}
