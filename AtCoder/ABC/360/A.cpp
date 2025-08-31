#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	int i = s.find('R'), j = s.find('M');
	if(i < j)
		cout << "Yes";
	else
		cout << "No";
	cout << endl;
	return 0;
}