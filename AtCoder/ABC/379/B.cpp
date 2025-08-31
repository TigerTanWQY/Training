#include <bits/stdc++.h>
using namespace std;

char s[103];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k >> s;
	int ans = 0;
	for(int i = 0, cnt = 0; i < n; ++i) {
		if(s[i] == 'O')
			++cnt;
		else
			cnt = 0;
		if(cnt == k) {
			++ans;
			cnt = 0;
		}
	}
	cout << ans << endl;
	return 0;
}