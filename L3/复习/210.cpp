#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <stack>
using namespace std;
#define L first
#define R second

const int N = 1003;
pair<int, int> G[N];
vector<string> s{""};

void LRT(const int &u) {
	if(G[u].L)
		LRT(G[u].L);
	if(G[u].R)
		LRT(G[u].R);
	cout << s[u] << ' ';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	for(string t; cin >> t; )
		s.push_back(t);
	stack<int> c;
	for(int i = s.size() - 1; i; --i)
		if('0' <= s[i][0] && s[i][0] <= '9')
			c.push(i);
		else {
			G[i].L = c.top();
			c.pop();
			G[i].R = c.top();
			c.pop();
			c.push(i);
		}
	LRT(1);
	return 0;
}