#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1003;
int a[N], f[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n = 0;
	while(cin >> a[++n]);
	--n;
	f[0] = 0x3f3f3f3f;
	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		int L = 0, R = ans + 1;
		while(L + 1 < R) {
			int M = (L + R) / 2;
			if(f[M] >= a[i])
				L = M;
			else
				R = M;
		}
		int x = L + 1;
		ans = max(ans, x);
		f[x] = a[i];
	}
	cout << ans << '\n';
	ans = 0;
	memset(f, 0, sizeof(f));
	for(int i = 1; i <= n; ++i) {
		int L = 0, R = ans + 1;
		while(L + 1 < R) {
			int M = (L + R) / 2;
			if(f[M] < a[i])
				L = M;
			else
				R = M;
		}
		int x = L + 1;
		ans = max(ans, x);
		f[x] = a[i];
	}
	cout << ans;
	cout.flush();
	return 0;
}