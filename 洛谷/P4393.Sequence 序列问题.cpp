#include <iostream>
#include <algorithm>
using namespace std;

constexpr const int N = 1'000'003;
int a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	long long ans = 0;
	for(int i = 1; i < n; ++i)
		ans += max(a[i], a[i + 1]);
	cout << ans;
	cout.flush();
	return 0;
}