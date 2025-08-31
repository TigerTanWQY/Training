#include <iostream>
#include <algorithm>
using namespace std;

const int N = 300003;
struct
{ int a, x, y; }
a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, ans = 0x3f3f3f3f;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i].a;
	for(int i = 1; i <= n; ++i)
		a[i].x = max(a[i - 1].x, a[i].a + n - i);
	for(int i = n; i; --i)
		a[i].y = max(a[i + 1].y, a[i].a + i - 1);
	for(int i = 1; i <= n; ++i)
		ans = min(ans, max({a[i].a, a[i - 1].x, a[i + 1].y}));
	cout << ans;
	return 0;
}