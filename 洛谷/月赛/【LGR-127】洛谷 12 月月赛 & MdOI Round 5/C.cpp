#include <iostream>
using namespace std;
using LL = long long;
using i128 = __int128;

int a[1'000'003], b[1'000'003];

template<class _Tp>
void write(_Tp x) {
	int s[40], k = 0;
	for(; x; x /= 10)
		s[++k] = x % 10;
	for(int i = k; i; --i)
		cout.put(s[i] + '0');
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	i128 tot1 = 0, tot2 = 0;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		tot1 += a[i];
		tot2 += 1LL * a[i] * a[i];
	}
	for(int i = 1; i <= n; ++i)
		cin >> b[i];
	i128 ans = tot2 * n - tot1 * tot1;
	for(int i = n; i; --i) {
		tot1 += b[i] - a[i];
		tot2 += 1LL * b[i] * b[i] - 1LL * a[i] * a[i];
		ans = max(ans, tot2 * n - tot1 * tot1);
	}
	write(ans);
	cout.flush();
	return 0;
}