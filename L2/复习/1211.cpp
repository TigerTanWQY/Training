#include <iostream>
#include <string>
using namespace std;

constexpr const int day[]{-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

inline bool isp(const string& s) {
	for(int i = 0, j = s.size() - 1; i < j; ++i, --j)
		if(s[i] != s[j])
			return false;
	return true;
}

inline bool isl(const int& y)
{ return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0; }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int L, R;
	cin >> L >> R;
	int y = L / 10000, m = L / 100 % 100, d = L % 100, ans = 0;
	for(; y * 10000 + m * 100 + d <= R; ) {
		if(isp(to_string(y * 10000 + m * 100 + d)))
			++ans;
		++d;
		if(m == 2) {
			if(isl(y)) {
				if(d > 29) {
					++m;
					d = 1;
				}
			} else
				if(d > 28) {
					++m;
					d = 1;
				}
		} else
			if(d > day[m]) {
				++m;
				d = 1;
			}
		if(m > 12) {
			++y;
			m = 1;
		}
	}
	cout << ans << endl;
	return 0;
}