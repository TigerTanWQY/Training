#include <bits/stdc++.h>
using namespace std;

constexpr const int P = 998244353;
int a[5003], q[5003];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> q[i];
		a[i] = i;
	}
	long long ans = 0;
	do {
		bool flg = true;
		for(int i = 1; flg && i <= n; ++i)
			if(q[i] == 0) {
				if(i > 1 && a[i] >= *min_element(a+1, a+i))
					flg = false;
			} else if(q[i] == 1) {
				if(i > 1 && a[i] <= *max_element(a+1, a+i))
					flg = false;
			} else if(q[i] == 2) {
				if(i < n && a[i] >= *min_element(a+i+1, a+n+1))
					flg = false;
			} else {
				if(i < n && a[i] <= *max_element(a+i+1, a+n+1))
					flg = false;
			}
		ans += flg;
		if(ans == P)
			ans = 0;
	} while(next_permutation(a+1, a+n+1));
	cout << ans << endl;
	return 0;
}
