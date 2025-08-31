#include <bits/stdc++.h>
using namespace std;

constexpr const int P = 1e9 + 7;
const string t("$chokudai");
int f[100003][9];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	cin >> s;
	s = '$' + s;
	for(int i = 0; i < s.size(); ++i)
		for(int j = 0; j < t.size(); ++j)
			if(j == 0)
				f[i][j] = 1;
			else if(i == 0)
				f[i][j] = 0;
			else if(s[i] != t[j])
				f[i][j] = f[i - 1][j];
			else
				f[i][j] = (f[i - 1][j] + f[i - 1][j - 1]) % P;
	cout << f[s.size() - 1][t.size() - 1] % P << endl;
	return 0;
}
