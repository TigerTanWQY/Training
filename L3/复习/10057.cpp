#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s, t;
	cin >> s >> t;
	for(int i = 0; i < s.size(); ++i)
		if(s[i] != t[i]) {
			cout << i + 1;
			return 0;
		}
	cout << t.size() << endl;
	return 0;
}