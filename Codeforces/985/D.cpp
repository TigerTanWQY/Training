#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	long double n, h;
	cin >> n >> h;
	long long ans;
	if(h * (h + 1) >= 2 * n)
		ans = ceil((sqrt(8 * n + 1) - 1) / 2);
	else
		ans = ceil(sqrt(2 * h * h - 2 * h + 4 * n) - h);
	cout << ans << endl;
	return 0;
}
