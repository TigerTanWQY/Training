#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
using LL = long long;

constexpr const int N = 100'003;
pair<int, int> a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a, a + n);
	int ans = 0;
	for(int i = 0; i < n; ++i)
		ans = max(ans, a[i].second - i);
	cout << ans + 1 << endl;
	fclose(stdin);
	fclose(stdout);
	fclose(stderr);
	return 0;
}