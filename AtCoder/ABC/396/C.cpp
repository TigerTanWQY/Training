#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int N = 2e5 + 3;
int a1[N], a2[N];
LL s1[N], s2[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> a1[i];
	sort(a1 + 1, a1 + n + 1, greater<>());
	for(int i = 1; i <= n; ++i)
		s1[i] = s1[i - 1] + a1[i];
	for(int i = 1; i <= m; ++i)
		cin >> a2[i];
	sort(a2 + 1, a2 + m + 1, greater<>());
	for(int i = 1; i <= m; ++i)
		s2[i] = s2[i - 1] + a2[i];
	LL ans = 0;
	for(int i = 1, j = 0; i <= n; ++i) {
		if(s2[i] >= s2[j])
			++j;
		ans = max(ans, s1[i] + s2[j]);
	}
	cout << ans << endl;
	return 0;
}
