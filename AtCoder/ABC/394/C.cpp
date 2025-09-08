#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	cin >> s;
	for(int i = 1; i < s.size(); ++i)
		if(s[i - 1] == 'W' && s[i] == 'A') {
			s[i - 1] = 'A';
			s[i] = 'C';
			if(i - 1 >= 1)
				i -= 2;
		}
	cout << s << endl;
	return 0;
}
