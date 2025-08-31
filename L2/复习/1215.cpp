#include <iostream>
#include <cmath>
using namespace std;
using LL = long long;

int a[100003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, p1, s1, s2;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	cin >> m >> p1 >> s1 >> s2;
	a[p1] += s1;
	LL tot1 = 0, tot2 = 0;
	for(int i = 1; i < m; ++i)
		tot1 += (LL)a[i] * (m - i);
	for(int i = m + 1; i <= n; ++i)
		tot2 += (LL)a[i] * (i - m);
	int p2 = 0;
	LL ans1 = 0x3f3f3f3f3f3f3f3f, ans2 = -0x3f3f3f3f3f3f3f3f;
	for(int i = 1; i <= n; ++i) {
		if(i < m)
			tot1 += (LL)s2 * (m - i);
		else if(i > m)
			tot2 += (LL)s2 * (i - m);
		if(abs(tot1 - tot2) < abs(ans1 - ans2)) {
			ans1 = tot1;
			ans2 = tot2;
			p2 = i;
		}
		if(i < m)
			tot1 -= (LL)s2 * (m - i);
		else if(i > m)
			tot2 -= (LL)s2 * (i - m);
	}
	cout << p2 << endl;
	return 0;
}