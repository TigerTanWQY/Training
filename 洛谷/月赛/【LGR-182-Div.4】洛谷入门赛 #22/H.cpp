#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	int n = s.size(), ans = 0;
	for(int i = 0; i < n; ++i)
		for(int j = i; j < n; ++j) {
			unordered_map<char, int> cnt;
			for(int k = i; k <= j; ++k)
				++cnt[s[k]];
			bool flag = true;
			int maxn = 0;
			for(auto& pair : cnt)
				if(pair.second > maxn)
					maxn = pair.second;
			if(maxn > (j - i + 1) / 2)
				flag = false;
			if(flag)
				++ans;
		}
	cout << ans;
	return 0;
}