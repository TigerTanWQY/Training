#include <iostream>
#include <utility>
#include <bitset>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using LL = long long;

constexpr const LL INF = 0x3f3f3f3f3f3f3f3f;
constexpr const int N = 200'003;
bitset<N> vis;
int a[N], fa[N], p[N];
LL ans, cnt1[N], cnt0[N];

int fnd(const int x) {
	if(fa[x] != x)
		fa[x] = fnd(fa[x]);
	return fa[x];
}

void mrge(int x, int y) {
	x = fnd(x);
	y = fnd(y);
	ans += cnt1[y] * cnt0[x];
	cnt1[y] += cnt1[x];
	cnt0[y] += cnt0[x];
	fa[x] = y;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	p[0] = -1;
	for(int i = 1; i < n; ++i) {
		cin >> p[i];
		--p[i];
	}
	__gnu_pbds::priority_queue<pair<double, int>, greater<pair<double, int>>> q;
	for(int i = 0; i < n; ++i) {
		fa[i] = i;
		cin >> a[i];
		if(a[i])
			++cnt1[i];
		else
			++cnt0[i];
		q.push({(cnt0[i] == 0? INF: 1.0 * cnt1[i] / (1.0 * cnt0[i])), i});
	}
	while(!q.empty()) {
		int u = q.top().second;
		q.pop();
		if(vis[u])
			continue;
		vis[u] = true;
		if(~p[u]) {
			int v = fnd(p[u]);
			mrge(u, v);
			q.push({(cnt0[v] == 0? INF: 1.0 * cnt1[v] / (1.0 * cnt0[v])), v});
		}
	}
	cout << ans;
	cout.flush();
	return 0;
}