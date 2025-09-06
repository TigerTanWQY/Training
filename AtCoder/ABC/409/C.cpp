#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int N = 3e5 + 3;
int d[N];
LL pos[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	LL n, L;
	cin >> n >> L;
	for(int i = 0; i < n - 1; ++i)
		cin >> d[i];
	if(L % 3 != 0) {
		cout.put('0') << endl;
		return 0;
	}
	LL seg = L / 3, cur = 0;
	pos[0] = cur;
	for(int i = 1; i < n; ++i) {
		cur = (cur + d[i - 1]) % L;
		pos[i] = cur;
	}
	unordered_map<LL, LL> cnt;
	for(int i = 0; i < n; ++i)
		++cnt[pos[i]];
	LL ans = 0;
	for(const auto& [x, cnt_x]: cnt) {
		LL y = (x + seg) % L;
		if(cnt.find(y) == cnt.cend())
			continue;
		LL z = (y + seg) % L;
		if(cnt.find(z) == cnt.cend())
			continue;
		ans += cnt_x * cnt[y] * cnt[z];
	}
	cout << ans / 3 << endl;
	return 0;
}
