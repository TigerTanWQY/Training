#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

const int N = 5003;
pair<int, int> a[N];
int f[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i].first >> a[i].second;
	sort(a + 1, a + n + 1);
	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		f[i] = 1;
		for(int j = 1; j < i; ++j)
			if(a[i].second > a[j].second)
				f[i] = max(f[i], f[j] + 1);
		ans = max(ans, f[i]);
	}
	cout << ans;
	cout.flush();
	return 0;
}