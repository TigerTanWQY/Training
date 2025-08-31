#include <bits/stdc++.h>
using namespace std;
using TI = tuple<int, int, int>;

constexpr const int N = 1e5 + 3;
vector<TI> e;
TI a[N];
int fa[N], n;

int fnd(const int x) {
	if(fa[x] != x)
		fa[x] = fnd(fa[x]);
	return fa[x];
}

auto Kruskal() {
	sort(e.begin(), e.end());
	e.erase(unique(e.begin(), e.end()), e.cend());
	for(int i = 0; i <= n; ++i)
		fa[i] = i;
	long long res = 0;
	int cnt = 0;
	for(auto [w, u, v]: e) {
		u = fnd(u); v = fnd(v);
		if(u == v)
			continue;
		fa[v] = u;
		res += w;
		if(++cnt == n - 1)
			break;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for(int i = 1, x, y; i <= n; ++i) {
		cin >> x >> y;
		a[i] = {x, y, i};
	}
	sort(a + 1, a + n + 1, [](const TI& A, const TI& B)
		{ return get<0>(A) < get<0>(B); });
	for(int i = 1; i < n; ++i)
		e.push_back({get<0>(a[i + 1]) - get<0>(a[i]), get<2>(a[i]), get<2>(a[i + 1])});
	sort(a + 1, a + n + 1, [](const TI& A, const TI& B)
		{ return get<1>(A) < get<1>(B); });
	for(int i = 1; i < n; ++i)
		e.push_back({get<1>(a[i + 1]) - get<1>(a[i]), get<2>(a[i]), get<2>(a[i + 1])});
	cout << Kruskal() << endl;
	return 0;
}