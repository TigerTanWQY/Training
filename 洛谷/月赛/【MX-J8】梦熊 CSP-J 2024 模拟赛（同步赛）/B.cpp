#include <iostream>
using namespace std;

constexpr const int P = 1e9 + 7, N = 2e5 + 3;
int m[N], a[N];

inline void add(int& x, const int y) {
	x += y;
	x %= P;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> m[i];
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	int ans = 1;
	for(int s = 0; s < 1 << n; ++s) {
		int cnt = 1e9;
		for(int i = 0; i < n; ++i)
			if(s >> i & 1)
				cnt = min(cnt, m[i] - a[i]);
			else
				cnt = min(cnt, a[i] - 1);
		add(ans, cnt);
	}
	cout << ans << endl;
	return 0;
}