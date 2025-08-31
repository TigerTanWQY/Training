#include <bits/stdc++.h>
using namespace std;

constexpr const int p[]{2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
int a[100003], b[33];
long long cnt[1 << 10];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	for(int i = 1; i <= 30; ++i)
		for(int j = i, k = 0; k < 10; ++k)
			for(; j % p[k] == 0; j /= p[k])
				b[i] ^= 1 << k;
	int n;
	cin >> n;
	cnt[0] = 1;
	int tot = 0; long long ans = 0;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		tot ^= b[a[i]];
		ans += cnt[tot]++;
	}
	cout << ans << endl;
	return 0;
}
