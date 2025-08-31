#include <iostream>
#include <algorithm>
using namespace std;

constexpr const int N = 9 + 1;
pair<int, int> a[N];
int p[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i].first;
		p[i] = i;
	}
	for(int i = 1; i <= n; ++i)
		cin >> a[i].second;
	int ans = 0x3f3f3f3f;
	do {
		int tot = 1;
		for(int i = 2; i <= n; ++i)
			tot += max(a[p[i]].first, a[p[i - 1]].second) + 1;
		ans = min(ans, tot);
	} while(next_permutation(p + 1, p + n + 1));
	cout << ans;
	cout.flush();
	return 0;
}