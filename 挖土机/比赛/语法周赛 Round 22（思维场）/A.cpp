#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string a, b;
	cin >> b >> a;
	for(int i = 0; i < 3; ++i) {
		if(a[i] == b[i]) {
			cout << '2';
			continue;
		}
		bool flag = true;
		for(int j = 0; flag && j < 3; ++j)
			if(a[i] == b[j]) {
				cout << '1';
				flag = false;
			}
		if(flag)
			cout << '0';
	}
	cout << endl;
	return 0;
}