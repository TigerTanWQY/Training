#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	string s;
	cin >> n >> s;
	s = '$' + s;
	int ans = 1;
	for(int L = 2, cnt = 1; L <= n; ++L)
		if(s[L] != s[L - 1]) {
			if(cnt & 1) {
				++ans;
				cnt = 1;
			} else {
				if(s[L] == 'R')
					ans += (s[L - 1] == 'S');
				else if(s[L] == 'P')
					ans += (s[L - 1] == 'R');
				else if(s[L] == 'S')
					ans += (s[L - 1] == 'P');
				cnt = 0;
			}
		} else {
			++cnt;
			if(cnt & 1)
				++ans;
		}
	cout << ans;
	cout.flush();
	return 0;
}
/*
R S P
S P R

R S P S R P R P R P S P R S P S R S P R S P R S
S P R P S R R R R R P P R P R P S S R S P R S S
+ + + + + +   +   + +     + + + +   + + + + +
*/