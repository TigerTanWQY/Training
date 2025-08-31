#include <bits/stdc++.h>
using namespace std;

constexpr const int base[]{0, 2, 3, 5, 7, 11};
int a[7], b[7], c[7];

void f(int a[]) {
	memcpy(c, a, sizeof c);
	for(int i = 1; i <= a[0]; ++i)
		a[i] = c[a[0] - i + 1];
}

int main() {
	char ch;
	scanf("%d%c", &a[++a[0]], &ch);
	while(ch != '+')
		scanf("%d%c", &a[++a[0]], &ch);
	while(cin >> b[++b[0]] >> ch);
	f(a);
	f(b);
	for(int i = 1; i <= 5; ++i)
		c[i] = a[i] + b[i];
	for(int i = 1; i <= 5; ++i) {
		c[i + 1] += c[i] / base[i];
		c[i] %= base[i];
	}
	c[0] = max(a[0], b[0]) + (c[max(a[0], b[0]) + 1] > 0);
	cout << c[c[0]];
	for(int i = c[0] - 1; i; --i)
		cout << ',' << c[i];
	cout << endl;
	return 0;
}
