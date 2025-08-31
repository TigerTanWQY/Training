#include <iostream>
#include <algorithm>
using namespace std;

int a[200003];
long long s[200003];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	for(int i = 2; i < n; i += 2)
		s[i] = s[i - 2] + a[i] - a[i - 1];
	for(int i = n; i > 1; i -= 2)
		s[i] = s[i + 2] + a[i] - a[i - 1];
	long long ans = 0x3f3f3f3f3f3f3f3f;
	for(int x; m--; ) {
		cin >> x;
		int i = lower_bound(a + 1, a + 1 + n, x) - a;
		if(i & 1)
			ans = min(ans, s[i - 1] + s[i + 2] + a[i] - x);
		else
			ans = min(ans, s[i - 2] + s[i + 1] + x - a[i - 1]);
	}
	cout << ans;
	return 0;
}