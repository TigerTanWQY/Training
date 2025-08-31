#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	string t = s.substr(s.size() - 2, 2);
	if(t == "er")
		cout << "er";
	else
		cout << "ist";
	return 0;
}