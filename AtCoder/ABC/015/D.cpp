#include <bits/stdc++.h>
using namespace std;

pair<int, int> a[53];
int f[53][10003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, V, W;
	cin >> W >> n >> V;
	for(int i = 1; i <= n; ++i)
		cin >> a[i].first >> a[i].second;
	for(int i = 1; i <= n; ++i)
		for(int j = V; j; --j)
			for(int k = W; k >= a[i].first; --k)
				f[j][k] = max(f[j][k], f[j - 1][k - a[i].first] + a[i].second);
	cout << f[V][W] << endl;
	return 0;
}
