#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a, b, c;
	cin >> a >> b >> c;
	if(b > c)
		c += 24;
	if((b <= a && a <= c) || (b <= a + 24 && a + 24 <= c))
		cout << "No";
	else
		cout << "Yes";
	cout.flush();
	return 0;
}