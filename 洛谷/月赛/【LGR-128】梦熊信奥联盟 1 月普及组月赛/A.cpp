#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	double L = 0, R = 1e9 + 1;
	for(int i = 1, x; i <= n; ++i) {
		cin >> x;
		L = max(L, 1.0 * m / (x * i));
		R = min(R, 1.0 * m / ((x - 1) * i));
	}
	if(R == 1e9 + 1)
		cout << "xiaogougege";
	else {
		int ans = 0;
		for(int i = ceil(L); i < R; ++i)
			++ans;
		cout << ans;
	}
	cout.flush();
	return 0;
}