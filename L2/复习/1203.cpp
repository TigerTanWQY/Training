#include <iostream>
#include <algorithm>
using namespace std;

struct Data {
	int id, scr;
	bool operator<(const Data& x) const {
		if(scr != x.scr)
			return scr > x.scr;
		else
			return id < x.id;
	}
} a[5003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	m = min(n, m + (m >> 1));
	for(int i = 1; i <= n; ++i)
		cin >> a[i].id >> a[i].scr;
	sort(a + 1, a + n + 1);
	int scr = a[m].scr, cnt = 0;
	for(int i = 1; i <= n; ++i)
		if(a[i].scr >= scr)
			++cnt;
		else
			break;
	cout << scr << ' ' << cnt << '\n';
	for(int i = 1; i <= cnt; ++i)
		cout << a[i].id << ' ' << a[i].scr << '\n';
	cout.flush();
	return 0;
}