#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL a[500003];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	if(m >= n) {
		cout.put('0') << endl;
		return 0;
	}
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a, a + n);
	LL tot = a[n - 1] - a[0];
	vector<LL> f;
	for(int i = 0; i < n - 1; ++i)
		f.push_back(a[i+1] - a[i]);
	sort(rbegin(f), rend(f));
	LL cnt = 0;
	for(int i = 0; i < m - 1; ++i)
		cnt += f[i];
	cout << tot - cnt << endl;
	return 0;
}
