#include <iostream>
#include <string>
using namespace std;

const string a = "ABCD";

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string op, s;
	cin >> op >> s;
	int n = s.size(), cnt = 0;
	for(int i = 0; i < n; ++i) {
		if(op[i] == 'R')
			cnt = (cnt + 3) % 4;
		else
			cnt = (cnt + 1) % 4;
		if(s[i] == 'o')
			cout << a[cnt];
	}
	return 0;
}