#include <iostream>
#include <cstring>
using namespace std;

char s[1003];

void dfs(const int &L, const int &R) {
	int x = 0, y = 0, z = 0;
	for(int i = L; i <= R; ++i)
		if(s[i] == '(')
			++x;
		else if(s[i] == ')')
			--x;
		else if(!x)
			if(s[i] == '*' || s[i] == '/')
				y = i;
			else if(s[i] == '+' || s[i] == '-')
				z = i;
	if(z) {
		cout << s[z] << ' ';
		dfs(L, z - 1);
		dfs(z + 1, R);
		return;
	} if(y) {
		cout << s[y] << ' ';
		dfs(L, y - 1);
		dfs(y + 1, R);
		return;
	} else if(s[L] == '(' && s[R] == ')')
		dfs(L + 1, R - 1);
	else {
		for(int i = L; i <= R; ++i)
			cout << s[i];
		cout << ' ';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> (s + 1);
	int n = strlen(s + 1);
	dfs(1, n);
	return 0;
}