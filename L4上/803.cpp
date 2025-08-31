#include <iostream>
#include <string>
#include <map>
using namespace std;

const int N = 1'350'003;
struct Node {
	map<char, int> nxt{};
	bool is_end{};
} trie[N];
string ans;
int cnt = 0;

void ist(const string& s) {
	int idx = 0;
	for(const auto& ch: s) {
		if(!trie[idx].nxt.count(ch))
			trie[idx].nxt[ch] = ++cnt;
		idx = trie[idx].nxt[ch];
	}
	trie[idx].is_end = true;
}

void dfs(const int& u, const int& d) {
	if(trie[u].is_end)
		cout << ans << '\n';
	for(const auto& p: trie[u].nxt) {
		ans += p.first;
		dfs(p.second, d + 1);
		ans.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(string s; n--; ) {
		cin >> s;
		ist(s);
	}
	dfs(0, 0);
	return 0;
}