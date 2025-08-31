#include <iostream>
#include <algorithm>
using namespace std;

constexpr const int N = 1003;
pair<int, int> a[N];
int r[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1, x; i <= n; ++i) {
		cin >> x;
		for(; x % 2 == 0; x /= 2)
			++a[i].first;
		for(; x % 3 == 0; x /= 3)
			++a[i].second;
		r[i] = x;
	}
	for(int i = 2; i <= n; ++i)
		if(r[i] != r[i - 1]) {
			cout << "-1" << endl;
			return 0;
		}
	int min1 = 0x3f3f3f3f, min2 = 0x3f3f3f3f;
	for(int i = 1; i <= n; ++i) {
		min1 = min(min1, a[i].first);
		min2 = min(min2, a[i].second);
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i)
		ans += a[i].first - min1 + a[i].second - min2;
	cout << ans << endl;
	return 0;
}