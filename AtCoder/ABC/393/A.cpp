#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s1, s2;
	cin >> s1 >> s2;
	if(s1 == s2) {
		if(s1 == "sick")
			cout.put('1');
		else
			cout.put('4');
	} else if(s1 == "sick")
		cout.put('2');
	else
		cout.put('3');
	cout << endl;
	return 0;
}
