#include <iostream>
#include <string>
using namespace std;

string s;

void dfs(const int& L, const int& R) {
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
		dfs(L, z - 1);
		dfs(z + 1, R);
		cout << s[z] << ' ';
		return;
	} else if(y) {
		dfs(L, y - 1);
		dfs(y + 1, R);
		cout << s[y] << ' ';
		return;
	} else if(s[L] == '(' && s[R] == ')') {
		dfs(L + 1, R - 1);
		return;
	} else {
		for(int i = L; i <= R; ++i)
			cout << s[i];
		cout << ' ';
		return;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s;
	s = '$' + s;
	dfs(1, s.size() - 1);
	return 0;
}