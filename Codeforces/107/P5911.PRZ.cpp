#include <iostream>
#include <array>
#include <algorithm>
using namespace std;
using LL = long long;

constexpr const int N = 16;
array<int, N> a, b;
array<LL, 1 << N> v, w, f;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
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
	f.fill(0x3f3f3f3f3f3f3f3f);
	f[0] = 0;
	for(int i = 0; i < 1 << n; ++i)
		for(int j = i; ; j = i & j - 1) {
			if(w[i ^ j] <= V)
				f[i] = min(f[i], f[j] + v[i ^ j]);
			if(!j)
				break;
		}
	cout << f[(1 << n) - 1];
	return 0;
}