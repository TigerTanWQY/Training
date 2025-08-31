#include <iostream>
using namespace std;

char op[5003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("e.in", "r", stdin);
	freopen("e.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 1; i < n; ++i)
		cin >> op[i];
	cout << (1 << n);
	cout << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}