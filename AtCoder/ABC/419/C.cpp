#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int N = 2e5 + 3;
int n;
LL r[N], c[N];

bool check(LL x) {
	LL Lx = -1e18, Rx = 1e18, Ly = -1e18, Ry = 1e18;
	for(int i = 0; i < n; ++i) {
		Lx = max(Lx, r[i] - x);
		Rx = min(Rx, r[i] + x);
		Ly = max(Ly, c[i] - x);
		Ry = min(Ry, c[i] + x);
	}
	return (Lx <= Rx) && (Ly <= Ry);
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> r[i] >> c[i];
	LL L = 0, R = 2e9;
	while(L < R) {
		LL M = (L + R) >> 1;
		if(check(M))
			R = M;
		else
			L = M + 1;
	}
	cout << L << endl;
	return 0;
}
