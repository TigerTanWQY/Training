#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 100003;
vector<pair<int, int>> G[N];
int a[N], w[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 1; i <= n; ++i)
		cin >> w[i];
	for(int i = 1; i <= n; ++i)
		G[a[i]].push_back({w[i], i});
	int ans = 0;
	for(int i = 1; i <= n; ++i)
		if(G[i].size() > 1) {
			sort(G[i].begin(), G[i].end());
			for(int j = 0; j < G[i].size() - 1; ++j)
				ans += G[i][j].first;
		}
	cout << ans << endl;
	return 0;
}