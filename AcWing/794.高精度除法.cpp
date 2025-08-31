#include <iostream>
#include <cstring>
using namespace std;

const int N = 100003;
char s[N];
int a[N], d[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int b;
	cin >> (s + 1) >> b;
	int la = strlen(s + 1);
	for(int i = la; i; --i)
		a[i] = s[la - i + 1] - '0';
	int lc = la, r = 0;
	for(int i = lc; i; --i) {
		r = r * 10 + a[i];
		d[i] = r / b;
		r %= b;
	}
	for(; lc > 1 && !d[lc]; --lc);
	for(int i = lc; i; --i)
		cout << d[i];
	cout << '\n' << r;
	return 0;
}