#include <iostream>
#include <bitset>
#include <algorithm>
using namespace std;

constexpr const int N = 2'003, M = 50'003;
struct Node {
	int u, v, w;
	Node() noexcept = default;
	Node(const int& _u, const int& _v, const int _w) noexcept
	: u(_u), v(_v), w(_w)
	{ }
	bool operator<(const Node& x) const {
		if(u != x.u)
			return u < x.u;
		else if(v != x.v)
			return v < x.v;
		else
			return w < x.w;
	}
} p[M];
bitset<N> c[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= m; ++i)
		cin >> p[i].u >> p[i].v >> p[i].w;
	sort(p + 1, p + m + 1);
	int ans = 0;
	for(int a = 1; a <= n; ++a) {
//		for(int i = 1; i <= m; ++i)
//			if(p[i].u == a)
//				c[p[i].v][p[i].w] = true;
		auto Lit = lower_bound(p + 1, p + m + 1, Node{a, 0, 0}), Rit = upper_bound(p + 1, p + m + 1, Node{a, 0, 0}) - 1;
		for(int i = 1; i <= m; ++i)
			if(c[p[i].u][p[i].v] && c[p[i].u][p[i].w] && c[p[i].v][p[i].w])
				++ans;
		for(int i = 1; i <= m; ++i)
			if(p[i].u == a)
				c[p[i].v][p[i].w] = false;
	}
	cout << ans << endl;
	return 0;
}