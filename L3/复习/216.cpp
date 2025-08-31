#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int P = 10000;
vector<int> add, times;
string s;

int dfs(const int& L, const int& R) {
	int y = 0, z = 0;
	if(!times.empty())
		y = *lower_bound(times.cbegin(), times.cend(), L);
	if(!add.empty())
		z = *lower_bound(add.cbegin(), add.cend(), L);
	if(L <= z && z <= R)
		return (dfs(L, z - 1) + dfs(z + 1, R)) % P;
	else if(L <= y && y <= R)
		return dfs(L, y - 1) * dfs(y + 1, R) % P;
	else
		return stoi(s.substr(L, R - L + 1)) % P;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s;
	s = '$' + s;
	for(int i = 1; i < s.size(); ++i)
		if(s[i] == '+')
			add.push_back(i);
		else if(s[i] == '*')
			times.push_back(i);
	cout << dfs(1, s.size() - 1);
	return 0;
}