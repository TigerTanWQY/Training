#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int L, R, W;
	cin >> L >> R >> W;
	W *= 1000;
	int nL = 0, nR = 0;
	for(int n = 1; n <= 1e6; ++n)
		if(L * n <= W && W <= R * n) {
			nL = n;
			break;
		}
	for(int n = 1e6; n; --n)
		if(L * n <= W && W <= R * n) {
			nR = n;
			break;
		}
	if(nL == 0 || nR == 0)
		cout << "UNSATISFIABLE";
	else
		cout << nL << ' ' << nR;
	cout << endl;
	return 0;
}
