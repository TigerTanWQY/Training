#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	long long ans = 0;
	for(int t, tp; n--; ) {
		cin >> t >> tp;
		if(tp)
			ans += t;
		else
			ans += 20;
	}
	cout << ans << endl;
	return 0;
}
