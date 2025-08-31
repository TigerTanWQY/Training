#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	cin >> s;
	cout << s;
	if(s.back() == 's')
		cout << "es";
	else
		cout.put('s');
	cout << endl;
	return 0;
}