#include <iostream>
#include <utility>
using namespace std;

constexpr const int P = 20123;
pair<bool, int> a[10003][103];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, rt;
	cin >> n >> m;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			cin >> a[i][j].first >> a[i][j].second;
	cin >> rt;
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		int x = a[i][rt].second;
		ans += x;
		ans %= P;
		int cnt = 0;
		for(int j = 0; j < m; ++j)
			cnt += a[i][j].first;
		x %= cnt;
		if(x == 0)
			x = cnt;
		if(a[i][rt].first)
			--x;
		while(x) {
			++rt;
			rt %= m;
			if(a[i][rt].first)
				--x;
		}
	}
	cout << ans << endl;
	return 0;
}