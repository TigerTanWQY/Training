#include <iostream>
#include <cstring>
using namespace std;

char s[6];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s;
	int h, m;
	sscanf(s, "%d:%d", &h, &m);
	h = (h + 9) % 24;
	if(h < 10)
		cout << '0';
	cout << h << ':';
	if(m < 10)
		cout << '0';
	cout << m;
	return 0;
}