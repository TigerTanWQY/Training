#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	__gnu_pbds::gp_hash_table<string, bool> mp;
	for(string s; n--; ) {
		cin >> s;
		mp[s] = true;
	}
	cout << mp.size() << endl;
	return 0;
}
