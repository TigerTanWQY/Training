#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	string s;
	cin >> n >> q >> s;
	int cnt = 0;
	for(int op, x; q--; ) {
		cin >> op >> x;
		if(op == 1) {
			cnt -= x;
			cnt += n;
			cnt %= n;
		} else {
			cout.put(s[(x + cnt - 1) % n]);
			cout.put('\n');
		}
	}
	cout.flush();
	return 0;
}