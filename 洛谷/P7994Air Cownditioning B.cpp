#include <iostream>
using namespace std;

constexpr const int N = 100003;
int a[N], b[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 1; i <= n; ++i) {
		cin >> b[i];
		b[i] -= a[i];
	}
	long long ans = 0;
	for(int i = 1; i <= n + 1; ++i)
		ans += max(b[i] - b[i - 1], 0);
	cout << ans;
	cout << endl;
	return 0;
}