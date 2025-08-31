#include <iostream>
using namespace std;
using LL = long long;

int a[200'003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	LL ans = 0;
	int L = 1, R = 2, cnt = 0;
	for(int d = a[R] - a[R - 1]; R <= n; ++R)
		if(a[R] - a[R - 1] != d) {
			int m = R - L;
			ans += (m + 1LL) * m / 2LL;
			L = R - 1;
			d = a[R] - a[R - 1];
			++cnt;
		}
	int m = R - L;
	ans += (m + 1LL) * m / 2LL;
	L = R - 1;
	++cnt;
	cout << ans - cnt + 1;
	cout.flush();
	return 0;
}