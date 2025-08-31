#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, long long> mp;
int a[200003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n;
	for(int k = 1; k <= n; ++k)
		cin >> a[k];
	cin >> q;
	for(int op, k, w, tag = -1; q--; ) {
		cin >> op;
		if(op == 1) {
			cin >> w;
			tag = w;
			mp.clear();
		} else if(op == 2) {
			cin >> k >> w;
			if(mp.count(k))
				mp[k] += w;
			else if(~tag)
				mp[k] = tag + w;
			else
				mp[k] = a[k] + w;
		} else {
			cin >> k;
			if(mp.count(k))
				cout << mp[k];
			else if(tag != -1)
				cout << tag;
			else
				cout << a[k];
			cout << '\n';
		}
	}
	cout.flush();
	return 0;
}