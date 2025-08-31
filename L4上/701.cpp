#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
#define L first
#define R second

const int N = 100003;
vector<int> G[N];
pair<int, int> BT[N];

void mkTree(const int& u) {
	sort(G[u].begin(), G[u].end());
	int m = G[u].size();
	if(m) {
		BT[u].L = G[u][0];
		for(int i = 1; i < m; ++i)
			BT[G[u][i - 1]].R = G[u][i];
		for(const auto& v: G[u])
			mkTree(v);
	}
}

void TLR(const int& u) {
	cout << u << ' ';
	if(BT[u].L)
		TLR(BT[u].L);
	if(BT[u].R)
		TLR(BT[u].R);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int _ = 1, u, v; _ < n; ++_) {
		cin >> u >> v;
		G[u].push_back(v);
	}
	mkTree(1);
	TLR(1);
	return 0;
}