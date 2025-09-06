#include <bits/stdc++.h>
using namespace std;

vector<int> G[1000003];
int a[200003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		G[a[i]].push_back(i);
	}
	int ans = n + 1;
	for(int i = 1; i <= n; ++i) {
		if(G[a[i]].front() != i)
			continue;
		for(int j = 1; j < G[a[i]].size(); ++j)
			ans = min(ans, G[a[i]][j] - G[a[i]][j - 1] + 1);
	}
	cout << (ans == n + 1? -1: ans) << endl;
	return 0;
}
