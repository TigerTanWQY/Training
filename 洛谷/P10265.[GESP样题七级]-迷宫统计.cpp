#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1003;
int G[N][N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, S;
	cin >> n >> S;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			cin >> G[i][j];
	int ans1 = 0, ans2 = 0;
	for(int i = 1; i <= n; ++i)
	{ ans1 += G[S][i]; ans2 += G[i][S]; }
	cout << ans1 << ' ' << ans2 << ' ' << ans1 + ans2 << endl;
	return 0;
}
