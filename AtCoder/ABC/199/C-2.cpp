#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	string s;
	cin >> n >> s >> q;
	bool flip = false;
	for(int tp, x, y; q--; ) {
		cin >> tp >> x >> y;
		--x; --y;
		if(x > y)
			swap(x, y);
		if(tp == 1)
			if(flip)
				if(x < n && y < n)
					swap(s[x + n], s[y + n]);
				else if(x < n)
					swap(s[x + n], s[y - n]);
				else if(y < n)
					swap(s[x - n], s[y + n]);
				else
					swap(s[x - n], s[y - n]);
			else
				swap(s[x], s[y]);
		else
			flip = !flip;
	}
	if(flip) {
		s += s.substr(0, n);
		s.erase(0, n);
		flip = false;
	}
	cout << s << endl;
	return 0;
}
