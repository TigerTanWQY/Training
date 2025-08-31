#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int ans = 0;
	for(string s; cin >> s; )
		ans += s.size();
	cout << ans << endl;
	return 0;
}