#include <bits/stdc++.h>
using namespace std;

char a[103][103], s[10003];

int main() {
	int n, m, x, y;
	scanf("%d%d%d%d", &n, &m, &x, &y);
	for(int i = 1; i <= n; ++i)
		scanf("%s", a[i] + 1);
	scanf("%s", s + 1);
	set<pair<int, int>> ans;
	if(a[x][y] == '@')
		ans.insert({x, y});
	for(int i = 1; i <= strlen(s + 1); ++i) {
		auto ch = s[i];
		if(ch == 'U') {
			if(x >= 2 && a[x - 1][y] != '#') {
				--x;
				if(a[x][y] == '@')
					ans.insert({x, y});
			}
		} else if(ch == 'D') {
			if(x < n && a[x + 1][y] != '#') {
				++x;
				if(a[x][y] == '@')
					ans.insert({x, y});
			}
		} else if(ch == 'L') {
			if(y >= 2 && a[x][y - 1] != '#') {
				--y;
				if(a[x][y] == '@')
					ans.insert({x, y});
			}
		} else {
			if(y < m && a[x][y + 1] != '#') {
				++y;
				if(a[x][y] == '@')
					ans.insert({x, y});
			}
		}
	}
	printf("%d %d %llu\n", x, y, ans.size());
	return 0;
}
