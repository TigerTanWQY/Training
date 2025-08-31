#include <iostream>
using namespace std;

constexpr const int P = 1e4 + 7, N = 1e5 + 3;
int a[N], c[N], f[4][2][N];

inline void add(int& x, const int& y)
{ x += y; x %= P; }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		a[i] %= P;
	}
	for(int i = 1; i <= n; ++i)
		cin >> c[i];
	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		const int k = i & 1;
		add(ans, f[0][k][c[i]]);
		add(ans, f[1][k][c[i]] * a[i]);
		add(ans, f[2][k][c[i]] * i);
		add(ans, f[3][k][c[i]] * i % P * a[i] % P);
		add(f[0][k][c[i]], a[i] * i % P);
		add(f[1][k][c[i]], i);
		add(f[2][k][c[i]], a[i]);
		add(f[3][k][c[i]], 1);
	}
	cout << ans << endl;
	return 0;
}