#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1e6 + 3;
int st[23][N], a[N], s[N], f[N];

int qry(int L, int R) {
	int lg = log2(R - L + 1);
	return max(st[lg][L], st[lg][R - (1 << lg) + 1]);
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, _q;
	cin >> n >> _q;
	a[0] = 2;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	int tot = 0;
	for(int i = 1, cnt0 = 0, cnt1 = 0; i <= n; ++i) {
		if(a[i])
		{ --tot; ++cnt0; }
		else
		{ ++tot; ++cnt1; }
		st[0][i] = cnt1 - cnt0;
		f[i] = cnt0;
		s[i] = s[i - 1] + (a[i] == 1 && a[i - 1] == 0);
	}
	for(int j = 1; j <= 20; ++j)
		for(int i = 1; i + (1 << j) - 1 <= n; ++i)
			st[j][i] = max(st[j - 1][i], st[j - 1][i + (1 << j - 1)]);
	for(int op, L, R; _q--; cout.put('\n')) {
		cin >> op >> L >> R;
		if(op == 1)
			cout << max(f[R] - f[L - 1], qry(L, R) - (L - 1 - f[L - 1]) + f[R]);
		else
			cout << (1 + !(s[L] == s[R]));
	}
	cout.flush(); return 0;
}
