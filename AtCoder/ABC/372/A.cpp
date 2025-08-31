#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	cin >> s;
	for(const auto& ch: s)
		if(ch != '.')
			cout.put(ch);
	cout << endl;
	return 0;
}