#include <iostream>
using namespace std;

const int d[2][4]{{0, 150, 888, 275}, {0, 300, 1600, 600}};
int a[10], n, m, ans = 0;

void dfs(const int& u) {
	if(u > 7) {
		int cntc = 0, cntz = 0;
		for(int i = 1; i <= 7; ++i) {
			cntc += d[0][a[i]];
			cntz += d[1][a[i]];
		}
		if(cntc <= n && cntz >= m)
			++ans;
		return;
	}
	a[u] = 0;
	dfs(u + 1);
	a[u] = 1;
	dfs(u + 1);
	a[u] = 2;
	dfs(u + 1);
	a[u] = 3;
	dfs(u + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	dfs(1);
	cout << ans;
	return 0;
}