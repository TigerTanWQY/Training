#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a, b, d;
	cin >> a >> b >> d;
	for(int i = a; i <= b; i += d)
		cout << i << ' ';
	return 0;
}