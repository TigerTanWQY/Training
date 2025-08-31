#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 3e5 + 3;
bitset<N> vis;
int a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int _T;
	cin >> _T;
	for(int n, m, k; _T--; cout.put('\n')) {
		cin >> n >> m >> k;
		for(int i = 1; i <= n; ++i)
			vis[i] = false;
		for(int i = 1; i <= m; ++i)
			cin >> a[i];
		for(int i = 1, x; i <= k; ++i) {
			cin >> x;
			vis[x] = true;
		}
		if(k < n - 1) {
			for(int _ = m; _--; )
				cout.put('0');
			continue;
		} else if(k == n) {
			for(int _ = m; _--; )
				cout.put('1');
			continue;
		}
		int id = 0;
		for(int i = 1; !id && i <= n; ++i)
			if(!vis[i])
				id = i;
		for(int i = 1; i <= m; ++i)
			if(a[i] == id)
				cout.put('1');
			else
				cout.put('0');
	}
	cout << endl;
	return 0;
}
