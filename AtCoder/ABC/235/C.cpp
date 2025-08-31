#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	unordered_map<int, vector<int>> cnt;
	for(int i = 1, x; i <= n; ++i) {
		cin >> x;
		cnt[x].push_back(i);
	}
	for(int x, k; q--; ) {
		cin >> x >> k;
		if(k > cnt[x].size())
			cout << "-1\n";
		else
			cout << cnt[x][k - 1] << '\n';
	}
	return 0;
}