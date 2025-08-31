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
	bool neg = false;
	if(la < lb) {
		for(int i = 1; i <= la; ++i)
			c[i] = a[i];
		for(int i = 1; i <= lb; ++i)
			a[i] = b[i];
		for(int i = lb + 1; i < N; ++i)
			a[i] = 0;
		for(int i = 1; i <= la; ++i) {
			b[i] = c[i];
			c[i] = 0;
		}
		for(int i = la + 1; i < N; ++i)
			b[i] = c[i] = 0;
		swap(la, lb);
		neg = true;
	} else if(la == lb) {
		for(int i = la; !neg && i; --i)
			if(a[i] < b[i])
				neg = true;
			else if(a[i] > b[i])
				break;
		if(neg) {
			for(int i = 1; i <= la; ++i)
				c[i] = a[i];
			for(int i = 1; i <= lb; ++i)
				a[i] = b[i];
			for(int i = lb + 1; i < N; ++i)
				a[i] = 0;
			for(int i = 1; i <= la; ++i) {
				b[i] = c[i];
				c[i] = 0;
			}
			for(int i = la + 1; i < N; ++i)
				b[i] = c[i] = 0;
			swap(la, lb);
		}
	}
	int lc = la;
	for(int i = 1; i <= lc; ++i) {
		c[i] += a[i] - b[i];
		if(c[i] < 0) {
			--c[i + 1];
			c[i] += 10;
		}
	}
	for(; lc > 1 && c[lc] == 0; --lc);
	if(neg)
		cout << '-';
	for(int i = lc; i; --i)
		cout << c[i];
	return 0;
}