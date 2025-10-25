#include <bits/stdc++.h>
using namespace std;

int a[18];
long long f[3003];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a+1, a+n+1); // not necessary
	f[0] = 1;
	for(int i = 1; i <= n; ++i)
		for(int j = a[i]; j <= m; ++j)
			f[j] += f[j-a[i]];
	cout << f[m] << endl;
	return 0;
}
