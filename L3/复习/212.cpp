#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <stack>
using namespace std;
#define L first
#define R second

pair<int, int> G[1003];
vector<string> s{""};

void TLR(const int &u) {
	cout << s[u] << ' ';
	if(G[u].L)
		TLR(G[u].L);
	if(G[u].R)
		TLR(G[u].R);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	for(string t; cin >> t; )
		s.push_back(t);
	stack<int> c;
	for(int i = 1; i < s.size(); ++i)
		if('0' <= s[i][0] && s[i][0] <= '9')
			c.push(i);
		else {
			G[i].R = c.top();
			c.pop();
			G[i].L = c.top();
			c.pop();
			c.push(i);
		}
	TLR(s.size() - 1);
	return 0;
}