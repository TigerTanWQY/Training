#include <iostream>
using namespace std;

bool a[13][13];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j) {
			char c;
			cin >> c;
			if(c == '#')
				a[i][j] = true;
		}
	int ans = 0;
	for(int i = 1; i < n; ++i)
		for(int j = 1; j < m; ++j)
			ans += (a[i][j] ^ a[i + 1][j + 1] ^ a[i + 1][j] ^ a[i][j + 1]);
	cout << ans;
	return 0;
}