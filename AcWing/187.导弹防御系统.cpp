#include <iostream>
using namespace std;

const int N = 53;
int a[N], up[N], down[N], n, ans;

void dfs(const int& u, const int& cntu, const int& cntd) {
	if(cntu + cntd >= ans)
		return;
	if(u > n) {
		ans = cntu + cntd;
		return;
	}
	int k = 1;
	for(; k <= cntu && up[k] >= a[u]; ++k);
	int t = up[k];
	up[k] = a[u];
	if(k <= cntu)
		dfs(u + 1, cntu, cntd);
	else
		dfs(u + 1, cntu + 1, cntd);
	up[k] = t;
	k = 1;
	for(; k <= cntd && down[k] <= a[u]; ++k);
	t = down[k];
	down[k] = a[u];
	if(k <= cntd)
		dfs(u + 1, cntu, cntd);
	else
		dfs(u + 1, cntu, cntd + 1);
	down[k] = t;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	while(cin >> n && n) {
		for(int i = 1; i <= n; ++i)
			cin >> a[i];
		ans = n;
		dfs(1, 0, 0);
		cout << ans << '\n';
	}
	cout.flush();
	return 0;
}