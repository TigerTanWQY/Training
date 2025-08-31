#include <iostream>
#include <set>
using namespace std;

set<int> st[2][400'003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, q;
	cin >> n >> m >> q;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j) {
			// 这里 n*m<=4*10^5, 不是 n,m<=4*10^5, 所以不会 TLE 或 MLE!!
			// 这样写会比赛时 much easier!!
			st[0][i].insert(j);
			st[1][j].insert(i);
		}
	int cnt = 0;
	for(int x, y; q--; ) {
		cin >> x >> y;
		if(st[0][x].count(y)) { // 存在墙
			st[0][x].erase(y);
			st[1][y].erase(x);
			++cnt;              // 直接炸掉
		} else {
			auto cit = st[1][y].upper_bound(x);
			if(cit != st[1][y].cbegin()) { // Up
				int z = *(--cit);
				st[0][z].erase(y);
				st[1][y].erase(z);
				++cnt;
			}
			cit = st[1][y].upper_bound(x); // 不能省略 !!qwq
			// 因为“上面”(Up) 会删掉元素
			// ++cit 会 UB
			// 下同
			if(cit != st[1][y].cend()) { // Down
				int z = *cit;
				st[0][z].erase(y);
				st[1][y].erase(z);
				++cnt;
			}
			cit = st[0][x].upper_bound(y);
			if(cit != st[0][x].cbegin()) { // Left
				int z = *(--cit);
				st[0][x].erase(z);
				st[1][z].erase(x);
				++cnt;
			}
			cit = st[0][x].upper_bound(y);
			if(cit != st[0][x].cend()) { // Right
				int z = *cit;
				st[0][x].erase(z);
				st[1][z].erase(x);
				++cnt;
			}
		}
	}
	cout << n * m - cnt << endl;
	return 0;
}