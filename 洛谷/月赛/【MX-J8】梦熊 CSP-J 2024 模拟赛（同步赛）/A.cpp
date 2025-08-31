#include <iostream>
#include <algorithm>
using namespace std;
using LL = long long;

constexpr const int N = 1e5 + 3;
int n;
LL L[N], R[N], b[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> R[i] >> b[i];
		R[i] -= b[i];
		L[i] = -b[i];
	}
	LL cntL = L[1], cntR = R[1];
	for(int i = 2; i <= n; ++i) {
		const LL maxn = L[i], minn = R[i], L1 = -R[i], R1 = -L[i];
		if(cntL - min(cntL, maxn) + max(minn, cntR) - cntR > cntL - min(cntL, L1) + max(R1, cntR) - cntR) {
			cntL = min(cntL, maxn);
			cntR = max(minn, cntR);
		} else {
			cntL = min(cntL, L1);
			cntR = max(R1, cntR);
		}
	}
	cout << cntR - cntL << endl;
	return 0;
}