#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

const int N = 1'350'003;
struct Node {
	unordered_map<char, int> nxt{};
	bool is_end{};
} trie[N];
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

bool fnd(const string& s) {
	int idx = 0;
	for(const auto& ch: s)
		if(!trie[idx].nxt.count(ch))
			return false;
		else
			idx = trie[idx].nxt[ch];
	return trie[idx].is_end;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n;
	for(string s; n--; ) {
		cin >> s;
		ist(s);
	}
	cin >> m;
	for(string s; m--; ) {
		cin >> s;
		cout << fnd(s) << '\n';
	}
	return 0;
}