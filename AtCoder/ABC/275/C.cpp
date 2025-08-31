#include <iostream>
#include <set>
#include <utility>
using namespace std;
using PII = pair<int, int>;

char s[12][12];

bool valid(const int& x, const int& y)
{ return 0 <= x && x < 9 && 0 <= y && y < 9 && s[x][y] == '#'; }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	for(int i = 0; i < 9; ++i)
		cin >> s[i];
	set<set<PII>> st;
	for(int i = 0; i < 9; ++i)
		for(int j = 0; j < 9; ++j)
			for(int dx = -8; dx < 9; ++dx)
				for(int dy = -8; dy < 9; ++dy) {
					if(!dx && !dy)
						continue;
					int i2 = i + dx, j2 = j + dy, i3 = i2 - dy, j3 = j2 + dx, i4 = i3 - dx, j4 = j3 - dy;
					if(valid(i, j) && valid(i2, j2) && valid(i3, j3) && valid(i4, j4)) {
						set<PII> tmp;
						tmp.insert({i, j});
						tmp.insert({i2, j2});
						tmp.insert({i3, j3});
						tmp.insert({i4, j4});
						st.insert(tmp);
					}
				}
	cout << st.size();
	return 0;
}