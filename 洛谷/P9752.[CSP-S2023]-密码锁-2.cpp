#include <bits/stdc++.h>
using namespace std;

string a[11], s;
int n, ans = 0;

bool chk() {
	for(int i = 0; i < n; ++i) {
		int x = -1;
		for(int k = 0; k < 5; ++k)
			if(s[k] != a[i][k])
				if(x == -1)
					x = k;
				else if(k != x+1)
					return false;
		if(x == -1 || (x+1 < 5 && s[x+1] != a[i][x+1] && (s[x+1]-a[i][x+1]+10) % 10 != (s[x]-a[i][x]+10) % 10))
			return false;
	}
	return true;
}

void dfs(int p) {
	if(p == 5) {
		if(chk())
			++ans;
		return;
	}
	for(int i = 0; i < 10; ++i) {
		s += '0' + i;
		dfs(p+1);
		s.pop_back();
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n;
	for(int i = 0, x; i < n; ++i)
		for(int _ = 5; _--; ) {
			cin >> x;
			a[i] += '0' + x;
		}
	dfs(0);
	cout << ans << endl;
	return 0;
}
