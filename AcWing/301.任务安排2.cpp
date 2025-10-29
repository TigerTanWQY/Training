#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 3e5 + 3;
int q[N];
long long st[N], sc[N], f[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, S;
	cin >> n >> S;
	for(int i = 1; i <= n; ++i) {
		cin >> st[i] >> sc[i];
		st[i] += st[i-1];
		sc[i] += sc[i-1];
	}
	int hh = 0, tt = 0;
	for(int i = 1; i <= n; ++i) {
		while(hh < tt && (f[q[hh+1]] - f[q[hh]]) <=
				(sc[q[hh+1]] - sc[q[hh]]) * (st[i] + S))
			++hh;
		f[i] = f[q[hh]] + S * (sc[n] - sc[q[hh]]) + st[i] * (sc[i] - sc[q[hh]]);
		while(hh < tt && (f[q[tt]] - f[q[tt-1]]) * (sc[i] - sc[q[tt]]) >=
				(f[i] - f[q[tt]]) * (sc[q[tt]] - sc[q[tt-1]]))
			--tt;
		q[++tt] = i;
	}
	cout << f[n] << endl;
	return 0;
}
