#include <iostream>
using namespace std;

constexpr const int N = 2e5 + 3;
int a[N], ans[N * 2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0; i < n; ++i)
		ans[2 * i + 1] = ans[2 * i + 2] = ans[a[i] - 1] + 1;
	for(int i = 0; i <= 2 * n; ++i)
		cout << ans[i] << '\n';
	cout.flush();
	return 0;
}