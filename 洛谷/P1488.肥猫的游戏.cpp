#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 5e4 + 3;
bitset<N> b;
int a[N][3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 0; i < n - 2; ++i)
		for(int j = 0; j < 3; ++j)
			cin >> a[i][j];
	for(int j = 0; j < 3; ++j)
		b[a[0][j]] = true;
	int ans = 0;
	for(int i = 1; i < n - 2; ++i) {
		int res = 0;
		for(int j = 0; j < 3; ++j)
			res += b[a[i][j]];
		if(res == 2)
			++ans;
	}
	if(ans == 1)
		cout << "JMcat Win";
	else if(ans == 2)
		if(n & 1)
			cout << "PZ Win";
		else
			cout << "JMcat Win";
	else
		if(n & 1)
			cout << "PZ Win";
		else
			cout << "JMcat Win";
	cout << endl;
	return 0;
}
