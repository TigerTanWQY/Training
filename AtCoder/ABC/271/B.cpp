#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, q;
	cin >> n >> q;
	vector<vector<int>> a(n + 1);
	for(int i = 1, l; i <= n; ++i) {
		cin >> l;
		a[i].push_back(0);
		for(int j = 1, x; j <= l; ++j) {
			cin >> x;
			a[i].push_back(x);
		}
	}
	while(q--) {
		int s, t;
		cin >> s >> t;
		cout << a[s][t] << '\n';
	}
	return 0;
}
