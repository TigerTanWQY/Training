#include <iostream>
#include <algorithm>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
#define k first
#define w second

constexpr const int N = 100'003;
PII p[N];
int a[N], sz[N];
LL s[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++i)
		s[i] = s[i - 1] + a[i];
	for(int i = 1; i <= m; ++i)
		cin >> p[i].k >> p[i].w;
	sort(p + 1, p + m + 1, [&](const PII& x, const PII& y) { return x.w < y.w; });
	int t1 = min((int) (upper_bound(a + 1, a + n + 1, p[1].w) - a - 1), p[1].k) + 1;
	sz[1] = t1 - 1;
	for(int i = 2, t2 = 1; i <= m; ++i) {
		int len = p[i].k;
		sz[i] = p[i].k;
		while(len > 0) {
			while(t1 <= n && a[t1] <= p[t2].w && len > 0) {
				++t1;
				--len;
			}
			if(len >= sz[t2]) {
				len -= sz[t2];
				sz[t2++] = 0;
			} else {
				sz[t2] -= len;
				len = 0;
			}
		}
	}
	LL ans = s[n] - s[t1 - 1];
	for(int i = 1; i <= m; ++i)
		ans += (LL)p[i].w * sz[i];
	cout << ans;
	cout.flush();
	return 0;
}