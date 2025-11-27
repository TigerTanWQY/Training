#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 3003;
char s[N];
int mn[N], mx[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		mn[i] = 27;
		cin >> s;
		for(int j = m; j; --j)
			swap(s[j], s[j-1]);
		for(int j = 1; j <= m; ++j) {
			mn[i] = min(mn[i], s[j] - 'a' + 1);
			mx[i] = max(mx[i], s[j] - 'a' + 1);
		}
	}
	for(int i = 1; i <= n; ++i) {
		bool res = 1;
		for(int j = 1; j <= n; ++j)
			res &= (i == j || mn[i] < mx[j]);
		cout << res;
	}
	cout << endl; return 0;
}
