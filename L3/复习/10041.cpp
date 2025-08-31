#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, nx, ny, k;
	cin >> n >> m >> nx >> ny >> k;
	unordered_map<int, vector<int>> a[2];
	for(int x, y; k--; ) {
		cin >> x >> y;
		a[0][x].push_back(y);
		a[1][y].push_back(x);
	}
	for(int _ = 0; _ < 2; ++_)
		for(auto& [__, c]: a[_])
			sort(c.begin(), c.end());
	cin >> k;
	for(char op; k--; cout.put('\n')) {
		int d;
		cin >> op >> d;
		if(op == 'L')
			if(!a[0].count(nx))
				ny = max(ny - d, 1);
			else {
				auto& c = a[0][nx];
				const auto id = upper_bound(c.cbegin(), c.cend(), ny) - c.cbegin();
				if(id)
					ny = max(ny - d, c[id - 1] + 1);
				else
					ny = max(ny - d, 1);
			}
		else if(op == 'R')
			if(!a[0].count(nx))
				ny = min(ny + d, m);
			else {
				auto& c = a[0][nx];
				const auto id = upper_bound(c.cbegin(), c.cend(), ny) - c.cbegin();
				if(id == c.size())
					ny = min(ny + d, m);
				else
					ny = min(ny + d, c[id] - 1);
			}
		else if(op == 'U')
			if(!a[1].count(ny))
				nx = max(nx - d, 1);
			else {
				auto& c = a[1][ny];
				const auto id = upper_bound(c.cbegin(), c.cend(), nx) - c.cbegin();
				if(id)
					nx = max(nx - d, c[id - 1] + 1);
				else
					nx = max(nx - d, 1);
			}
		else
			if(!a[1].count(ny))
				nx = min(nx + d, n);
			else {
				auto& c = a[1][ny];
				const auto id = upper_bound(c.cbegin(), c.cend(), nx) - c.cbegin();
				if(id == c.size())
					nx = min(nx + d, n);
				else
					nx = min(nx + d, c[id] - 1);
			}
		cout << nx << ' ' << ny;
	}
	cout.flush();
	return 0;
}