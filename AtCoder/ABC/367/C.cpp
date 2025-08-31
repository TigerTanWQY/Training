#include <iostream>
using namespace std;

constexpr const int N = 8 + 1;
int r[N], a[N], n, k;

void dfs(const int i) {
	if(i > n) {
		int tot = 0;
		for(int j = 1; j <= n; ++j)
			tot += a[j];
		if(tot % k == 0) {
			for(int j = 1; j <= n; ++j)
				cout << a[j] << ' ';
			cout << '\n';
		}
		return;
	}
	for(int x = 1; x <= r[i]; ++x) {
		a[i] = x;
		dfs(i + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> k;
	for(int i = 1; i <= n; ++i)
		cin >> r[i];
	dfs(1);
	cout.flush();
	return 0;
}