#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

bitset<1003> b;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int i = 1, x; i <= m; ++i) {
		cin >> x;
		b[x] = true;
	}
	vector<int> ans;
	for(int i = 1; i <= n; ++i)
		if(!b[i])
			ans.push_back(i);
	cout << ans.size() << '\n';
	for(const auto& x: ans)
		cout << x << ' ';
	cout << endl;
	return 0;
}
