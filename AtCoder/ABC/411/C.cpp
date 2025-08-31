#include <bits/stdc++.h>
using namespace std;

bitset<500003> b;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	long long ans = 0;
	for(int x; q--; cout.put('\n')) {
		cin >> x;
		if(!b[x]) {
			if(x == 1)
				++ans;
			else
				if(!b[x - 1])
					++ans;
			if(x < n && b[x + 1])
				--ans;
			b[x] = true;
		} else {
			if(x == 1)
				--ans;
			else
				if(!b[x - 1])
					--ans;
			if(x < n && b[x + 1])
				++ans;
			b[x] = false;
		}
		cout << ans;
	}
	cout.flush(); return 0;
}
