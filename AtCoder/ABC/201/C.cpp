#include <bits/stdc++.h>
using namespace std;

char s[11];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> s;
	int ans = 0;
	for(int i = 0; i < 1e4; ++i) {
		int flag = 0;
		for(int x = i, j = 4; j--; ) {
			flag |= 1 << (x % 10);
			x /= 10;
		}
		bool chk = true;
		for(int j = 0; chk && j < 10; ++j) {
			if(!(flag & 1 << j) && s[j] == 'o')
				chk = false;
			if((flag & 1 << j) && s[j] == 'x')
				chk = false;
		}
		ans += chk;
	}
	cout << ans << endl;
	return 0;
}
