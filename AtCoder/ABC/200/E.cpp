#include <bits/stdc++.h>
using namespace std;

long long c[4][3'000'003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	long long k;
	cin >> n >> k;
	memset(c, 0, sizeof(long long) * (n * 3 + 1) * 4);
	c[0][0] = 1;
	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j <= i * n; ++j) {
			c[i + 1][j + 1] += c[i][j];
			c[i + 1][j + n + 1] -= c[i][j];
		}
		for(int j = 1; j <= (i + 1) * n; ++j)
			c[i + 1][j] += c[i + 1][j - 1];
	}
	int id = 0;
	for(int i = 3; !id && i <= 3 * n; ++i)
		if(k <= c[3][i])
			id = i;
		else
			k -= c[3][i];
	for(int i = 1; i <= n; ++i) {
		const int minn = max(1, id - i - n), maxn = min(n, id - i - 1), y = minn + k - 1, z = id - i - y;
		if(minn > maxn)
			continue;
		else if(k > maxn - minn + 1) {
			k -= maxn - minn + 1;
			continue;
		} else {
			cout << i << ' ' << y << ' ' << z << endl;
			break;
		}
	}
	return 0;
}
