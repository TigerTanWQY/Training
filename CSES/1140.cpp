#include <iostream>
#include <algorithm>
using namespace std;
using LL = long long;

constexpr const int N = 2e5 + 3;
struct Project
{ int L, R, w; }
a[N];
int c[N];
LL f[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i].L >> a[i].R >> a[i].w;
	sort(a + 1, a + n + 1, [&](const Project &x, const Project &y) { return x.R < y.R; });
	for(int i = 1; i <= n; ++i)
		c[i] = a[i].R;
	for(int i = 1; i <= n; ++i)
		f[i] = max(f[i - 1], f[lower_bound(c + 1, c + n + 1, a[i].L) - c - 1] + a[i].w);
	cout << f[n] << endl;
    return 0;
}