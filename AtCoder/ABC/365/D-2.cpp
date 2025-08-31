#include <iostream>
using namespace std;

constexpr const int N = 200'005;
char s[N], t[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n >> (s + 1);
	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		if(s[i] == 'R')
			t[i] = 'P';
		else if(s[i] == 'P')
			t[i] = 'S';
		else if(s[i] == 'S')
			t[i] = 'R';
		if(t[i] == t[i - 1])
			t[i] = s[i];
		else
			++ans;
	}
	cout << ans;
	cout.flush();
	return 0;
}