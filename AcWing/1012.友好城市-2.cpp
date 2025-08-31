#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

const int N = 200003;
pair<int, int> a[N];
int f[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i].first >> a[i].second;
	sort(a + 1, a + n + 1);
	f[0] = 0x3f3f3f3f;
	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		int L = 0, R = ans + 1;
		while(L + 1 < R) {
			int M = (L + R) / 2;
			if(f[M] < a[i].second)
				L = M;
			else
				R = M;
		}
		int x = L + 1;
		ans = max(ans, x);
		f[x] = a[i].second;
	}
	cout << ans;
	cout.flush();
	return 0;
}