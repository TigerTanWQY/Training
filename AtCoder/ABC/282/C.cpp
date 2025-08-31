#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	string s;
	cin >> n >> s;
	bool flag = true;
	for(int i = 0; i < n; ++i) {
		if(s[i] == '"')
			flag = !flag;
		if(flag && s[i] == ',')
			s[i] = '.';
	}
	cout << s;
	return 0;
}