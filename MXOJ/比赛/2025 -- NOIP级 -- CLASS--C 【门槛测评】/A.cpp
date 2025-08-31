#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long

int n, x, y;

bool chk(int M) {
	for(int i = 0; i <= log2(n); ++i) {
		if(i * x >= M)
			break;
		else if(!i)
			if((M - i * x) / y + 1 > n)
				return true;
			else
				continue;
		int j = (M - i * x) / y, v = 1, tmp = j / (i + 1), R = j - tmp * (i + 1);
		for(int k = 0; k <= i; ++k) {
			if(R > 0)
			{ v += (tmp + 1) * v; --R; }
			else
				v += tmp * v;
			if(v > n)
				return true;
		}
	}
	return false;
}

signed main() {
	freopen("dice.in", "R", stdin);
	freopen("dice.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> x >> y;
	int ans = 0, L = 1, R = 1e19;
	while (L <= R) {
		int M = (L + R) >> 1;
		if(chk(M))
		{ ans = M; R = M - 1; }
		else
			L = M + 1;
	}
	ans += x;
	cout << ans << endl;
	return 0;
}
