#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	string s;
	cin >> n >> s;
	bool flag = true;
	for(auto& ch: s)
		if(ch == '"')
			flag = !flag;
		else if(flag && ch == ',')
			ch = '.';
	cout << s << endl;
	return 0;
}