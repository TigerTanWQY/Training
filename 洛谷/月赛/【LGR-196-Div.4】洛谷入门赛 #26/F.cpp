#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<int, vector<int>> a;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int i = 1, x; i <= n; ++i) {
		cin >> x;
		a[x].push_back(i);
	}
	bool flag = true;
	while(flag && !a.empty())
		for(auto& [p, c]: a) {
			cout << c.back() << '\n';
			c.pop_back();
			if(c.empty())
				flag = false;
		}
	cout.flush();
	return 0;
}