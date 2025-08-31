#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, int> cnt;
int a[200003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, c;
	cin >> n >> c;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		++cnt[a[i]];
		a[i] -= c;
	}
	long long ans = 0;
	for(int i = 1; i <= n; ++i)
		ans += cnt[a[i]];
	cout << ans;
	return 0;
}