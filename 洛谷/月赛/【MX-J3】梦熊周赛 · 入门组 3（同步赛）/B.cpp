#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a, b;
	string s;
	cin >> a >> b >> s;
	if(a + b > s.size()) {
		cout << "-1" << endl;
		return 0;
	}
	int cnts = 0, cntt = 0;
	for(const auto& ch: s)
		if(ch == 'S')
			++cnts;
		else if(ch == 'T')
			++cntt;
	if(cnts >= a && cntt >= b)
		cout.put('0');
	else if(cnts >= a)
		cout << b - cntt;
	else if(cntt >= b)
		cout << a - cnts;
	else
		cout << "-1";
	cout << endl;
	return 0;
}