#include <bits/stdc++.h>
using namespace std;

int a[1000003];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int L, R; m--; ) {
		cin >> L >> R;
		++a[L]; --a[R + 1];
	}
	for(int i = 1; i <= n; ++i)
		a[i] += a[i - 1];
	cout << *min_element(a + 1, a + n + 1) << endl;
	return 0;
}
