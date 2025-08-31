#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

const int N = 270003;
struct Node {
	unordered_map<char, int> nxt{};
	bool is_end{};
} trie[N];
unordered_set<string> stu;
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
	for(int i = 1; i <= n; ++i) {
		string s;
		cin >> s;
		stu.insert(s);
	}
	cin >> m;
	for(string s; m--; ) {
		cin >> s;
		if(!stu.count(s))
			cout << "WRONG";
		else if(fnd(s))
			cout << "REPEAT";
		else {
			cout << "OK";
			ist(s);
		}
		cout << '\n';
	}
	return 0;
}