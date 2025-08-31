#include <bits/stdc++.h>
using namespace std;

int a[103];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	double ans = 0;
	for(int i = 1; i <= n; ++i) {
		int tot = 0;
		for(int j = 1; j <= n; ++j)
			if(i != j && a[i] % a[j] == 0)
				++tot;
		ans += (tot / 2 + 1.0) / (tot + 1);
	}
	cout << fixed << setprecision(7) << ans << endl;
	return 0;
}
