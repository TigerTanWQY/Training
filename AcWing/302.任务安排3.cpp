#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 3e5 + 3;
long long sc[N], st[N], f[N], q[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n; long long S;
	cin >> n >> S;
	for(int i = 1; i <= n; ++i) {
		cin >> st[i] >> sc[i];
		st[i] += st[i-1];
		sc[i] += sc[i-1];
	}
	int tt = 0;
	for(int i = 1; i <= n; ++i) {
		int L = 0, R = tt;
		while(L < R) {
			int M = (L + R) >> 1;
			if(f[q[M+1]] - f[q[M]] >
					(S + st[i]) * (sc[q[M+1]] - sc[q[M]]))
				R = M;
			else
				L = M+1;
		}
		f[i] = f[q[R]] + S * (sc[n] - sc[q[R]]) + st[i] * (sc[i] - sc[q[R]]);
		while(tt && (double)(f[q[tt]] - f[q[tt-1]]) * (sc[i] - sc[q[tt]]) >=
				(double)(f[i] - f[q[tt]]) * (sc[q[tt]] - sc[q[tt-1]]))
			--tt;
		q[++tt] = i;
	}
	cout << f[n] << endl;
	return 0;
}
