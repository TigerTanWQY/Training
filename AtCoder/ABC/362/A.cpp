#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int r, g, b;
	string c;
	cin >> r >> g >> b >> c;
	if(c == "Red")
		cout << min(g, b);
	else if(c == "Green")
		cout << min(r, b);
	else if(c == "Blue")
		cout << min(r, g);
	cout << endl;
	return 0;
}