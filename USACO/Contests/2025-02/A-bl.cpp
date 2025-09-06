#include <bits/stdc++.h>
using namespace std;

int a[100003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int _T;
	cin >> _T;
	for(int n; _T--; cout.put('\n')) {
		cin >> n;
		a[0] = a[n + 1] = 0;
		for(int i = 1; i <= n; ++i)
			cin >> a[i];
		vector<int> ans;
		for(int i = 1; i <= n; ++i) {
			for(int j = i; j > 1; --j)
				swap(a[j], a[j - 1]);
			int mx1 = -0x3f3f3f3f, pos = -1;
			for(int j = 1; j <= n; ++j)
				if(a[j] > mx1) {
					mx1 = a[j];
					pos = j;
				}
			int mx2 = -0x3f3f3f3f;
			vector<int> res;
			for(int j = n; j >= pos; --j)
				if(a[j] >= mx2)
					res.push_back(mx2 = a[j]);
			ans = max(ans, res);
			for(int j = 1; j < i; ++j)
				swap(a[j], a[j + 1]);
		}
		for(int i = ans.size() - 1; i >= 0; --i)
			cout << ans[i] << ' ';
	}
	cout.flush();
	return 0;
}
