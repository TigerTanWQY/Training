#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 2e5 + 3;
int a[N], b[N], idx[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	a[0] = N - 1; idx[a[0]] = n + 1;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		if(!idx[a[i]])
			idx[a[i]] = i;
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++i)
		idx[a[i]] = min(idx[a[i]], idx[a[i - 1]]);
	for(int x; m--; cout.put('\n')) {
		cin >> x;
		auto it = upper_bound(a + 1, a + n + 1, x);
		if(--it == a)
			cout << "-1";
		else
			cout << idx[*it];
	}
	cout.flush();
	return 0;
}
