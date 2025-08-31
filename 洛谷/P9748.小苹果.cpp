#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	int ans1 = 0, ans2 = 0;
	while(n) {
		++ans1;
		if(!ans2 && n % 3 == 1)
			ans2 = ans1;
		n -= n / 3 + !!(n % 3);
	}
	cout << ans1 << ' ' << ans2 << endl;
	return 0;
}