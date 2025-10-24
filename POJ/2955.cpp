#include <bits/stdc++.h>
using namespace std;

const int N = 103;
char a[N];
int f[N][N];

int main() {
	cin.tie(NULL)->sync_with_stdio(false);
	for(int n; cin >> a && a[0] != 'e'; cout.put('\n')) {
		n = strlen(a);
		for(int len = 2; len <= n; ++len)
			for(int i = 0; i + len - 1 < n; ++i) {
				int j = i + len - 1;
				if((a[i] == '(' && a[j] == ')') || (a[i] == '[' && a[j] == ']'))
					f[i][j] = max(f[i][j], f[i+1][j-1] + 2);
				for(int k = i; k <= j; ++k)
					f[i][j] = max(f[i][j], f[i][k] + f[k+1][j]);
			}
		cout << f[0][n-1];
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				f[i][j] = 0;
	}
	cout.flush(); return 0;
}
