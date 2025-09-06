#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 2e5 + 3;
vector<int> G[N];
int A[N * 2];

int main() {
	int T;
	cin >> T;
	for(int n; T--; cout.put('\n')) {
		cin >> n;
		for(int i = 0; i < n * 2; ++i)
			cin >> A[i];
		for(int i = 0; i < n * 2; ++i)
			G[A[i]].push_back(i);
		set<pair<int, int>> ans;
		for(int i = 0; i + 1 < n * 2; ++i) {
			int a = A[i], b = A[i + 1];
			if(G[a][0] + 1 == G[a][1])
				continue;
			if(G[b][0] + 1 == G[b][1])
				continue;
			vector<int> v{G[a][0], G[a][1], G[b][0], G[b][1]};
			sort(begin(v), end(v));
			if(v[0] + 1 == v[1] && v[2] + 1 == v[3])
				ans.insert(minmax(a, b));
		}
		cout << ans.size();
		for(int i = 0; i <= n; ++i)
			G[i].clear();
	}
	cout.flush(); return 0;
}
