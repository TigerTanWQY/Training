#include <iostream>
using namespace std;

int a[13];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	constexpr const int n = 10;
	int m;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	cin >> m;
	m += 30;
	int ans = 0;
	for(int i = 1; i <= n; ++i)
		if(a[i] <= m)
			++ans;
	cout << ans << endl;
	return 0;
}