#include <iostream>
#include <string>
using namespace std;

int mp[128], a[10], c[10];

inline int lowbit(const int x)
{ return x & -x; }

inline int query(int x) {
	int res = 0;
	for(; x; x -= lowbit(x))
		res += c[x];
	return res;
}

inline void modify(int x, const int w) {
	for(; x <= 7; x += lowbit(x))
		c[x] += w;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	const string tgt = "$atcoder";
	string s;
	cin >> s;
	s = '$' + s;
	for(int i = 1; i <= 7; ++i)
		mp[tgt[i]] = i;
	for(int i = 1; i <= 7; ++i)
		a[i] = mp[s[i]];
	int ans = 0;
	for(int i = 1; i <= 7; ++i) {
		ans += i - query(a[i]) - 1;
		modify(a[i], 1);
	}
	cout << ans << endl;
	return 0;
}