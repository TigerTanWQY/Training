#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
#define mkp make_pair

constexpr const int N = 2e5 + 3;
struct
{ int g, s, b; }
a[N];
int g[N], s[N], b[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> g[i] >> s[i] >> b[i];
		a[i].g = g[i]; a[i].s = s[i]; a[i].b = b[i];
	}
	sort(g + 1, g + n + 1, greater<>());
	sort(s + 1, s + n + 1, greater<>());
	sort(b + 1, b + n + 1, greater<>());
	for(int i = 1; i <= n; cout.put('\n'), ++i) {
		int id1 = upper_bound(g + 1, g + n + 1, a[i].g + 1, greater<>()) - g,
			id2 = upper_bound(s + 1, s + n + 1, a[i].s + 1, greater<>()) - s,
			id3 = upper_bound(b + 1, b + n + 1, a[i].b + 1, greater<>()) - b;
		cout << min({id1, id2, id3});
	}
	cout.flush();
	return 0;
}