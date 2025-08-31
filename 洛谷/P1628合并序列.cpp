#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> ans;
string a[100003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	string t;
	cin >> t;
	int m = t.size();
	for(int i = 1; i <= n; ++i)
		if(a[i].substr(0, m) == t)
			ans.push_back(a[i]);
	sort(ans.begin(), ans.end());
	for(const auto& s: ans)
		cout << s << '\n';
	return 0;
}