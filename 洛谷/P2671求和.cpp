#include <iostream>
using namespace std;

const int P = 10007;
const int N = 100003;
int w[N], c[N], a[2][4][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> w[i];
	for(int i = 1; i <= n; ++i)
		cin >> c[i];
	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		bool y = (i & 1);
		ans = (ans + a[y][0][c[i]]) % P;
		ans = (ans + 1LL * a[y][1][c[i]] * w[i]) % P;
		ans = (ans + 1LL * a[y][2][c[i]] * i) % P;
		ans = (ans + 1LL * a[y][3][c[i]] * i % P * w[i] % P) % P;
		a[y][0][c[i]] = (a[y][0][c[i]] + 1LL * i * w[i] % P) % P;
		a[y][1][c[i]] = (a[y][1][c[i]] + i) % P;
		a[y][2][c[i]] = (a[y][2][c[i]] + w[i]) % P;
		a[y][3][c[i]] = (a[y][3][c[i]] + 1) % P;
	}
	cout << ans;
	return 0;
}