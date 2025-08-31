#include <iostream>
using namespace std;

int a[10003], n, m;

void dfs(const int p) {
	if(p > n)
		return;
	for(int i = 1; i <= m; ++i) {
		a[p] = i;
		for(int j = 1; j <= p; cout.put(' '), ++j)
			cout << a[j];
		cout.put('\n');
		dfs(p + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	dfs(1);
	cout.flush();
	return 0;
}