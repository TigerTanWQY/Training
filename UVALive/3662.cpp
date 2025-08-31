#include <iostream>
#include <cmath>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

constexpr const int N = 1e5 + 3;
vector<tuple<int, int, int>> e;
pair<int, int> a[N];
int fa[N], n;
long long ans = 0;

int dis(const pair<int, int>& A, const pair<int, int>& B)
{ return abs(A.first - B.first) + abs(A.second - B.second); }

int fnd(const int x) {
	if(fa[x] != x)
		fa[x] = fnd(fa[x]);
	return fa[x];
}

inline void Kruskal() {
	sort(e.begin(), e.end());
	for(int i = 0; i <= n; ++i)
		fa[i] = i;
	for(auto [w, u, v]: e) {
		u = fnd(u); v = fnd(v);
		if(u == v)
			continue;
		fa[v] = u;
		ans += w;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for(int _T = 1; cin >> n && n; ++_T) {
		for(int i = 1; i <= n; ++i)
			cin >> a[i].first >> a[i].second;
		sort(a + 1, a + n + 1);
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j < i; ++j) {
				e.push_back({dis(a[i], a[j]), i, j});
				e.push_back({dis(a[i], a[j]), j, i});
			}
		Kruskal();
		cout << "Case " << _T << " Total Weight = " << ans << '\n';
		e.clear();
		ans = 0;
	}
	cout.flush();
	return 0;
}