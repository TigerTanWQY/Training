#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 3e5 + 3;
unordered_map<int, int> cnt;
int a[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		++cnt[a[i]];
	}
	int ans = -1, maxn = 0;
	for(int i = 1; i <= n; ++i)
		if(cnt[a[i]] == 1 && a[i] >= maxn)
		{ maxn = a[i]; ans = i; }
	cout << ans << endl;
	return 0;
}
