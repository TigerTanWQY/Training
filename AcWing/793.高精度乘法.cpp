#include <iostream>
#include <cstring>
using namespace std;

const int N = 100003;
char s[N];
int a[N], c[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int b;
	cin >> (s + 1) >> b;
	int la = strlen(s + 1);
	for(int i = 1; i <= la; ++i)
		a[i] = s[la - i + 1] - '0';
	int lc = la + 5;
	for(int i = 1; i <= lc; ++i)
		c[i] = a[i] * b;
	for(int i = 1; i <= lc; ++i) {
		c[i + 1] += c[i] / 10;
		c[i] %= 10;
	}
	for(; lc > 1 && !c[lc]; --lc);
	for(int i = lc; i; --i)
		cout << c[i];
	return 0;
}