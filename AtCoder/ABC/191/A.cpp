#include <iostream>
using namespace std;
// BV1HV411Z7HH
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if(a * b <= d && d <= a * c)
		cout << "No";
	else
		cout << "Yes";
	return 0;
}