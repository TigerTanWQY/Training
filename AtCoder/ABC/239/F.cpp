#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 2e5 + 3;
vector<int> G[N];
int a[N];
#include <atcoder/dsu>

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	atcoder::dsu d(n);
	for(int i = 0, u, v; i < m; ++i) {
		cin >> u >> v;
		--a[--u]; --a[--v];
		d.merge(u, v);
	}
	for(int i = 0; i < n; ++i)
		if(a[i] < 0) {
			cout << "-1" << endl;
			return 0;
		} else
			while(a[i]--)
				G[d.leader(i)].push_back(i);
	vector<vector<int>> c2;
	vector<int> c1;
	for(int i = 0; i < n; ++i)
		if(G[i].size() == 1)
			c1.push_back(G[i][0]);
		else if(G[i].size() > 1)
			c2.push_back(G[i]);
	vector<pair<int, int>> ans;
	for(const auto& v: c2) {
		for(int i = 0; i < (int)/*! (int) <- Important !*/v.size() - 1; ++i) {
			if(c1.empty()) {
				cout << "-1" << endl;
				return 0;
			}
			d.merge(v[i], c1.back());
			ans.push_back({v[i], c1.back()});
			c1.pop_back();
		}
		c1.push_back(v.back());
	}
	if(c1.size() != 2) {
		cout << "-1" << endl;
		return 0;
	}
	d.merge(c1[0], c1[1]);
	ans.push_back({c1[0], c1[1]});
	if(d.size(0) != n)
		cout << "-1\n";
	else
		for(const auto& [u, v]: ans)
			cout << u + 1 << ' ' << v + 1 << '\n';
	cout.flush();
	return 0;
}
