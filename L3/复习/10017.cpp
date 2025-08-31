#include <iostream>
#include <bitset>
using namespace std;

int c[13], n, m;

void dfs(const int p, const int lst) {
	if(p > n) {
		for(int i = 1; i <= n; ++i)
			cout << c[i] << ' ';
		cout.put('\n');
		return;
	} else if(lst == m)
		return;
	for(int i = lst + 1; i <= m; ++i) {
		c[p] = i;
		dfs(p + 1, i);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	dfs(1, 0);
	cout << endl;
	return 0;
}