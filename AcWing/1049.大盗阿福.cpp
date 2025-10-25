#include <bits/stdc++.h>
using namespace std;

int a[100003], f[100003];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int _T;
	cin >> _T;
	for(int n; _T--; cout.put('\n')) {
		cin >> n;
		for(int i = 1; i <= n; ++i)
			cin >> a[i];
		f[1] = a[1]; f[2] = a[2];
		int mx = f[1];
		for(int i = 3; i <= n; ++i) {
			f[i] = mx + a[i];
			mx = max(mx, f[i-1]);
		}
		cout << max(f[n-1], f[n]);
//		for(int i = 1; i <= n; ++i)
//			f[i] = 0;
	}
	cout.flush(); return 0;
}
