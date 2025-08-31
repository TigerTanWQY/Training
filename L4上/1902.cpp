#include <iostream>
#include <algorithm>
using namespace std;

const int N = 131075;
char s[N];
int n;

int getans(const int& L, const int& R, const char& ch) {
	if(L == R)
		return s[L] != ch;
	int tot1 = 0, tot2 = 0, M = (L + R) / 2;
	for(int i = L; i <= M; ++i)
		if(s[i] != ch)
			++tot1;
	for(int i = M + 1; i <= R; ++i)
		if(s[i] != ch)
			++tot2;
	tot1 += getans(M + 1, R, ch + 1);
	tot2 += getans(L, M, ch + 1);
	return min(tot1, tot2);
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int _T;
	cin >> _T;
	while(_T--) {
		cin >> n >> (s + 1);
		cout << getans(1, n, 'a') << '\n';
	}
	return 0;
}