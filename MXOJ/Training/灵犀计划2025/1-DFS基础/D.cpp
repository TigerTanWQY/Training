#include <iostream>
using namespace std;

constexpr const int N = 30;
bool b[N], c[N], d[N];
int a[N], n, cnt = 0;

void dfs(int k) {
	if(k > n) {
		if(cnt < 3) {
			for(int x = 1; x <= n; ++x)
				cout << a[x] << ' ';
			cout.put('\n');
		}
		++cnt;
		return;
	}
	for(int y = 1; y <= n; ++y)
		if(!b[y] && !c[k + y] && !d[k - y + n]) {
			a[k] = y;
			b[y] = c[k + y] = d[k - y + n] = true;
			dfs(k + 1);
			b[y] = c[k + y] = d[k - y + n] = false;
		}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n;
	dfs(1);
	cout << cnt << endl;
	return 0;
}
