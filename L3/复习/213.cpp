#include <iostream>
#include <string>
using namespace std;

const int P = 1e9 + 7;
string s;

int dfs(const int& L, const int& R) {
	int x = 0, y = 0, z = 0;
	for(int i = L; i <= R; ++i)
		if(s[i] == '(')
			++x;
		else if(s[i] == ')')
			--x;
		else if(!x)
			if(s[i] == '*')
				y = i;
			else if(s[i] == '+' || s[i] == '-')
				z = i;
	if(z)
		if(s[z] == '+')
			return (dfs(L, z - 1) + dfs(z + 1, R)) % P;
		else
			return (dfs(L, z - 1) - dfs(z + 1, R) + P) % P;
	else if(y)
		return 1LL * dfs(L, y - 1) * dfs(y + 1, R) % P;
	else if(s[L] == '(' && s[R] == ')')
		return dfs(L + 1, R - 1);
	else
		return stoi(s.substr(L, R - L + 1));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s;
	s = '$' + s;
	cout << dfs(1, s.size() - 1);
	return 0;
}