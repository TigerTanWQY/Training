#include <bits/stdc++.h>
using namespace std;

int a[500003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	multiset<int> st;
	for(int i = 1, cnt = 0; i <= n; ++i) {
		a[i] += st.size();
		st.insert(a[i] + i - 1);
		st.erase(cbegin(st), st.lower_bound(++cnt));
		a[i] -= n - i;
		a[i] = max(a[i], 0);
		cout << a[i] << ' ';
	}
	cout << endl;
	return 0;
}
