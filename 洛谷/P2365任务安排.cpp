#include <iostream>
using namespace std;

const int N = 5003;
int t[N], c[N];
long long f[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, s;
	cin >> n >> s;
	for(int i = 1, x, y; i <= n; ++i) {
		cin >> x >> y;
		t[i] = t[i - 1] + x;
		c[i] = c[i - 1] + y;
		f[i] = 0x3f3f3f3f3f3f3f3f;
	}
	for(int i = 1; i <= n; ++i)
		for(int k = 0; k <= i; ++k)
			f[i] = min(f[i], f[k] + 1LL * t[i] * (c[i] - c[k]) + 1LL * s * (c[n] - c[k]));
	cout << f[n];
	return 0;
}