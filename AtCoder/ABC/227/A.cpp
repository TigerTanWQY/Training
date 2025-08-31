#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k, a;
	cin >> n >> k >> a;
	k %= n;
	int ans = (a + k - 1 + n) % n;
	if(!ans)
		ans = n;
	cout << ans;
	return 0;
}