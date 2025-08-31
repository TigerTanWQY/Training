#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int m; n--; cout.put('\n')) {
		cin >> m;
		int cnt = 0;
		for(int _ = m, tp; _--; ) {
			cin >> tp;
			if(tp)
				++cnt;
		}
		cout << fixed << setprecision(3) << 1.0 * (m - cnt) / m;
	}
	cout.flush();
	return 0;
}
