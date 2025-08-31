#include <iostream>
using namespace std;

int f[10000003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		char ch;
		cin >> ch;
		f[i] = ch - '0';
	}
	int len = n;
	for(char op; m--; ) {
		cin >> op;
		if(op == '*')
			f[++len] = 0;
		else if(op == '+')
			++f[len];
		else if(op == '-')
			--f[len];
		else {
			f[len - 1] += f[len] >> 1;
			--len;
		}
	}
	for(int i = len; i > 1; --i) {
		f[i - 1] += f[i] >> 1;
		f[i] &= 1;
	}
	for(int i = 1; i <= len; ++i)
		cout << f[i];
	cout << endl;
	return 0;
}