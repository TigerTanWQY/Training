#include <iostream>
#include <vector>
using namespace std;

constexpr const int N = 2e6 + 3;
struct Node
{ int id, x, v; };
vector<Node> q[N];
int a[N], c[N], ans[N];

int lowbit(const int x)
{ return x & -x; }

void modify(int x, const int w = 1) {
	for(; x < N; x += lowbit(x))
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
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 1, L, R, x; i <= m; ++i) {
		cin >> L >> R >> x;
		q[L - 1].push_back({i, x, -1});
		q[R].push_back({i, x, 1});
	}
	for(int i = 1; i <= n; ++i) {
		modify(a[i]);
		for(const auto& j: q[i])
			ans[j.id] += j.v * query(j.x);
	}
	for(int i = 1; i <= m; ++i)
		cout << ans[i] << '\n';
	cout.flush();
	return 0;
}