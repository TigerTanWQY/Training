#include <iostream>
#include <cstring>
using namespace std;

char s[100'003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> (s + 1);
	int n = strlen(s + 1), top = 0, ans = 0;
	for(int i = 1; i <= n; ++i)
		if(s[i] == '(')
			++top;
		else if(top > 0)
			--top;
		else {
			++ans;
			++top;
		}
	ans += top / 2;
	cout << ans << endl;
	return 0;
}