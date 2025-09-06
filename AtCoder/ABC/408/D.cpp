#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int _T;
	cin >> _T;
	for(string s; _T--; cout.put('\n')) {
		int n;
		cin >> n >> s;
		int pre = 0, minn = 0, cnt = 0;
		for(int i = 1; i <= n; ++i) {
			if(s[i - 1] == '1')
				++pre;
			minn = min(minn, 2 * pre - i);
			cnt = min(cnt, minn + i - 2 * pre);
		}
		cout << pre + cnt;
	}
	cout.flush(); return 0;
}
