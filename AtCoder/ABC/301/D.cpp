#include <iostream>
#include <string>
using namespace std;

int main() {
	long long n, cnt = 0;
	string s;
	cin >> s >> n;
	int m = s.size();
	s = '$' + s;
	for (int i = 1; i <= m; ++i) {
		cnt <<= 1;
		if (s[i] == '1')
			cnt++;
	}
	if (cnt > n) {
		cout << "-1";
		return 0;
	}
	for (int i = 1; i <= m; i++)
		if (s[i] == '?')
			if (cnt + (1LL << m - i) <= n)
				cnt += (1LL << m - i);
	cout << cnt;
	return 0;
}
