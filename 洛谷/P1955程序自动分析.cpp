#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

const int N = 100003;
int fa[4 * N];

int fnd(const int& x) {
	if(fa[x] != x)
		fa[x] = fnd(fa[x]);
	return fa[x];
}

bool same(const int& x, const int& y)
{ return fnd(x) == fnd(y); }

void mrge(const int& x, const int& y) {
	if(same(x, y))
		return;
	fa[fnd(x)] = fnd(y);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int _T;
	cin >> _T;
	for(int n; _T--; ) {
		cin >> n;
		vector<array<int, 3>> op;
		vector<int> var;
		for(int u, v, w; n--; ) {
			cin >> u >> v >> w;
			op.push_back({u, v, w});
			var.push_back(u);
			var.push_back(v);
		}
		sort(var.begin(), var.end());
		var.erase(unique(var.begin(), var.end()), var.cend());
		n = var.size();
		for(int i = 0; i <= 2 * n; ++i)
			fa[i] = i;
		bool flag = true;
		for(auto [u, v, w]: op) {
			u = lower_bound(var.cbegin(), var.cend(), u) - var.cbegin() + 1;
			v = lower_bound(var.cbegin(), var.cend(), v) - var.cbegin() + 1;
			if(w)
				mrge(u, v);
			else {
				if(same(u, v)) {
					flag = false;
					break;
				}
				mrge(u + n, v + n);
			}
		}
		if(flag)
			cout << "YES";
		else
			cout << "NO";
		cout << '\n';
	}
	cout.flush();
	return 0;
}