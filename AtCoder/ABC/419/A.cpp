#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	cin >> s;
	if(s == "red")
		cout << "SSS";
	else if(s == "blue")
		cout << "FFF";
	else if(s == "green")
		cout << "MMM";
	else
		cout << "Unknown";
	cout << endl;
	return 0;
}
