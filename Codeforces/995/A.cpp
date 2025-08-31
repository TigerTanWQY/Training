#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 103;
int a[N], b[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int _T;
	cin >> _T;
	for(int n; _T--; cout.put('\n')) {
		cin >> n;
		for(int i = 1; i <= n; ++i)
			cin >> a[i];
		for(int i = 1; i <= n; ++i)
			cin >> b[i];
		b[n + 1] = 0;
		int ans = 0;
		for(int i = 1; i <= n; ++i)
			if(a[i] > b[i + 1])
				ans += a[i] - b[i + 1];
		cout << ans;
	}
	cout.flush();
	return 0;
}
