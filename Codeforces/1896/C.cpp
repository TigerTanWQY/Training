#include <iostream>
#include <algorithm>
using namespace std;

const int N = 200003;
struct Data
{ int id, v; }
a[N];
int b[N], ans[N], n, k;

bool cmp1(const Data& x, const Data& y)
{ return x.v > y.v; }

bool cmp2(const Data& x, const Data& y)
{ return x.v < y.v; }

bool solve() {
	sort(a + 1, a + n + 1, cmp1);
	sort(b + 1, b + n + 1);
	sort(a + 1, a + k + 1, cmp2);
	for(int i = 1; i <= k; ++i) {
		if(a[i].v <= b[i])
			return false;
		ans[a[i].id] = b[i];
	}
	sort(a + k + 1, a + n + 1, cmp2);
	for(int i = k + 1; i <= n; ++i) {
		if(a[i].v > b[i])
			return false;
		ans[a[i].id] = b[i];
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for(; T--; ) {
		cin >> n >> k;
		for(int i = 1; i <= n; ++i) {
			cin >> a[i].v;
			a[i].id = i;
		}
		for(int i = 1; i <= n; ++i)
			cin >> b[i];
		if(!solve()) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		for(int i = 1; i <= n; ++i)
			cout << ans[i] << ' ';
		cout << '\n';
	}
	return 0;
}