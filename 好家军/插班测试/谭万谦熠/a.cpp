#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	int a, b;
	char op;
	cin >> a >> op >> b;
	if(op == '+')
		cout << a + b;
	else if(op == '-')
		cout << a - b;
	cout << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}