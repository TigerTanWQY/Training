#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int N = 5e4 + 3, M = 2e5 + 3;
int bel[N], z[M], y[M], wz[M], a[N], ap1[N], ap2[N];
LL ans[N];

void qs(int L, int R) {
	int i = L, j = R, m = bel[z[L + R >> 1]], mm = y[L + R >> 1];
	while(i <= j) {
		for(; bel[z[i]] < m || bel[z[i]] == m && ((m & 1) && y[i] < mm || (1 ^ m & 1) && y[i] > mm); ++i);
		for(; bel[z[j]] > m || bel[z[j]] == m && ((m & 1) && y[j] > mm || (1 ^ m & 1) && y[j] < mm); --j);
		if(i <= j) {
			swap(z[i], z[j]);
			swap(y[i], y[j]);
			swap(wz[i++], wz[j--]);
		}
	}
	if(i < R)
		qs(i, R);
	if(L < j)
		qs(L, j);
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m = 0, _q;
	cin >> n;
	int cnt = sqrt(n << 2);
	if(cnt > n)
		cnt = n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		bel[i] = (i - 1) / cnt + 1;
	}
	cin >> _q;
	for(int i = 1, j, L, R, x; i <= _q; ++i) {
		cin >> j >> L >> R >> x;
		z[++m] = L; y[m] = x; wz[m] = i;
		z[++m] = j - 1; y[m] = R - 1; wz[m] = i;
		z[++m] = L; y[m] = R - 1; wz[m] = -i;
		z[++m] = j - 1; y[m] = x; wz[m] = -i;
	}
	qs(1, m);
	int L = 0, R = 0;
	LL cur = 0;
	for(int i = 1; i <= m; ++i) {
		while(L < z[i]) {
			++ap1[a[++L]];
			cur += ap2[a[L]];
		}
		while(R < y[i]) {
			++ap2[a[++R]];
			cur += ap1[a[R]];
		}
		while(L > z[i]) {
			--ap1[a[L]];
			cur -= ap2[a[L--]];
		}
		while(R > y[i]) {
			--ap2[a[R]];
			cur -= ap1[a[R--]];
		}
		if(wz[i] > 0)
			ans[wz[i]] += cur;
		else
			ans[-wz[i]] -= cur;
	}
	for(int i = 1; i <= _q; ++i)
		cout << ans[i] << '\n';
	cout.flush(); return 0;
}
