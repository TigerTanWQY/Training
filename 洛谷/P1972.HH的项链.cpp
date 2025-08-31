#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

constexpr const int N = 1e6 + 3;
struct Data {
	int L, R, id;
	bool friend operator<(const Data& x, const Data& y)
	{ return x.R < y.R; }
};
array<Data, N> q;
array<int, N> a, ans, vis, c;
int n;

int lowbit(const int x)
{ return x & -x; }

void modify(int x, const int w) {
	for(; x <= n; x += lowbit(x))
		c[x] += w;
}

int query(int x) {
	int res = 0;
	for(; x; x -= lowbit(x))
		res += c[x];
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int m;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	cin >> m;
	for(int i = 1; i <= m; ++i) {
		cin >> q[i].L >> q[i].R;
		q[i].id = i;
	}
	sort(q.begin() + 1, q.begin() + m + 1);
	for(int i = 1, now = 1; i <= m; ++i) {
		for(int j = now; j <= q[i].R; ++j) {
			if(vis[a[j]])
				modify(vis[a[j]], -1);
			modify(j, 1);
			vis[a[j]] = j;
		}
		now = q[i].R + 1;
		ans[q[i].id] = query(q[i].R) - query(q[i].L - 1);
	}
	for(int i = 1; i <= m; ++i)
		cout << ans[i] << '\n';
	cout.flush();
	return 0;
}