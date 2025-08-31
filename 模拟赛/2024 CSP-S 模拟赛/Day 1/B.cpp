#include <iostream>
#include <algorithm>
using namespace std;

unsigned a[500003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	unsigned ans = 0x3f3f3f3f;
	do {
		unsigned maxn = 0;
		for(int i = 1; i <= n; i += 2)
			maxn = max(maxn, min(a[i] ^ a[i + 1], max(a[i], a[i + 1])));
		if(n & 1)
			maxn = max(maxn, a[n]);
		ans = min(ans, maxn);
	} while(next_permutation(a + 1, a + n + 1));
	cout << ans << endl;
	return 0;
}