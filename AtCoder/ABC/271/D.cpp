#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

pair<int, int> a[103];
bool dp[103][10003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, s;
	cin >> n >> s;
	for(int i = 1; i <= n; ++i)
		cin >> a[i].first >> a[i].second;
	dp[1][0] = true;
	for(int i = 1; i <= n; ++i)
		for(int j = 0; j <= s; ++j)
			if(dp[i][j]) {
				if(j + a[i].first <= s)
					dp[i + 1][j + a[i].first] = true;
				if(j + a[i].second <= s)
					dp[i + 1][j + a[i].second] = true;
			}
	if(dp[n + 1][s]) {
		cout << "Yes\n";
		string t(n + 1, '\0');
		for(int i = n; i; --i)
			if(s >= a[i].first && dp[i][s - a[i].first]) {
				t[i] = 'H';
				s -= a[i].first;
			}
			else {
				t[i] = 'T';
				s -= a[i].second;
			}
		t.erase(t.cbegin());
		cout << t;
	}
	else
		cout << "No";
	return 0;
}
