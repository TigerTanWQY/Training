#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> a;
	for(int i = 1, L, R; i <= n; ++i) {
		cin >> L >> R;
		a.push_back(L * 2);
		a.push_back(R * 2 + 1);
	}
	sort(a.begin(), a.end());
	int ans = 1, cnt = 0;
	for(const auto& x: a) {
		if(!(x & 1))
			++cnt;
		else
			--cnt;
		ans = max(ans, cnt);
	}
	cout << ans;
	cout.flush();
	return 0;
}