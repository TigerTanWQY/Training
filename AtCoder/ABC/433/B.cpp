#include <bits/stdc++.h>
using namespace std;

int a[103];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 1; i <= n; ++i) {
		bool flg = true;
		for(int j = i-1; j; --j)
			if(a[j] > a[i]) {
				cout << j << '\n';
				flg = false;
				break;
			}
		if(flg)
			cout << "-1\n";
	}
	cout.flush(); return 0;
}
