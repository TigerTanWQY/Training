#include <iostream>
#include <unordered_map>
#include <string>
#include <utility>
using namespace std;

const int N = 3000003;
unordered_map<char, int> trie[N];
int ans[N], cnt = 0;

void ist(const string& s) {
	int idx = 0;
	for(const auto& ch: s) {
		if(!trie[idx].count(ch))
			trie[idx][ch] = ++cnt;
		idx = trie[idx][ch];
		++ans[idx];
	}
}

pair<bool, int> fnd(const string& s) {
	int idx = 0;
	for(const auto& ch: s)
		if(!trie[idx].count(ch))
			return {false, 0};
		else
			idx = trie[idx][ch];
	return {true, idx};
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int _;
	cin >> _;
	for(int n, m; _--; ) {
		cin >> n >> m;
		for(string s; n--; ) {
			cin >> s;
			ist(s);
		}
		for(string s; m--; ) {
			cin >> s;
			auto p = fnd(s);
			if(p.first)
				cout << ans[p.second];
			else
				cout << '0';
			cout << '\n';
		}
		for(int i = 0; i <= cnt; ++i) {
			trie[i].clear();
			ans[i] = 0;
		}
		cnt = 0;
	}
	return 0;
}