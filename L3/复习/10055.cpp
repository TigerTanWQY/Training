#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<string> s(n), t(n);
	for(int i = 0; i < n; ++i)
		cin >> s[i];
	for(int i = 0; i < n; ++i)
		cin >> t[i];
	vector<string> ts(m), tt(m);
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j) {
			ts[j].push_back(s[i][j]);
			tt[j].push_back(t[i][j]);
		}
	sort(ts.begin(), ts.end());
	sort(tt.begin(), tt.end());
	cout << (ts == tt? "Yes": "No") << endl;
	return 0;
}