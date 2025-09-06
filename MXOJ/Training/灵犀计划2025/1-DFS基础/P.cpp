#include <iostream>
using namespace std;

int a[23], n, k, ans = 0;

bool is_prime(int x) {
	if(x < 2)
		return false;
	for(int i = 2; i * i <= x; ++i)
		if(x % i == 0)
			return false;
	return true;
}

void dfs(int i, int cnt, int tot) {
	if(cnt == k) {
		if(is_prime(tot))
			++ans;
		return;
	} else if(i == n)
		return;
	dfs(i + 1, cnt + 1, tot + a[i]);
	dfs(i + 1, cnt, tot);
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> k;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	dfs(0, 0, 0);
	cout << ans << endl;
	return 0;
}
