#include <iostream>
#include <algorithm>
using namespace std;

const int N = 103;
int a[N], f[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int _T;
	cin >> _T;
	for(int n; _T--; ) {
		cin >> n;
		for(int i = 1; i <= n; ++i)
			cin >> a[i];
		int ans = 1;
		for(int i = 1; i <= n; ++i) {
			f[i] = 1;
			for(int j = 1; j < i; ++j)
				if(a[i] > a[j])
					f[i] = max(f[i], f[j] + 1);
			ans = max(ans, f[i]);
		}
		reverse(a + 1, a + n + 1);
		for(int i = 1; i <= n; ++i) {
			f[i] = 1;
			for(int j = 1; j < i; ++j)
				if(a[i] > a[j])
					f[i] = max(f[i], f[j] + 1);
			ans = max(ans, f[i]);
		}
		cout << ans << '\n';
	}
	cout.flush();
	return 0;
}