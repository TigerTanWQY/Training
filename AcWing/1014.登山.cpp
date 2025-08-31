#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1003;
int a[N], f[N], g[N];

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 1; i <= n; ++i) {
		f[i] = 1;
		for(int j = 1; j < i; ++j)
			if(a[j] < a[i])
				f[i] = max(f[i], f[j] + 1);
	}
	for(int i = n; i; --i) {
		g[i] = 1;
		for(int j = n; j > i; --j)
			if(a[i] > a[j])
				g[i] = max(g[i], g[j] + 1);
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i)
		ans = max(ans, f[i] + g[i] - 1);
	cout << ans;
	return 0;
}