#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string x, y;
	cin >> x >> y;
	if(y == "Ocelot")
		cout << "Yes";
	else if(y == "Serval")
		cout << (x != "Ocelot"? "Yes": "No");
	else
		cout << (x == "Lynx"? "Yes": "No");
	cout << endl; return 0;
}
