#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 2e4 + 3;
int d[N], c[N], s[N], w[N];

int main() {
	freopen("valley.in", "r", stdin);
	freopen("valley.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for(int i = 2; i <= n; ++i)
		cin >> d[i];
	for(int i = 1; i <= n; ++i)
		cin >> c[i];
	for(int i = 1; i <= n; ++i)
		cin >> s[i];
	for(int i = 1; i <= n; ++i)
		cin >> w[i];
	cout << endl;
	return 0;
}
