#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	int t = stoi(s.substr(3));
	if(0 < t && t < 350 && t != 316)
		cout << "Yes";
	else
		cout << "No";
	return 0;
}