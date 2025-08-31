#include <iostream>
using namespace std;
using LL = long long;

constexpr const int N = 10'003;
int q[N], h = 1, t = 1;
LL st[N], sc[N], f[N];

int fnd(int L, int R, const LL s) {
	int ans = t;
	while(L <= R) {
		int M = (L + R) / 2;
		if(f[q[M + 1]] - f[q[M]] > s * (sc[q[M + 1]] - sc[q[M]])) {
			R = M - 1;
			ans = M;
		} else
			L = M + 1;
	}
	return q[ans];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, s;
	cin >> n >> s;
	for(int i = 1, x, y; i <= n; ++i) {
		cin >> x >> y;
		st[i] = st[i - 1] + x;
		sc[i] = sc[i - 1] + y;
	}
	for(int i = 1; i <= n; ++i) {
		int p = fnd(h, t, s + st[i]);
		f[i] = f[p] + s * (sc[n] - sc[p]) + st[i] * (sc[i] - sc[p]);
		while(h < t && (f[q[t]] - f[q[t - 1]]) * (sc[i] - sc[q[t]]) >= (f[i] - f[q[t]]) * (sc[q[t]] - sc[q[t - 1]]))
			--t;
		q[++t] = i;
	}
	cout << f[n] << endl;
	return 0;
}