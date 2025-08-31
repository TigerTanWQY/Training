#include <iostream>
using namespace std;

int d[1003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int u, v; m--; ) {
		cin >> u >> v;
		++d[u]; ++d[v];
	}
	for(int i = 1; i <= n; ++i)
		cout << d[i] << ' ';
	cout << endl;
	return 0;
}