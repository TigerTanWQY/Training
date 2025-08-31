#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string n;
	cin >> n;
	int m = n.size();
	sort(n.begin(), n.end());
	long long ans = 0;
	do
		for(int i = 1; i < m; ++i)
			ans = max(ans, 1LL * stoi(n.substr(0, i)) * stoi(n.substr(i)));
	while(next_permutation(n.begin(), n.end()));
	cout << ans;
	return 0;
}