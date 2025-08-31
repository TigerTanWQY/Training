#include <iostream>
#include <vector>
#include <bitset>
#include <string>
using namespace std;

vector<char> G[300003];
bitset<128> vis;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	cin >> s;
	int m = 0;
	for(int i = 0; i < s.size(); ++i)
		if(s[i] == '(')
			++m;
		else if(s[i] == ')') {
			for(const char& ch: G[m])
				vis[ch] = false;
			G[m--].clear();
		} else {
			if(vis[s[i]]) {
				cout << "No" << endl;
				return 0;
			}
			G[m].push_back(s[i]);
			vis[s[i]] = true;
		}
	cout << "Yes" << endl;
	return 0;
}