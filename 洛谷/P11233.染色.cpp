#include <iostream>
using namespace std;

int a[200003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int _T;
	cin >> _T;
	for(int n; _T--; cout.put('\n')) {
		cin >> n;
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		long long ans = 0;
		for(int s = 0; s < 1 << n; ++s) {
			long long cnt = 0;
			for(int i = 0; i < n; ++i)
				for(int j = i - 1; j >= 0; --j)
					if((s >> i & 1) == (s >> j & 1)) {
						cnt += (a[i] == a[j]? a[i]: 0);
						break;
					}
			ans = max(ans, cnt);
		}
		cout << ans;
	}
	cout.flush();
	return 0;
}