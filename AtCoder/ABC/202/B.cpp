#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string ans;
	for(char ch; cin >> ch; )
		switch(ch) {
			case '0':
			case '1':
			case '8':
				ans += ch;
				break;
			case '6':
				ans += '9';
				break;
			case '9':
				ans += '6';
				break;
		}
	for(auto cit = ans.crbegin(); cit != ans.crend(); ++cit)
		cout << *cit;
	cout << endl;
	return 0;
}