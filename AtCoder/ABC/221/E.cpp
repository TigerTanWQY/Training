#include <iostream>
using namespace std;

const int P = 998244353;
const int N = 300003;
int a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, ans = 0;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int L = 1; L < n; ++L) {
		int aR = 0;
		for(int R = L + 1; R <= n; ++R)
			if(a[L] <= a[R])
				aR = R;
		if(aR)
//			ans = (ans + (aR - L + 1) * (aR - L) / 2) % P;
			ans = (ans + (1 << aR - L + 1));
	}
	cout << ans;
	return 0;
}