#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		if(i % 3)
			cout << 'o';
		else
			cout << 'x';
	return 0;
}