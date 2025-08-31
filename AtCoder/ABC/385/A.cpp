#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a, b, c;
	cin >> a >> b >> c;
	if(a + b == c || a + c == b || b + c == a ||
		(a == b && b == c))
		cout << "Yes";
	else
		cout << "No";
	cout << endl;
	return 0;
}
