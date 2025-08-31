#include <iostream>
#include <string>
#include <set>
using namespace std;
using LL = long long;

set<LL> st;

void func() {
	for(int i = 1; i <= 9; ++i)
		for(int d = -9; d < 9; ++d) {
			string s;
			int x = i;
			for(int _ = 0; _ < 18; ++_) {
				s.push_back(x + '0');
				st.insert(stoll(s));
				x += d;
				if(x < 0 || 9 < x)
					break;
			}
		}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	LL x;
	cin >> x;
	func();
	cout << (*st.lower_bound(x));
	return 0;
}
