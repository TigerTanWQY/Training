#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

constexpr const int N = 1'003;
int a[N], f[N * N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	int minn = 0x3f3f3f3f, maxn = 0;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		minn = min(minn, a[i]);
		maxn = max(maxn, a[i]);
	}
	maxn = maxn - minn;
	for(int i = 1; i <= n; ++i)
		a[i] -= minn;
	memset(f,0x3f,sizeof(f));
	f[0] = 0;
	for(int i = 1; i <= k * maxn; ++i)
		for(int j = 1; j <= n; ++j)
			if(a[j] <= i)
				f[i] = min(f[i], f[i - a[j]] + 1);
	for(int i = 0; i <= k * maxn; ++i)
		if(f[i] <= k)
			cout << i + k * minn << ' ';
	cout.flush();
	return 0;
}