#include <iostream>
using namespace std;

int a[200003], ans[400003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0; i < n; ++i) {
		ans[2 * i + 1] = ans[a[i] - 1] + 1;
		ans[2 * i + 2] = ans[a[i] - 1] + 1;
	}
	for(int i = 0; i <= 2 * n; ++i)
		cout << ans[i] << '\n';
	return 0;
}