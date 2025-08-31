#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1003;
int a[N], f[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n = 0;
	while(cin >> a[++n]);
	--n;
	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		f[i] = 1;
		for(int j = 1; j < i; ++j)
			if(a[i] <= a[j])
				f[i] = max(f[i], f[j] + 1);
		ans = max(ans, f[i]);
	}
	cout << ans << '\n';
	ans = 0;
	for(int i = 1; i <= n; ++i) {
		f[i] = 1;
		for(int j = 1; j < i; ++j)
			if(a[i] > a[j])
				f[i] = max(f[i], f[j] + 1);
		ans = max(ans, f[i]);
	}
	cout << ans;
	cout.flush();
	return 0;
}