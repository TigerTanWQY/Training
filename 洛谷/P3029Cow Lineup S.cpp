#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

const int N = 50'003;
struct Node {
	int pos, id;
	bool operator<(const Node& x) const
	{ return pos < x.pos; }
} a[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	unordered_set<int> s;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i].pos >> a[i].id;
		s.insert(a[i].id);
	}
	sort(a + 1, a + n + 1);
	unordered_map<int, int> cnt;
	++cnt[a[1].id];
	int ans = 0x3f3f3f3f, m = s.size();
	for(int i = 1, j = 1, tot = 1; i <= n; ++i) {
		while(tot < m && j < n) {
			++cnt[a[++j].id];
			if(cnt[a[j].id] == 1)
				++tot;
		}
		if(tot == m)
			ans = min(ans, a[j].pos - a[i].pos);
		--cnt[a[i].id];
		if(!cnt[a[i].id])
			--tot;
	}
	cout << ans;
	cout << endl;
	return 0;
}