#include <bits/stdc++.h>
using namespace std;

int a[100003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	int tot = 0;
	for(int i = 1, L, R, w; i <= n; ++i) {
		cin >> L >> R >> w;
		a[L] += w; a[R + 1] -= w;
		tot += w;
	}
	int minw = 0x3f3f3f3f;
	for(int i = 1, cnt = 0; i <= m; ++i) {
		cnt += a[i];
		minw = min(minw, cnt);
	}
	cout << tot - minw << endl;
	return 0;
}
