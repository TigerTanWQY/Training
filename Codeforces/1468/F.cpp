#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for(int n; T--; ) {
		cin >> n;
		unordered_map<int, unordered_map<int, int>> cnt;
		for(int i = 1, k; i <= n; ++i) {
			cin >> k;
			for(int _ = 0, x; _ < k; ++_) {
				cin >> x;
				++cnt[i][x];
			}
		}
		for(int i = 1; i <= n; ++i)
			;
	}
	return 0;
}