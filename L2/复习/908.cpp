#include <iostream>
#include <bitset>
using namespace std;

bitset<103> vis;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int i = 1, cnt = 0; vis.count() < n; i = i % n + 1) {
		if(!vis[i])
			++cnt;
		if(cnt == m) {
			vis[i] = true;
			cout << i << ' ';
			cnt = 0;
		}
	}
	cout.flush();
	return 0;
}