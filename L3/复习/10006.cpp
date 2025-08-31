#include <iostream>
#include <cstring>
using namespace std;

constexpr const int N = 2e5 + 3;
char s[N], t[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> (s + 1) >> (t + 1);
	const int n = strlen(s + 1), m = strlen(t + 1);
	int i = 1, j = 1;
	for(; i <= n && j <= m; ++i)
		if(s[i] == t[j])
			++j;
		else if(i > 2 && s[i - 1] == t[j] && s[i - 2] == t[j]) {
			while(j <= m && s[i - 1] == t[j])
				++j;
			--i;
		} else {
			cout << "No" << endl;
			return 0;
		}
	if(j <= m)
		for(; j <= m; ++j)
			if(t[j] != t[j - 1]) {
				cout << "No" << endl;
				return 0;
			}
	cout << "Yes" << endl;
	return 0;
}