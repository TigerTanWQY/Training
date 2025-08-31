#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s, t;
	cin >> s >> t;
	bool flag = true;
	if(s == t)
		flag = false;
	for(int i = 1; flag && i < s.size(); ++i) {
		swap(s[i - 1], s[i]);
		if(s == t)
			flag = false;
		swap(s[i - 1], s[i]);
	}
	if(flag)
		cout << "No";
	else
		cout << "Yes";
	return 0;
}