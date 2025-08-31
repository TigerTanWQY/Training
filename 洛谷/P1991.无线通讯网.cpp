#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

constexpr const int N = 503;
vector<tuple<double, int, int>> e;
vector<double> ans;
int fa[N], n;

double dis(const pair<int, int>& x, const pair<int, int>& y)
{ return sqrt((x.first - y.first) * (x.first - y.first) + (x.second - y.second) * (x.second - y.second)); }

int fnd(const int x) {
	if(fa[x] != x)
		fa[x] = fnd(fa[x]);
	return fa[x];
}

void Kruskal() {
	sort(e.begin(), e.end());
	for(int i = 0; i <= n; ++i)
		fa[i] = i;
	for(auto [w, u, v]: e) {
		u = fnd(u); v = fnd(v);
		if(u != v) {
			fa[u] = v;
			ans.push_back(w);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int k;
	cin >> k >> n;
	vector<pair<int, int>> v{{0, 0}};
	for(int i = 1, x, y; i <= n; ++i) {
		cin >> x >> y;
		v.push_back({x, y});
		for(int j = 1; j < i; ++j) {
			const double w = dis(v[i], v[j]);
			e.push_back({w, i, j});
			e.push_back({w, j, i});
		}
	}
	Kruskal();
	sort(ans.begin(), ans.end());
	cout << fixed << setprecision(2) << (k >= 2? ans[n - k - 1]: ans.back()) << endl;
	return 0;
}