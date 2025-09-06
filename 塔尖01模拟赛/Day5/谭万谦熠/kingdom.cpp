#include <bits/stdc++.h>
using namespace std;

int a[500003];

int main() {
	freopen("kingdom.in", "r", stdin);
	freopen("kingdom.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	vector<int> d;
	int mx = -1;
	for(int i = 0; i < n; ++i) {
		int L = i - 1, R = i + 1;
		for(; L >= 0 && a[L] % a[i] == 0; --L); ++L;
		for(; R < n && a[R] % a[i] == 0; ++R); --R;
		int len = R - L;
		if(len > mx) {
			mx = len;
			d.clear();
			d.push_back(L);
		} else if(len == mx)
			d.push_back(L);
	}
	cout << d.size() << ' ' << mx << '\n';
	for(const auto& x: d)
		cout << x + 1 << ' ';
	cout << endl;
	return 0;
}
