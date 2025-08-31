#include <iostream>
#include <utility>
#include <set>
using namespace std;
using PII = pair<int, int>;

constexpr const int n = 9, N = n + 3;
char s[N][N];

bool valid(const int& x, const int& y)
{ return 0 <= x && x < n && 0 <= y && y < n && s[x][y] == '#'; }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for(int i = 0; i < n; ++i)
		cin >> s[i];
	set<set<PII>> ans;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			for(int dx = -8; dx < n; ++dx)
				for(int dy = -8; dy < n; ++dy) {
					if(!dx && !dy)
						continue;
					const int i2 = i + dx, j2 = j + dy, i3 = i2 - dy, j3 = j2 + dx, i4 = i3 - dx, j4 = j3 - dy;
					if(valid(i, j) && valid(i2, j2) && valid(i3, j3) && valid(i4, j4)) {
						set<PII> st;
						st.insert({i, j});
						st.insert({i2, j2});
						st.insert({i3, j3});
						st.insert({i4, j4});
						ans.insert(st);
					}
				}
	cout << ans.size();
	return 0;
}