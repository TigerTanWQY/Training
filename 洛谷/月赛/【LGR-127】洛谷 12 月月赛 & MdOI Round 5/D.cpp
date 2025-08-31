#include <iostream>
#include <utility>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

const int N = 1'200'003;
vector<pair<int, int>> e;
bitset<N> vis;

void dfs(const int& u) {
	;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	if(n & 1) {
		cout << "-1";
		return 0;
	}
	for(int u = 1; u < n; ++u) {
		e.push_back({u, u + 1});
		e.push_back({u + 1, u});
	}
	e.push_back({n, 1});
	e.push_back({1, n});
	for(int _ = 3, u, v; _ < n; ++_) {
		cin >> u >> v;
		e.push_back({u, v});
		e.push_back({v, u});
	}
	sort(e.begin(), e.end());
	cout.flush();
	return 0;
}