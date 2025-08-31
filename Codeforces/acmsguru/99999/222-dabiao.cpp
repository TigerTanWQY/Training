#include <iostream>
#include <bitset>
using namespace std;

constexpr const int N = 10 + 1;
bitset<N> vis;
int n, k;
long long ans = 0;

void dfs(const int& i, const int& cnt) {
	if(cnt == k) {
		++ans;
		return;
	} else if(i > n)
		return;
	for(int j = 1; j <= n; ++j)
		if(!vis[j]) {
			vis[j] = true;
			dfs(i + 1, cnt + 1);
			vis[j] = false;
		}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> k;
	dfs(0, 0);
	cout << ans;
	cout.flush();
	return 0;
}