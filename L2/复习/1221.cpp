#include <iostream>
#include <algorithm>
using namespace std;
#define _v first
#define _pos second

constexpr const int N = 8003;
pair<int, int> a[N];
int ans[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i]._v;
		a[i]._pos = i;
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++i)
		ans[a[i]._pos] = i;
	for(int op, x, w; q--; ) {
		cin >> op >> x;
		if(op == 2)
			cout << ans[x] << '\n';
		else {
			cin >> w;
			int p = ans[x];
			a[p]._v = w;
			for(int i = p; i < n; ++i)
				swap(a[i], a[i + 1]);
			for(int i = n; i >= 2; --i)
				if(a[i] < a[i - 1])
					swap(a[i], a[i - 1]);
				else
					break;
			for(int i = 1; i <= n; ++i)
				ans[a[i]._pos] = i;
		}
	}
	cout.flush();
	return 0;
}