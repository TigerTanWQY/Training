#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100003;
char s[N];
int a[N], b[N], c[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> (s + 1);
	int la = strlen(s + 1);
	for(int i = 1; i <= la; ++i)
		a[i] = s[la - i + 1] - '0';
	cin >> (s + 1);
	int lb = strlen(s + 1);
	for(int i = 1; i <= lb; ++i)
		b[i] = s[lb - i + 1] - '0';
	int lc = max(la, lb) + 1;
	for(int i = 1; i <= lc; ++i) {
		c[i] += a[i] + b[i];
		c[i + 1] = c[i] / 10;
		c[i] %= 10;
	}
	for(; lc > 1 && !c[lc]; --lc);
	for(int i = lc; i; --i)
		cout << c[i];
	return 0;
}