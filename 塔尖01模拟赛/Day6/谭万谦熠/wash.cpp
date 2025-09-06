#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int t[10000003], n, x;

int read() {
	int res = 0;
	char ch = getchar();
	for(; '0' > ch || ch > '9'; ch = getchar());
	for(; '0' <= ch && ch <= '9'; ch = getchar())
		res = res * 10 + ch - '0';
	return res;
}

bool chk(LL T, int y) {
	LL tot = 0;
	for(int i = 0; i < n; ++i) {
		if(t[i] + (LL)y <= T)
			continue;
		if(t[i] + (LL)x > T)
			return false;
		LL st = max(tot, (LL)t[i]);
		if(st + x > T)
			return false;
		tot = st + x;
	}
	return true;
}

int main() {
	freopen("wash.in", "r", stdin);
	freopen("wash.out", "w", stdout);
	n = read(); x = read(); int m = read();
	LL lst = 0, Rm = 0, ans = 0;
	for(int i = 0; i < n; ++i) {
		t[i] = read();
		Rm = max(Rm, (LL)t[i]);
	}
	Rm += max(x, m);
	for(int y = 1; y <= m; ++y) {
		LL L = lst, R = Rm;
		while(L <= R) {
			LL M = (L + R) >> 1;
			if(chk(M, y))
				R = M - 1;
			else
				L = M + 1;
		}
		ans ^= y * L; lst = L;
	}
	printf("%lld\n", ans);
	return 0;
}
