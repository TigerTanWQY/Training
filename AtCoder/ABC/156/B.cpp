#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	int ans = 0;
	for(; n; n /= k)
		++ans;
	cout << ans;
	cout.flush();
	return 0;
}