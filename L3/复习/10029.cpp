#include <iostream>
#include <cstdlib>
#include <string>
#include <bitset>
#include <set>
using namespace std;

set<string> st;
bitset<11> vis;
string a[11], t;
int n, m, tot = 0;

void dfs(const int p, const string s, const int cnt) {
	if(s.size() > 16)
		return;
	else if(p > n) {
		if(st.find(s) == st.end() && s.size() >= 3) {
			cout << s << endl;
			exit(0);
		}
		return;
	}
	for(int i = 1; i <= n; i++)
		if(!vis[i]) {
			string tmp;
			for(int j = 1; j <= 16; j++) {
				tmp += '_';
				if(tot + cnt + j + n - p - 1 <= 16) {
					vis[i] = true;
					dfs(p + 1, s + tmp + a[i], cnt + j);
					vis[i] = false;
				} else
					break;
			}
		}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		tot += a[i].size();
	}
	for(int i = 1; i <= m; ++i) {
		cin >> t;
		st.insert(t);
	}
	for(int i = 1; i <= n; i++) {
		vis[i] = true;
		dfs(2, a[i], 0);
		vis[i] = false;
	}
	cout << "-1" << endl;
	return 0;
}