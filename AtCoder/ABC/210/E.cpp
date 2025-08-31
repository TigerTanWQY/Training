#include <iostream>
#include <vector>
#include <algorithm>
#include <atcoder/dsu>
using namespace std;

struct Node {
	int u, v, w;
	bool operator<(const Node& A) const
	{ return w < A.w; }
};
vector<Node> e;
int n, k = 0;
long long ans = 0;

bool Kruskal() {
	int cnt = 0;
	sort(e.begin(), e.end());
	atcoder::dsu fa(n + 1);
	for(const auto& p: e) {
		if(!fa.same(p.u, p.v)) {
			fa.merge(p.u, p.v);
			ans += p.w;
			++cnt;
		}
	}
	return cnt == n - 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int m;
	cin >> n >> m;
	vector<int> a(m + 1), b(m + 1);
	for(int i = 1; i <= m; ++i)
		cin >> a[i] >> b[i];
	for(int u = 1; u <= n; ++u)
		for(int i = 1; i <= m; ++i)
			e.push_back({u, (u + a[i]) % n? (u + a[i]) % n: n, b[i]});
	if(Kruskal())
		cout << ans;
	else
		cout << "-1";
	return 0;
}