#include <iostream>
#include <string>
using namespace std;
using LL = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	LL n;
	int k;
	string s;
	cin >> n >> k >> s;
	LL cnth = 0, cntm = 0, ansh = 0, ansm = 0;
	for(LL i = 0; i < n; ++i) {
		if(s[i % k] == 'A')
			++cntm;
		else
			++cnth;
		if(cntm >= 11 && cntm - cnth >= 2) {
			++ansm;
			cntm = cnth = 0;
		} else if(cnth >= 11 && cnth - cntm >= 2) {
			++ansh;
			cntm = cnth = 0;
		}
	}
	cout << ansm << ':' << ansh;
	cout << endl;
	return 0;
}