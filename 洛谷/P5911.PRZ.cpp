#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int N = 16;
int a[N], b[N];
LL v[1<<N], w[1<<N], f[1<<N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int V, n;
	cin >> V >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i] >> b[i];
	for(int i = 0; i < 1 << n; ++i)
		for(int j = 1; j <= n; ++j)
			if(i & 1 << j - 1) {
				v[i] = max(v[i], (LL)a[j]);
				w[i] += b[j];
			}
	memset(f, 0x3f, sizeof f);
	f[0] = 0;
	for(int i = 0; i < 1 << n; ++i)
		for(int j = i; ; j = i & j - 1) {
			if(w[i ^ j] <= V)
				f[i] = min(f[i], f[j] + v[i ^ j]);
			if(!j)
				break;
		}
	cout << f[(1 << n) - 1] << endl;
	return 0;
}
