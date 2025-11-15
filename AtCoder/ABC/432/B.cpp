#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	char s[7];
	cin >> s;
	int l = strlen(s);
	sort(s, s+l);
	int i = 0;
	for(; s[i] == '0'; ++i);
	for(; i; --i)
		swap(s[i], s[i-1]);
	cout << s << endl;
	return 0;
}
