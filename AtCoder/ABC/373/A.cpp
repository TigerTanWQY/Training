#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	const int n = 12;
	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		string s;
		cin >> s;
		if(s.size() == i)
			++ans;
	}
	cout << ans << endl;
	return 0;
}