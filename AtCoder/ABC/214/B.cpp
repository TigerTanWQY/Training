#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int s, t;
	cin >> s >> t;
	int ans = 0;
	for(int a = 0; a <= s; ++a)
		for(int b = 0; b <= s; ++b)
			for(int c = 0; c <= s; ++c)
				if(a + b + c <= s && a * b * c <= t)
					++ans;
	cout << ans;
	return 0;
}