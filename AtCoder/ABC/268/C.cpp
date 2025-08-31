#include <iostream>
#include <algorithm>
using namespace std;

int p[200003], cnt[200003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> p[i];
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < 3; ++j)
			++cnt[(p[i] - 1 - i + j + n) % n];
	int ans = 0;
	for(int i = 0; i < n; ++i)
		ans = max(ans, cnt[i]);
	cout << ans;
	return 0;
}
