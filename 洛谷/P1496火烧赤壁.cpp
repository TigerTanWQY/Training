#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> c;
bool flag[40003];
int a[20003], b[20003], m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i];
		c.push_back(a[i]);
		c.push_back(b[i]);
	}
	sort(c.begin(), c.end());
	c.erase(unique(c.begin(), c.end()), c.cend());
	m = c.size();
	for(int i = 0; i < n; ++i) {
		int L = lower_bound(c.cbegin(), c.cend(), a[i]) - c.cbegin(), R = lower_bound(c.cbegin(), c.cend(), b[i]) - c.cbegin() - 1;
		for(int j = L; j <= R; ++j)
			flag[j] = true;
	}
	long long ans = 0;
	for(int i = 0; i < m; ++i)
		if(flag[i])
			ans += c[i + 1] - c[i];
	cout << ans;
	cout << endl;
	return 0;
}