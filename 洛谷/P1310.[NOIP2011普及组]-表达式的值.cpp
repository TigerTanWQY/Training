#include <iostream>
using namespace std;

constexpr const int P = 10007, N = 1e5 + 3;
char s[N], stk[N], ans[N*2];
int u[N], v[N], top = 0, k = 0;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n >> s;
	ans[++k] = '.';
	for(int i = 0; s[i]; ++i) {
		if(s[i] == '(' || s[i] == '*')
			stk[++top] = s[i];
		else if(s[i] == '+') {
			while(stk[top] == '*')
				ans[++k] = stk[top--];
			stk[++top] = s[i];
		} else if(s[i] == ')') {
			while(stk[top] != '(')
				ans[++k] = stk[top--];
			--top;
		}
		if(s[i] != '(' && s[i] != ')')
			ans[++k] = '.';
	}
	while(top)
		ans[++k] = stk[top--];
	for(int i = 1; i <= k; ++i)
		if(ans[i] == '.') {
			u[++top] = 1;
			v[top] = 1;
		} else if(ans[i] == '*') {
			--top;
			u[top] = (u[top+1]*v[top] + u[top]*v[top+1] + u[top]*u[top+1]) % P;
			v[top] = v[top] * v[top+1] % P;
		} else if(ans[i] == '+') {
			--top;
			v[top] = (u[top+1]*v[top] + u[top]*v[top+1] + v[top]*v[top+1]) % P;
			u[top] = u[top] * u[top+1] % P;
		}
	cout << u[1] << endl;
	return 0;
}
