#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 103;
char s[N];
int f[N][N], g[N][N];

bool chk(char a, char b)
{ return (a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}'); }

void Print(int L, int R) {
	if(L > R)
		return;
	else if(L == R) {
		if(s[L-1] == '[' || s[L-1] == ']')
			cout << "[]";
		else if(s[L-1] == '(' || s[L-1] == ')')
			cout << "()";
		else
			cout << "{}";
		return;
	} else if(!g[L][R]) {
		cout.put(s[L-1]);
		Print(L+1, R-1);
		cout.put(s[R-1]);
	} else {
		Print(L, g[L][R]);
		Print(g[L][R]+1, R);
	}
}

int main() {
	cin.tie(NULL)->sync_with_stdio(false);
	for(; cin >> s; cout.put('\n')) {
		int n = strlen(s);
		memset(f, 0, sizeof f);
		for(int i = 1; i <= n; ++i)
			f[i][i] = 1;
		for(int len = 2; len <= n; ++len)
			for(int i = 1; i+len-1 <= n; ++i) {
				int j = len+i-1;
				f[i][j] = 1e9;
				if(chk(s[i-1], s[j-1])) {
					f[i][j] = f[i+1][j-1];
					g[i][j] = 0;
				}
				for(int k = i; k < j; ++k)
					if(f[i][j] > f[i][k] + f[k+1][j]) {
						f[i][j] = f[i][k] + f[k+1][j];
						g[i][j] = k;
					}
			}
		Print(1, n);
	}
	cout.flush(); return 0;
}
