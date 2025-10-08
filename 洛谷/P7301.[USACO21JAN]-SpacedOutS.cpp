#include <bits/stdc++.h>
using namespace std;

int x[1003][2], y[1003][2];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1, k; i <= n; ++i)
		for(int j = 1; j <= n; ++j) {
			cin >> k;
			x[i][j&1] += k;
			y[j][i&1] += k;
		}
	int c1 = 0, c2 = 0;
	for(int i = 1; i <= n; ++i) {
		c1 += max(x[i][1], x[i][0]);
		c2 += max(y[i][1], y[i][0]);
	}
	cout << max(c1, c2) << endl;
	return 0;
}
