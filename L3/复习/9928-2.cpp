#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

constexpr const int N = 1e6 + 3;
pair<int, int> T[N];
char s[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> (s + 1);
	const int n = strlen(s + 1);
	stack<int> stk, op;
	int x = 0;
	for(int i = 1; i <= n; ++i)
		if('0' <= s[i] && s[i] <= '1')
			stk.push(s[i] - '0');
		else if(s[i] == '(')
			++x;
		else if(s[i] == ')')
			--x;
		else {
			char j = op.top();
			op.pop();
			if(s[j] == '&')
				;
			else
				;
		}
	cout.flush();
	return 0;
}