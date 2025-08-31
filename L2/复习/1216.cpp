#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	cin >> s;
	cout << count(s.cbegin(), s.cend(), '1') << endl;
	return 0;
}