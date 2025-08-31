#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

unordered_map<int, unordered_set<int>> mp[2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, q;
	cin >> n >> m >> q;
	long long cnt = 0;
	for(int x, y; q--; ) {
		cin >> x >> y;
		if(!mp[0][x].count(y)) {
			mp[0][x].insert(y);
			mp[1][y].insert(x);
			++cnt;
		} else {
			for(int i = x - 1; i; --i)
				if(!mp[0][i].count(y)) {
					mp[0][i].insert(y);
					mp[1][y].insert(i);
					++cnt;
					break;
				}
			for(int i = x + 1; i <= n; ++i)
				if(!mp[0][i].count(y)) {
					mp[0][i].insert(y);
					mp[1][y].insert(i);
					++cnt;
					break;
				}
			for(int j = y - 1; j; --j)
				if(!mp[1][j].count(x)) {
					mp[0][x].insert(j);
					mp[1][j].insert(x);
					++cnt;
					break;
				}
			for(int j = y + 1; j <= m; ++j)
				if(!mp[1][j].count(x)) {
					mp[0][x].insert(j);
					mp[1][j].insert(x);
					++cnt;
					break;
				}
		}
	}
	cout << (long long)n * m - cnt;
	cout.flush();
	return 0;
}