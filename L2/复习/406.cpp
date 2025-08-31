#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>
using namespace std;

bitset<10001> vis;
int a[103];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		vis[a[i]] = true;
	}
	vector<int> ans;
	for(int i = 1; i <= n; ++i)
		for(int j = i + 1; j <= n; ++j)
			if(a[i] + a[j] <= 10000 && vis[a[i] + a[j]])
				ans.push_back(a[i] + a[j]);
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.cend());
	cout << ans.size() << endl;
	return 0;
}