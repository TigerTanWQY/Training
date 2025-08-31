#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	cin >> s;
	int ans = 0;
	for(auto i = s.find("friend"); i != string::npos; i = s.find("friend", i + 9))
		++ans;
	cout << ans;
	cout.flush();
	return 0;
}