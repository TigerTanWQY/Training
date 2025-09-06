#include <iostream>
using namespace std;
using ULL = unsigned long long;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	ULL n;
	cin >> n;
	ULL ans = 0;
	for(int a = 1; ; ++a) {
		ULL aa = a <= 60? (1ULL << a): 0;
		if(aa == 0 || aa > n)
			break;
		ULL maxn = n / aa;
		if(maxn == 0)
			continue;
		ULL L = 1, R = maxn, res = 0;
		while(L <= R) {
			ULL M = L + (R - L) / 2;
			if(M <= maxn / M)
				if(M * M <= maxn) {
					res = M;
					L = M + 1;
				} else
					R = M - 1;
			else
				R = M - 1;
		}
		ans += (res + 1) / 2;
	}
	cout << ans << endl;
	return 0;
}
