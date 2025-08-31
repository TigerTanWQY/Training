#include <iostream>
#include <bitset>
using namespace std;

constexpr const int N = 2e5 + 3;
bitset<N> c;
int a[N * 2], cnt[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, k, i;
	cin >> n >> m >> k;
	for(i = 0; i < n; ++i) {
		cin >> a[i];
		a[i + n] = a[i];
	}
	i = 0;
	do {
		for(int j = i; j < i + k; ++j)
			c[a[j]] = true;
		for(int j = 1; j <= m; ++j)
			if(c[j])
				++cnt[j];
		i = (i + k) % n;
		c.reset();
	} while(i);
	for(i = 1; i <= m; ++i)
		cout << cnt[i] << ' ';
	cout << endl;
	return 0;
}