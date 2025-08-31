#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int cnt[14];
	for(int i = 0, x; i < 4; ++i) {
		cin >> x;
		++cnt[x];
	}
	for(int i = 1; i <= 13; ++i)
		for(int j = 1; j <= 13; ++j)
			if(i != j && ((cnt[i] == 3 && cnt[j] == 1) ||
				(cnt[i] == 2 && cnt[j] == 2))) {
				cout << "Yes" << endl;
				return 0;
			}
	cout << "No" << endl;
	return 0;
}
