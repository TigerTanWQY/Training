#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 2e5 + 3;
int a[N], b[N], cnt1[N], cnt2[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		++cnt1[a[i]];
	}
	for(int i = 1; i <= n; ++i) {
		cin >> b[i];
		++cnt2[b[i]];
	}
	reverse(b + 1, b + n + 1);
	for(int i = 1; i <= n; ++i)
		if(cnt2[i] > n - cnt1[i]) {
			cout << "No" << endl;
			return 0;
		}
	int L = -1, R = -1, w = -1;
	for(int i = 1; !~L && i <= n; ++i)
		if(a[i] == b[i]) {
			L = i;
			w = a[i];
		}
	for(int i = n; !~R && i; --i)
		if(a[i] == b[i])
			R = i;
	if(!~L) {
		cout << "Yes\n";
		for(int i = 1; i <= n; ++i)
			cout << b[i] << ' ';
		cout << endl;
		return 0;
	}
	for(int i = 1, j = L; i <= n; ++i) {
		if(L <= i && i <= R)
			continue;
		if(a[i] == w || b[i] == w)
			continue;
		swap(b[i], b[j]);
		++j;
		if(j > R) {
			cout << "Yes\n";
			for(int k = 1; k <= n; ++k)
				cout << b[k] << ' ';
			cout << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}
