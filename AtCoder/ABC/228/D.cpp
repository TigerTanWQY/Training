#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;
using LL = long long;

const int n = 1 << 20;
unordered_map<int, LL> mp;
map<int, int> itl;
LL a[n + 3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int _;
	cin >> _;
	itl[n] = 0;
	while(_--) {
		int t;
		LL x;
		cin >> t >> x;
		if(t == 1) {
			int i = x & (n - 1);
			auto it = itl.upper_bound(i);
			if(it == itl.end()) {
				i = 0;
				it = itl.begin();
			}
			if(it->second <= i) {
				mp[i] = x;
				int L1 = it->second, R1 = i, L2 = i + 1, R2 = it->first;
				itl.erase(it);
				if(L1 != R1)
					itl[R1] = L1;
				if(L2 != R2)
					itl[R2] = L2;
			} else {
				mp[it->second] = x;
				++(it->second);
				if(it->first == it->second)
					itl.erase(it);
			}
		} else {
			auto it = mp.find(x & (n - 1));
			if(it == mp.cend())
				cout << "-1\n";
			else
				cout << it->second << '\n';
		}
	}
	return 0;
}