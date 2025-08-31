#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s, t;
	cin >> s >> t;
	if(t.substr(0, s.size()) == s)
		cout << "Yes";
	else
		cout << "No";
	return 0;
}
