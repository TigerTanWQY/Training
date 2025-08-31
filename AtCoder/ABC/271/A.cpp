#include <iostream>
#include <string>
using namespace std;

const string s = "0123456789ABCDEF";

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	string ans;
	for(; n; n /= 16)
		ans = s[n % 16] + ans;
	while(ans.size() < 2)
		ans = '0' + ans;
	cout << ans;
	return 0;
}
