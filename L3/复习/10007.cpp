#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
using LL = long long;

constexpr const int N = 3003;
vector<int> G[N];
bitset<N> vis;
int x[N], y[N], r[N], S, T;

LL dist(const LL x1, const LL y1, const LL x2, const LL y2)
{ return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2); }

bool dfs(const int u) {
	vis[u] = true;
	if(u == T)
		return true;
	for(const auto &v: G[u])
		if(!vis[v])
			if(dfs(v))
				return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, sx, sy, tx, ty;
	cin >> n >> sx >> sy >> tx >> ty;
	for(int i = 1; i <= n; ++i)
		cin >> x[i] >> y[i] >> r[i];
	for(int i = 1; i <= n; ++i)
		for(int j = i + 1; j <= n; ++j) {
			LL d = dist(x[i], y[i], x[j], y[j]);
			if(d <= 1LL * (r[i] + r[j]) * (r[i] + r[j]) && 1LL * (r[i] - r[j]) * (r[i] - r[j]) <= d) {
				G[i].push_back(j);
				G[j].push_back(i);
			}
		}
	for(int i = 1; i <= n; ++i) {
		if(dist(x[i], y[i], sx, sy) == 1LL * r[i] * r[i])
			S = i;
		if(dist(x[i], y[i], tx, ty) == 1LL * r[i] * r[i])
			T = i;
	}
	if(dfs(S))
		cout << "Yes";
	else
		cout << "No";
	cout << endl;
	return 0;
}