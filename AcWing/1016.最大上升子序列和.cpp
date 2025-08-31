#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1003;
int a[N], f[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		f[i] = a[i];
		for(int j = 1; j < i; ++j)
			if(a[i] > a[j])
				f[i] = max(f[i], f[j] + a[i]);
		ans = max(ans, f[i]);
	}
	cout << ans;
	cout.flush();
	return 0;
}