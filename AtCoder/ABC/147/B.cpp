#include <iostream>
#include <cstring>
using namespace std;

constexpr const int N = 103;
char s[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> (s + 1);
	int n = strlen(s + 1), ans = 0;
	for(int i = 1, j = n; i < j; ++i, --j)
		if(s[i] != s[j])
			++ans;
	cout << ans;
	cout.flush();
	return 0;
}