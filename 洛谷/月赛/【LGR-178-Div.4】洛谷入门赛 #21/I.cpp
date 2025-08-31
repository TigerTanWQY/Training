#include <iostream>
using namespace std;

int n, k, ans;

void dfs(const int& m, const int& tot) {
	if(tot > k || m > n)
		return;
	++ans;
	for(int i = 0; i < 10; ++i)
		dfs(m + 1, tot + i);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while(T--) {
		cin >> n >> k;
		for(int i = 1; i < 10; ++i)
			dfs(1, i);
		cout << ans << '\n';
		ans = 0;
	}
	return 0;
}