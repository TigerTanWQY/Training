#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1e5 + 3;
int a[N], b[N], ans[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int _T;
	cin >> _T;
	for(int n; _T--; cout.put('\n')) {
		cin >> n;
		for(int i = 1; i <= n; ++i) {
			cin >> a[i];
			b[i] = a[i];
		}
		sort(b + 1, b + n + 1, greater<>());
		int id = 0;
		for(int i = 1; !id && i <= n; ++i)
			if(a[i] != b[i])
				id = i;
		for(int i = max_element(a + id, a + n + 1) - a; i > id; --i)
			swap(a[i], a[i - 1]);
		int mx1 = -0x3f3f3f3f, pos = -1;
		for(int i = 1; i <= n; ++i)
			if(a[i] > mx1) {
				mx1 = a[i];
				pos = i;
			}
		int m = 0, mx2 = -0x3f3f3f3f;
		for(int i = n; i >= pos; --i)
			if(a[i] >= mx2)
				ans[++m] = mx2 = a[i];
		for(int i = m; i; --i) {
			cout << ans[i];
			if(i != 1)
				cout.put(' ');
		}
	}
	cout.flush();
	return 0;
}
