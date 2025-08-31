#include <bits/stdc++.h>
using namespace std;

bitset<1003> vis;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int id, tp; n--; ) {
		cin >> id >> tp;
		vis[id] = vis[id] | (bool)tp;
	}
	cout << vis.count() << endl;
	return 0;
}
