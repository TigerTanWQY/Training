#include <bits/stdc++.h>
using namespace std;

int f[47][3][3], cnt[47];

int func(int n, int x, int y) {
	const int g = gcd(x, y);
	if(g != 1)
		return (g - n%g) * func(n/g, x/g, y/g) + (n % g) * func(n/g + 1, x/g, y/g);
	for(int i = 0; i < x+y; ++i)
		cnt[i] = (n-1) / (x+y) + ((n-1) % (x+y) >= i);
	f[0][1][1] = cnt[0];
	for(int i = 1, cur; i < x + y; ++i) {
		cur = x * i % (x+y);
		if(i != x+y-1)
			f[i][1][1] = f[i-1][0][1] + cnt[cur];
		f[i][0][1] = max(f[i-1][1][1], f[i-1][0][1]);
		f[i][1][0] = f[i-1][0][0] + cnt[cur];
		f[i][0][0] = max(f[i-1][1][0], f[i-1][0][0]);
	}
	return max({f[x+y-1][0][0], f[x+y-1][0][1], f[x+y-1][1][0], f[x+y-1][1][1]});
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, x, y;
	cin >> n >> x >> y;
	cout << func(n, x, y) << endl;
	return 0;
}
