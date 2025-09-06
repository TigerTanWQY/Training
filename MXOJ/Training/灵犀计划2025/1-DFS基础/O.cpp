#include <bits/stdc++.h>
using namespace std;

string a[11];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	do {
		bool flg = true;
		for(int i = 1; flg && i < n; ++i) {
			bool cnt = false;
			for(int j = 0; flg && j < m; ++j)
				if(a[i][j] != a[i + 1][j])
					if(!cnt)
						cnt = true;
					else
						flg = false;
		}
		if(flg) {
			cout << "Yes" << endl;
			return 0;
		}
	} while(next_permutation(a + 1, a + n + 1));
	cout << "No" << endl;
	return 0;
}
