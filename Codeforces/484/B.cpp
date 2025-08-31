#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int a[200003];

int read() {
	char ch = cin.get();
	int res = 0;
	for(; ch < '0' || '9' < ch; ch = cin.get());
	for(; '0' <= ch && ch <= '9'; ch = cin.get())
		res = res * 10 + ch - '0';
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n = read(), ans = 0;
	for(int i = 1; i <= n; ++i)
		a[i] = read();
	sort(a + 1, a + n + 1);
	n = unique(a + 1, a + n + 1) - a - 1;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= a[n] / a[i]; ++j)
			ans = max(ans, a[lower_bound(a + 1, a + n + 1, a[i] * (j + 1)) - a - 1] % a[i]);
	cout << ans;
	return 0;
}