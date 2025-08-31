#include <iostream>
using namespace std;

bool G[1003][1003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int u, v; m--; ) {
		cin >> u >> v;
		if(u == v || G[u][v]) {
			cout << "No" << endl;
			return 0;
		}
		G[u][v] = G[v][u] = true;
	}
	cout << "Yes" << endl;
	return 0;
}