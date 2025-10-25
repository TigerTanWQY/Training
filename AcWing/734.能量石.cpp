#include <bits/stdc++.h>
using namespace std;

int test_case = 1;
int n,m;
struct node
{ int s,e,l; }
a[103];
int f[100003];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int _T;
	cin >> _T;
	while(_T--) {
		memset(f, -0x3f, sizeof f);
		f[0] = m = 0;
		cin >> n;
		for (int i = 1;i <= n;i++) {
			cin >> a[i].s >> a[i].e >> a[i].l;
			m += a[i].s;
		}
		sort (a + 1,a + 1 + n,[](node x,node y) {
			return x.s * y.l < x.l * y.s;
		});
		for (int i = 1;i <= n;i++) {
			for (int j = m;j >= a[i].s;j--) f[j] = max (f[j],f[j - a[i].s] + a[i].e - (j - a[i].s) * a[i].l);
		}
		int ans = 0;
		for (int i = 0;i <= m;i++) ans = max (ans,f[i]);
		cout << "Case #" << test_case++ << ": " << ans << '\n';
	}
	cout.flush(); return 0;
}
