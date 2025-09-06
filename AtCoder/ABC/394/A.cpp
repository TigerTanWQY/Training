#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	cin >> s;
	for(const auto& ch: s)
		if(ch == '2')
			cout.put('2');
	cout << endl;
	return 0;
}
