#include <bits/stdc++.h>
using namespace std;

string s;
int L, R;

auto is_prime = [](int x) {
	if(x < 2)
		return false;
	for(int i = 2; i * i <= x; ++i)
		if(x % i == 0)
			return false;
	return true;
};

void dfs(int len) {
	if((s.size() << 1) >= len) {
		string t = s;
		char ch = s.back();
		if(len & 1)
			s.pop_back();
		reverse(begin(s), end(s));
		string tmp = t + s;
		if(!tmp.empty()) {
			int x = stoi(tmp);
			if(L <= x && x <= R && is_prime(x))
				cout << x << '\n';
		}
		reverse(begin(s), end(s));
		if(len & 1)
			s.push_back(ch);
		return;
	}
	for(char ch = (s.empty()? '1': '0'); ch <= '9'; ++ch) {
		s += ch;
		dfs(len);
		s.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> L >> R;
	for(int i = (int)log10(L); i <= (int)ceil(log10(R)); ++i) {
		dfs(i);
		s.clear();
	}
	cout.flush();
	return 0;
}
