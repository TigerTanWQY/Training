#include <bits/stdc++.h>
using namespace std;

int a[200003], b[200003];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0; i < m; ++i)
		cin >> b[i];
	sort(a, a+n);
	sort(b, b+m);
	int cnt = 0;
	for(int i = 0, j = 0; i < n && j < m; ) {
		if(a[i] <= b[j]) {
			++cnt;
			++i;
			++j;
		} else
			++j;
		if(cnt >= k)
			break;
	}
	cout << (cnt >= k? "Yes": "No") << endl;
	return 0;
}
