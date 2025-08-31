#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	for(int L, R; n--; ) {
		cin >> L >> R;
		if(k == 1) {
			cout << (R - L + 1);
		} else {
			int ans = 0;
			for(int i = L; i <= R; ++i)
				if(i % 10 == k || i % k == 0)
					++ans;
			cout << ans;
		}
		cout << '\n';
	}
	cout << flush;
	return 0;
}