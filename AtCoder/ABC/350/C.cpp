#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 200003;
int a[N], p[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 1; i <= n; ++i)
		p[a[i]] = i;
	vector<pair<int, int>> ans;
	for(int i = 1; i < n; ++i)
		if(p[i] != i) {
			int j = p[i];
			ans.push_back({i, j});
			swap(a[i], a[j]);
			swap(p[i], p[a[j]]);
		}
	cout << ans.size() << '\n';
	for(const auto& x: ans)
		cout << x.first << ' ' << x.second << '\n';
	return 0;
}